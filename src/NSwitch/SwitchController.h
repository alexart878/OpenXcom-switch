#pragma once

#include <SDL.h>
#include <stdint.h>
#include "../Engine/Game.h"

namespace OpenXcom
{

class Game;
class Screen;

class SwitchController
{
    void initController();
    void leftTriggerClick();
    void rightTriggerClick();
    void toggleCtrlMode();

    int32_t pointerPosX = 0;
    int32_t pointerPosY = 0;

    SDL_GameController *controller = nullptr;

    int16_t controllerLeftXAxis = 0;
    int16_t controllerLeftYAxis = 0;
    int16_t controllerRightXAxis = 0;
    int16_t controllerRightYAxis = 0;

    uint32_t lastControllerTime = 0;

    bool leftScrollActive = false;
	bool rightScrollActive = false;
	bool upScrollActive = false;
	bool downScrollActive = false;

	bool ctrlMode = false;

    // used to convert user-friendly pointer speed values into more useable ones
	const double CONTROLLER_SPEED_MOD = 2000000.0;
	double controllerPointerSpeed = 10.0 / CONTROLLER_SPEED_MOD;

    // bigger value correndsponds to faster pointer movement speed with bigger stick axis values
	const double CONTROLLER_AXIS_SPEEDUP = 1.03;

    enum
	{
		CONTROLLER_L_DEADZONE = 3000,
		CONTROLLER_R_DEADZONE = 25000
	};

    // pointer to game instance for proper events push
    Game *_game;
    // pointer to screen for pointer position handling
    Screen *_screen;

public:

    SwitchController(Game *game, Screen *screen);
    ~SwitchController();

    void setPointerPosXY(int32_t posX, int32_t posY);

    uint8_t getMouseState(int *x, int *y);

    void processTouchInput();
    void processControllerAxisMotion();
    void handleControllerAxisEvent(const SDL_ControllerAxisEvent &motion);
    void handleControllerButtonEvent(const SDL_ControllerButtonEvent &button);
};

}
