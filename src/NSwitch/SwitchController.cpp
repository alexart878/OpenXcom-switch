#include "SwitchController.h"

#include "../Engine/Options.h"
#include "../Engine/Screen.h"
#include "../Engine/Logger.h"
#include <switch.h>

namespace OpenXcom
{

SwitchController::SwitchController(Game *game, Screen *screen) : _game(game), _screen(screen)
{
    initController();
}

SwitchController::~SwitchController()
{
    _game = nullptr;
    _screen = nullptr;
    
    if (controller)
	{
		SDL_GameControllerClose(controller);
	}
}

void SwitchController::initController()
{
    if (SDL_InitSubSystem(SDL_INIT_GAMECONTROLLER) == -1)
	{
		Log(LOG_ERROR) << "Switch controller init fail.";
	}
	else
	{
		if (SDL_NumJoysticks() > 0)
		{
			if (SDL_IsGameController(0))
			{
				controller = SDL_GameControllerOpen(0);
				if (!controller)
					Log(LOG_ERROR) << SDL_GetError();
			}
		}
	}
}

void SwitchController::toggleCtrlMode()
{
    if (!ctrlMode)
    {
        ctrlMode = true;
        SDL_SetModState(KMOD_LCTRL);
    }
    else
    {
        ctrlMode = false;
        SDL_SetModState(KMOD_NONE);
    }
}

void SwitchController::leftTriggerClick()
{
    SDL_Event ev;
    ev.type = SDL_KEYDOWN;
    ev.key.state = SDL_PRESSED;
    ev.key.keysym.sym = SDLK_F5;

    _game->ActivateAction(ev);
}

void SwitchController::rightTriggerClick()
{
    SDL_Event ev;
    ev.type = SDL_KEYDOWN;
    ev.key.state = SDL_PRESSED;
    ev.key.keysym.sym = SDLK_F9;

    _game->ActivateAction(ev);
}

void SwitchController::setPointerPosXY(int32_t posX, int32_t posY)
{
    pointerPosX = posX;
    pointerPosY = posY;
}

uint8_t SwitchController::getMouseState(int *x, int *y)
{
    *x = static_cast<int>(pointerPosX);
    *y = static_cast<int>(pointerPosY);

    return SDL_GetMouseState(0, 0);
}

void SwitchController::processTouchInput()
{
	SDL_Event ev;
	
	static int fingerCount = -1;
	static bool touchActive = false;
	static bool clickTriggered = false;
	
	static int initialTouchX = 0;
	static int initialTouchY = 0;
	static uint64_t touchStartTime = 0;

	const static int clickThresholdDistancePx = 15;
	const static int clickThresholdTimeMs = 300;

	HidTouchScreenState state = {0};

	if (hidGetTouchScreenStates(&state, 1))
	{
		int touchX = 0;
		int touchY = 0;

		if (state.count > 0) // one finger gesture
		{
			if (!touchActive)
			{
				touchActive = true;
				clickTriggered = false;
				initialTouchX = state.touches[0].x;
                initialTouchY = state.touches[0].y;
                touchStartTime = armGetSystemTick();
				fingerCount = state.count;
			}

			touchX = state.touches[0].x;
			touchY = state.touches[0].y;

			pointerPosX = touchX;
			pointerPosY = touchY;

			ev.type = SDL_MOUSEMOTION;
			ev.motion.x = touchX;
			ev.motion.y = touchY;

			_game->ActivateAction(ev);
		}
		else if (touchActive) // release fingers gesture
		{
			touchActive = false;

			int releaseX = pointerPosX;
			int releaseY = pointerPosY;

			int dX = releaseX - initialTouchX;
			int dY = releaseY - initialTouchY;
			int dSquared = dX * dX + dY * dY;

			uint64_t elapsedTime = (armGetSystemTick() - touchStartTime) / 19200; // to ms

			if (!clickTriggered && dSquared <= clickThresholdDistancePx * clickThresholdDistancePx && elapsedTime <= clickThresholdTimeMs)
			{
				// treating as click
				switch(fingerCount)
				{
					case 1:
						ev.button.button = SDL_BUTTON_LEFT;
						break;
					case 2:
						ev.button.button = SDL_BUTTON_RIGHT;
						break;
					default:
						break;
				}
				
				ev.type = SDL_MOUSEBUTTONDOWN;
				ev.button.x = releaseX;
				ev.button.y = releaseY;

				_game->ActivateAction(ev);

				ev.type = SDL_MOUSEBUTTONUP;
				ev.button.x = releaseX;
				ev.button.y = releaseY;

				_game->ActivateAction(ev);

				clickTriggered = true;
			}
			else // treating as scroll
			{
				
			}
		}
	}
}

void SwitchController::processControllerAxisMotion()
{
	const uint32_t currentTime = SDL_GetTicks();
	const uint32_t deltaTime = currentTime - lastControllerTime;
	lastControllerTime = currentTime;

	if (controllerLeftXAxis != 0 || controllerLeftYAxis != 0)
	{
		const int16_t xSign = (controllerLeftXAxis > 0) - (controllerLeftXAxis < 0);
		const int16_t ySign = (controllerLeftYAxis > 0) - (controllerLeftYAxis < 0);

		controllerPointerSpeed = Options::controllerPointerSpeed / CONTROLLER_SPEED_MOD * (static_cast<float>(Options::displayHeight) / Screen::ORIGINAL_HEIGHT);
		pointerPosX += pow(std::abs(controllerLeftXAxis), CONTROLLER_AXIS_SPEEDUP) * xSign * deltaTime * controllerPointerSpeed;
		pointerPosY += pow(std::abs(controllerLeftYAxis), CONTROLLER_AXIS_SPEEDUP) * ySign * deltaTime * controllerPointerSpeed;
	
		if (pointerPosX < _screen->getCursorLeftBlackBand())
			pointerPosX = _screen->getCursorLeftBlackBand();
		else if (pointerPosX >= _screen->getWidth() - _screen->getCursorLeftBlackBand())
			pointerPosX = _screen->getWidth() - _screen->getCursorLeftBlackBand() - 1;

		if (pointerPosY < 0)
			pointerPosY = 0;
		else if (pointerPosY >= _screen->getHeight())
			pointerPosY = _screen->getHeight() - 1;

		SDL_Event ev;
		ev.type = SDL_MOUSEMOTION;
		ev.motion.x = pointerPosX;
		ev.motion.y = pointerPosY;
		
        _game->ActivateAction(ev);
	}

	// map scroll
	if (controllerRightXAxis > CONTROLLER_R_DEADZONE)
	{
		if (!rightScrollActive)
		{
			rightScrollActive = true;
			SDL_Event ev;
			ev.type = SDL_KEYDOWN;
			ev.key.state = SDL_PRESSED;
			ev.key.keysym.mod = KMOD_NONE;
			ev.key.keysym.sym = SDLK_RIGHT;
			
            _game->ActivateAction(ev);
		}
	}
	else if (rightScrollActive)
	{
		rightScrollActive = false;
		SDL_Event ev;
		ev.type = SDL_KEYUP;
		ev.key.state = SDL_RELEASED;
		ev.key.keysym.mod = KMOD_NONE;
		ev.key.keysym.sym = SDLK_RIGHT;
		
        _game->ActivateAction(ev);
	}

	if (controllerRightXAxis < -CONTROLLER_R_DEADZONE)
	{
		if (!leftScrollActive)
		{
			leftScrollActive = true;
			SDL_Event ev;
			ev.type = SDL_KEYDOWN;
			ev.key.state = SDL_PRESSED;
			ev.key.keysym.mod = KMOD_NONE;
			ev.key.keysym.sym = SDLK_LEFT;
			
            _game->ActivateAction(ev);
		}
	}
	else if (leftScrollActive)
	{
		leftScrollActive = false;
		SDL_Event ev;
		ev.type = SDL_KEYUP;
		ev.key.state = SDL_RELEASED;
		ev.key.keysym.mod = KMOD_NONE;
		ev.key.keysym.sym = SDLK_LEFT;
		
        _game->ActivateAction(ev);
	}

	if (controllerRightYAxis > CONTROLLER_R_DEADZONE)
	{
		if (!upScrollActive)
		{
			upScrollActive = true;
			SDL_Event ev;
			ev.type = SDL_KEYDOWN;
			ev.key.state = SDL_PRESSED;
			ev.key.keysym.mod = KMOD_NONE;
			ev.key.keysym.sym = SDLK_DOWN;
			
            _game->ActivateAction(ev);
		}
	}
	else if (upScrollActive)
	{
		upScrollActive = false;
		SDL_Event ev;
		ev.type = SDL_KEYUP;
		ev.key.state = SDL_RELEASED;
		ev.key.keysym.mod = KMOD_NONE;
		ev.key.keysym.sym = SDLK_DOWN;
		
        _game->ActivateAction(ev);
	}

	if (controllerRightYAxis < -CONTROLLER_R_DEADZONE)
	{
		if (!downScrollActive)
		{
			downScrollActive = true;
			SDL_Event ev;
			ev.type = SDL_KEYDOWN;
			ev.key.state = SDL_PRESSED;
			ev.key.keysym.mod = KMOD_NONE;
			ev.key.keysym.sym = SDLK_UP;
			
            _game->ActivateAction(ev);
		}
	}
	else if (downScrollActive)
	{
		downScrollActive = false;
		SDL_Event ev;
		ev.type = SDL_KEYUP;
		ev.key.state = SDL_RELEASED;
		ev.key.keysym.mod = KMOD_NONE;
		ev.key.keysym.sym = SDLK_UP;
		
        _game->ActivateAction(ev);
	}
}

void SwitchController::handleControllerAxisEvent(const SDL_ControllerAxisEvent &motion)
{
	if (motion.axis == SDL_CONTROLLER_AXIS_LEFTX)
	{
		if (std::abs(motion.value) > CONTROLLER_L_DEADZONE)
			controllerLeftXAxis = motion.value;
		else
			controllerLeftXAxis = 0;
	}
	else if (motion.axis == SDL_CONTROLLER_AXIS_LEFTY)
	{
		if (std::abs(motion.value) > CONTROLLER_L_DEADZONE)
			controllerLeftYAxis = motion.value;
		else
			controllerLeftYAxis = 0;
	}
	else if (motion.axis == SDL_CONTROLLER_AXIS_RIGHTX)
	{
		if (std::abs(motion.value) > CONTROLLER_R_DEADZONE)
			controllerRightXAxis = motion.value;
		else
			controllerRightXAxis = 0;
	}
	else if (motion.axis == SDL_CONTROLLER_AXIS_RIGHTY)
	{
		if (std::abs(motion.value) > CONTROLLER_R_DEADZONE)
			controllerRightYAxis = motion.value;
		else
			controllerRightYAxis = 0;
	}
    else if (motion.axis == SDL_CONTROLLER_AXIS_TRIGGERLEFT)
    {
        if (std::abs(motion.value) > 0)
        {
            leftTriggerClick();
        }
    }
    else if (motion.axis == SDL_CONTROLLER_AXIS_TRIGGERRIGHT)
    {
        if (std::abs(motion.value) > 0)
        {
            rightTriggerClick();
        }
    }
}

void SwitchController::handleControllerButtonEvent(const SDL_ControllerButtonEvent &button)
{
    bool activateAction = true;
	SDL_Event ev;

	if (button.button == SDL_CONTROLLER_BUTTON_A || button.button == SDL_CONTROLLER_BUTTON_B)
	{
		if (button.state == SDL_PRESSED)
			ev.type = SDL_MOUSEBUTTONDOWN;
		else if (button.state == SDL_RELEASED)
			ev.type = SDL_MOUSEBUTTONUP;

		ev.button.state = button.state;
		ev.button.x = pointerPosX;
		ev.button.y = pointerPosY;
        // for switch gamepad layout it's common to use revert A/B buttons
		ev.button.button = button.button == SDL_CONTROLLER_BUTTON_A ? SDL_BUTTON_RIGHT : SDL_BUTTON_LEFT;
	}
	else 
	{
		if (button.state == SDL_PRESSED)
			ev.type = SDL_KEYDOWN;
		else if (button.state == SDL_RELEASED)
			ev.type = SDL_KEYUP;

		ev.key.state = button.state;
		ev.key.keysym.mod = KMOD_NONE;

		switch(button.button)
		{
			case SDL_CONTROLLER_BUTTON_START:
				ev.key.keysym.sym = SDLK_BACKSPACE;
				break;
			case SDL_CONTROLLER_BUTTON_BACK:
				ev.key.keysym.sym = SDLK_ESCAPE;
				break;
			case SDL_CONTROLLER_BUTTON_DPAD_UP:
				ev.key.keysym.sym = SDLK_PAGEUP;
				break;
			case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
				ev.key.keysym.sym = SDLK_PAGEDOWN;
				break;
            case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
				ev.key.keysym.sym = SDLK_q;
				break;
			case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
				ev.key.keysym.sym = SDLK_e;
				break;
			case SDL_CONTROLLER_BUTTON_LEFTSHOULDER:
				ev.key.keysym.sym = SDLK_LSHIFT;
				break;
			case SDL_CONTROLLER_BUTTON_RIGHTSHOULDER:
				ev.key.keysym.sym = SDLK_TAB;
				break;
            case SDL_CONTROLLER_BUTTON_LEFTSTICK:
                toggleCtrlMode();
                break;
            case SDL_CONTROLLER_BUTTON_RIGHTSTICK:
                ev.key.keysym.sym = SDLK_HOME;
                break;
			case SDL_CONTROLLER_BUTTON_Y:
				ev.key.keysym.sym = SDLK_i;
				break;
			case SDL_CONTROLLER_BUTTON_X:
				ev.key.keysym.sym = SDLK_m;
				break;
			default:
				activateAction = false;
				break;
		}
	}

	if (activateAction)
	{
		_game->ActivateAction(ev);
	}
}

}
