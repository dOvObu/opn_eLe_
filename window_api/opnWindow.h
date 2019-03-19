#ifndef OPNWINDOW_H
#define OPNWINDOW_H

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>

#include <Windows.h>
#include <iostream>

#include "./opnCamera.h"
#include "../opnMat4.h"

void framebuffer_size_callback (GLFWwindow* window, int width, int height);
void mouse_callback (GLFWwindow* window, double xpos, double ypos);
void scroll_callback (GLFWwindow* window, double xoffset, double yoffset);

class opnWindow {
private:
	int width, height;
	int screenWidth, screenHeight;
	bool allRight = true;

public:
	GLFWwindow* window = nullptr;

	opnWindow (
		const char name[] = "window",
		const int& width_ = 800,
		const int& height_ = 600,
		const bool fullscreen = false)
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
	~opnWindow (void) {
		if (allRight) {
			glfwTerminate ();
		}
	}
	bool isOpen (void) { return !glfwWindowShouldClose (window); }
	inline void swap (void) { glfwSwapBuffers (window); }
	bool problems (void) { return !allRight; }
	inline void events (void) { glfwPollEvents (); }
	inline void clear (const float& r, const float& g, const float& b) {
		glClearColor (r, g, b, 1.0f);
		glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	inline void alphaOn (void) {
		glEnable (GL_BLEND);
		glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}
	inline void setPerspective (opnMat4& projection) {
		projection.tr = glm::perspective (
			45.0f, (GLfloat)screenWidth / (GLfloat)screenHeight, 0.1f, 100.0f);
	}
	inline void setOrtho (opnMat4& projection) {
		projection.tr = glm::ortho (0.0f, (GLfloat)screenWidth, 0.0f,
			(GLfloat)screenHeight, 0.1f, 1000.0f);
	}
	inline const int getWidth () const { return width; }
	inline const int getHeight () const { return height; }
	inline const int getScreenWidth () const { return screenWidth; }
	inline const int getScreenHeight () const { return screenHeight; }
	inline const bool pressed (const int& key) const{ return glfwGetKey (window, key) == GLFW_PRESS; }
	inline void close () const { glfwSetWindowShouldClose (window, true); }
	inline void setCursorVisible (bool visible) { ShowCursor (visible); }
	inline void setDefaultCallbacks ()
	{
		glfwSetFramebufferSizeCallback (window, framebuffer_size_callback);
		glfwSetCursorPosCallback (window, mouse_callback);
		glfwSetScrollCallback (window, scroll_callback);
	}
};



void framebuffer_size_callback (GLFWwindow* window, int width, int height);
void mouse_callback (GLFWwindow* window, double xpos, double ypos);
void scroll_callback (GLFWwindow* window, double xoffset, double yoffset);

#endif
