#ifndef OPNWINDOW_H
#define OPNWINDOW_H

// GLEW
#define GLEW_STATIC
#define DGLEW_NO_GLU
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>

#include <Windows.h>
#include <iostream>
#include <utility>

#include "./opnCamera.h"
#include "../drawable_objects/opnMat4.h"


namespace _____callbacks___ {
	void framebuffer_size_callback (GLFWwindow* window, int width, int height);
	void mouse_callback (GLFWwindow* window, double xpos, double ypos);
	void scroll_callback (GLFWwindow* window, double xoffset, double yoffset);
}

class opnWindow {
public:
	GLFWwindow* window = nullptr;

	opnWindow (
		const char name[] = "window",
		const int& width_ = 800,
		const int& height_ = 600,
		const bool fullscreen = false);

	~opnWindow (void) {
		if (allRight) {
			glfwTerminate ();
		}
	}
	
	inline bool isOpen (void) { return !glfwWindowShouldClose (window); }
	inline void show (void) { glfwSwapBuffers (window); }
	inline bool problems (void) { return !allRight; }
	inline void events (void) { glfwPollEvents (); }
	inline void clear (const float& r, const float& g, const float& b) { glClearColor (r, g, b, 1.0f), glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); }
	inline void alphaOn (void) { glEnable (GL_BLEND), glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); }
	inline void setPerspective (opnMat4& projection) { projection.tr = glm::perspective ( 45.0f, (GLfloat)screenWidth / (GLfloat)screenHeight, 0.1f, 100.0f); }
	inline void setOrtho (opnMat4& projection) { projection.tr = glm::ortho (0.0f, (GLfloat)screenWidth, 0.0f, (GLfloat)screenHeight, 0.1f, 1000.0f); }
	inline const std::pair<int, int> getSize () const { return {width, height}; }
	inline const std::pair<int,int> getScreenSize () const { return {screenWidth, screenHeight}; }
	inline const bool pressed (const int& key) const{ return glfwGetKey (window, key) == GLFW_PRESS; }
	inline void close () const { glfwSetWindowShouldClose (window, true); }
	inline void setCursorVisible (bool visible) { ShowCursor (visible); }
	inline void setDefaultCallbacks ()
	{
		using namespace _____callbacks___;
		glfwSetFramebufferSizeCallback (window, framebuffer_size_callback);
		glfwSetCursorPosCallback (window, mouse_callback);
		glfwSetScrollCallback (window, scroll_callback);
	}

private:
	int width, height;
	int screenWidth, screenHeight;
	bool allRight = true;
};


#endif
