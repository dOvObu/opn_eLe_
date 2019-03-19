#include "opnInput.h"

bool opnInput::opn3Dmode = true;
opnCamera* opnInput::freeCam = nullptr;
opnCamera* opnInput::profileCam = nullptr;


void opnInput::process (opnWindow& win)
{
	if (win.pressed (GLFW_KEY_ESCAPE))
	{
		win.close ();
		return;
	}

	float speed = 2.5f * currentCamera->dt;

	if (opn3Dmode) { opn3DmodeFunc (win, std::move (speed)); }
	else { opn3DprofileFunc (win, std::move (speed)); }
}




void defaultSettings (opnWindow& win, opnCamera* free, opnCamera* profile)
{
	opnInput::freeCam = free;
	opnInput::profileCam = profile;
	currentCamera = opnInput::freeCam;
	win.alphaOn ();
	win.setDefaultCallbacks ();
	win.setCursorVisible (false);
}

