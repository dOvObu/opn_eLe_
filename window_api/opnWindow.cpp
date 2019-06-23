#include "opnWindow.h"



void _____callbacks___::framebuffer_size_callback (GLFWwindow* window, int width, int height)
{
	currentCamera->framebuffer_size_callback (window, std::move (width), std::move (height));
}

void _____callbacks___::mouse_callback (GLFWwindow* window, double xpos, double ypos)
{
	currentCamera->mouse_callback (window, std::move (xpos), std::move (ypos));
}

void _____callbacks___::scroll_callback (GLFWwindow* window, double xoffset, double yoffset)
{
	if (currentCamera->fov >= 1.0f && currentCamera->fov <= 45.0f) currentCamera->fov -= yoffset;
	if (currentCamera->fov <= 1.0f) currentCamera->fov = 1.0f;
	if (currentCamera->fov >= 45.0f) currentCamera->fov = 45.0f;
}


opnWindow::opnWindow (
	const char name[],
	const int& width_,
	const int& height_,
	const bool fullscreen)
	: width (width_), height (height_)
{
	glfwInit ();

	// Задать настройки для GLFW
	glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint (GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint (GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	glfwWindowHint (GLFW_RESIZABLE, GL_FALSE);

	// Создать GLFWwindow объект, который можно исп. для GLFW функций
	window = glfwCreateWindow (width, height, name, fullscreen ? glfwGetPrimaryMonitor () : nullptr, nullptr);

	glfwGetFramebufferSize (window, &screenWidth, &screenHeight);
	try {
		if (nullptr == window) {
			throw "Failed to create GLFW window";
			glfwTerminate ();
		}
		glfwMakeContextCurrent (window);
		glewExperimental = GL_TRUE;

		if (GLEW_OK != glewInit ()) {
			throw "Failed to initialize GLEW";
		}
		glViewport (0, 0, screenWidth, screenHeight);
		glEnable (GL_DEPTH_TEST);
	}
	catch (const char errorLog[]) {
		std::cerr << errorLog << '\n';
		allRight = false;
	}
}
