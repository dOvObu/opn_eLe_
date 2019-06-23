#ifndef OPNINPUT_H
#define OPNINPUT_H

#include "opnWindow.h"

struct opnInput
{
	static void process (opnWindow& win);
	static void setCameras (opnCamera *freeCam, opnCamera *profileCam);

private:
	static bool opn3Dmode;
	static opnCamera *freeCam, *profileCam;
	static void opn3DmodeFunc (opnWindow& win, float&& speed)
	{
		auto& curr = currentCamera;
		auto& n = glm::normalize<3, float, glm::packed_highp>;

		if (win.pressed (GLFW_KEY_W)) curr->pos += speed * curr->front;
		if (win.pressed (GLFW_KEY_S)) curr->pos -= speed * curr->front;
		if (win.pressed (GLFW_KEY_E)) curr->pos += speed * curr->up ();
		if (win.pressed (GLFW_KEY_Q)) curr->pos -= speed * curr->up ();
		if (win.pressed (GLFW_KEY_A)) curr->pos -= n (glm::cross (curr->front, curr->up ())) * speed;
		if (win.pressed (GLFW_KEY_D)) curr->pos += n (glm::cross (curr->front, curr->up ())) * speed;
		if (win.pressed (GLFW_KEY_TAB)) {
			opn3Dmode = false;
			auto z = profileCam->pos.z;
			*(curr = profileCam) = *freeCam;
			profileCam->pos.z = z;
		}
	}

	static void opn3DprofileFunc (opnWindow& win, float&& speed)
	{
		auto& curr = currentCamera;
		if (win.pressed (GLFW_KEY_W)) curr->pos += speed * curr->up();
		if (win.pressed (GLFW_KEY_S)) curr->pos -= speed * curr->up();
		if (win.pressed (GLFW_KEY_A)) curr->pos -= glm::vec3 (speed, 0, 0);
		if (win.pressed (GLFW_KEY_D)) curr->pos += glm::vec3 (speed, 0, 0);
		if (win.pressed (GLFW_KEY_V))
		{
			opn3Dmode = true;
			curr = freeCam;
		}
	}
};

void defaultSettings (opnWindow& win);

#endif
