#include "SwitchTools.h"

#include <switch.h>

namespace OpenXcom
{

namespace Switch
{

/*
    The dirty thing is every SDL keyboard event
    makes InteractiveSurface write to our TextEdit,
    so to avoid this without modifying every part of
    code where we use TextEdit, i applied keyboard
    press for updating InteractiveSurface
*/
void callSwitchKeyboardDirty(TextEdit *txtEdit)
{
    Result rc = 0;
	SwkbdConfig kbd;
	char tmpoutstr[16] = {0};

	rc = swkbdCreate(&kbd, 0);
	if (R_SUCCEEDED(rc))
	{
		swkbdConfigMakePresetDefault(&kbd);
        swkbdConfigSetInitialText(&kbd, txtEdit->getText().c_str());
		
        rc = swkbdShow(&kbd, tmpoutstr, sizeof(tmpoutstr));

		if (R_SUCCEEDED(rc))
		{
			txtEdit->setText(tmpoutstr);
			swkbdClose(&kbd);
		}
	}
    
    SDL_Event event;

    event.type = SDL_KEYDOWN;
    event.key.keysym.sym = SDLK_RIGHT;
    SDL_PushEvent(&event);
}

int getSwitchScreenWidth()
{
    switch (appletGetOperationMode())
	{
		default:
		case AppletOperationMode_Handheld:
			return 1280;
			break;
		case AppletOperationMode_Console:
			return 1920;
			break;
	}
}

int getSwitchScreenHeight()
{
    switch (appletGetOperationMode())
	{
		default:
		case AppletOperationMode_Handheld:
			return 720;
			break;
		case AppletOperationMode_Console:
			return 1080;
			break;
	}
}

} /*end of Switch namespace*/

} /*end of OpenXcom namespace*/
