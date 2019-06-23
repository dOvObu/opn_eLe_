#include "opnInput.h"
#include "opnFreeCamera.h"
#include "opnProfileCamera.h"

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


void opnInput::setCameras (opnCamera *freeCam_, opnCamera *profileCam_)
{
	freeCam = freeCam_;
	profileCam = profileCam_;
}


void defaultSettings (opnWindow& win)
{
	static opnFreeCamera cam;
	static opnProfileCamera cam2;

	opnInput::setCameras (&cam, &cam2);
	currentCamera = &cam;
	win.alphaOn ();
	win.setDefaultCallbacks ();
	win.setCursorVisible (false);
}

