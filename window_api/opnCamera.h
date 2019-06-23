#ifndef OPNCAMERA_H
#define OPNCAMERA_H

// GLEW
#define GLEW_STATIC
#define DGLEW_NO_GLU
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>

#include "../drawable_objects/opnMat4.h"


class opnCamera
{
public:
	//bool firstMouse{true};
	float yaw {-90.f};//nouse to right/ to left
	float pitch {0.f};//nouse up/down
	float fov {45.f}; //on left/right shoulder

	glm::vec3 pos {0.f, 0.f, 3.f};
	glm::vec3 front {0.f, 0.f, 1.f};
	glm::vec3 up () { return upVec; }

	float dt = 0;
	void loadTo (opnMat4& view) { view.tr = glm::lookAt (pos, pos + front, upVec); }

	void framebuffer_size_callback (GLFWwindow* window, int&& width, int&& height) {
		glViewport (0, 0, width, height);
	}

	virtual void mouse_callback (GLFWwindow* window, double&& xpos, double&& ypos) = 0;
	virtual void scroll_callback (GLFWwindow* window, double&& xoffset, double&& yoffset) = 0;
	virtual ~opnCamera () {}

private:
	glm::vec3 upVec {0.f, 1.f, 0.f};
};

extern opnCamera* currentCamera;

#endif
