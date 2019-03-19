#include "opnWindow.h"


// glfw: при изменении размера окна исполняется эта функция
void framebuffer_size_callback (GLFWwindow* window, int width, int height)
{
	currentCamera->framebuffer_size_callback (window, std::move (width), std::move (height));
}

void mouse_callback (GLFWwindow* window, double xpos, double ypos)
{
	currentCamera->mouse_callback (window, std::move (xpos), std::move (ypos));
}

void scroll_callback (GLFWwindow* window, double xoffset, double yoffset)
{
	if (currentCamera->fov >= 1.0f && currentCamera->fov <= 45.0f) currentCamera->fov -= yoffset;
	if (currentCamera->fov <= 1.0f) currentCamera->fov = 1.0f;
	if (currentCamera->fov >= 45.0f) currentCamera->fov = 45.0f;
}


