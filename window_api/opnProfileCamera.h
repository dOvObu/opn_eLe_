#ifndef OPNPROFILECAMERA_H
#define OPNPROFILECAMERA_H


#include "opnCamera.h"
//#include <Windows.h>

class opnProfileCamera : public opnCamera
{
public:
	opnProfileCamera(){}
	~opnProfileCamera(){}
	void mouse_callback (GLFWwindow* window, double&& xpos, double&& ypos)
	{
		//*
		glm::ivec2 pos, size, mpos;
		glfwGetWindowSize (window, &size.x, &size.y);
		glfwGetWindowPos (window, &pos.x, &pos.y);
		mpos = pos + size / 2;

		float xoffset = xpos + pos.x - mpos.x;
		float yoffset = mpos.y - ypos - pos.y; // sys of coord of opngl и os 
		SetCursorPos (mpos.x, mpos.y);

		float sensitivity = 0.1f;
		xoffset *= sensitivity;
		yoffset *= sensitivity;

		currentCamera->yaw += xoffset;
		currentCamera->pitch += yoffset;

		// убедились, что при наклоне превосходящем границу, экран не перевернётся
		if (currentCamera->pitch > 89.0f) currentCamera->pitch = 89.0f;
		if (currentCamera->pitch < -89.0f) currentCamera->pitch = -89.0f;

		glm::vec3 front;
		front.x = cos (glm::radians (currentCamera->yaw)) * cos (glm::radians (currentCamera->pitch));
		front.y = sin (glm::radians (currentCamera->pitch));
		front.z = sin (glm::radians (currentCamera->yaw)) * cos (glm::radians (currentCamera->pitch));
		currentCamera->front = glm::normalize (front);
		//*/
	}

	void scroll_callback (GLFWwindow* window, double&& xoffset, double&& yoffset)
	{
		if (currentCamera->fov >= 1.0f && currentCamera->fov <= 45.0f) currentCamera->fov -= yoffset;
		if (currentCamera->fov <= 1.0f) currentCamera->fov = 1.0f;
		if (currentCamera->fov >= 45.0f) currentCamera->fov = 45.0f;
	}
};

#endif
