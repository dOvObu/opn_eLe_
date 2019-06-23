#ifndef OPNBOX_H
#define OPNBOX_H

#define GLEW_STATIC
#define DGLEW_NO_GLU
#include <GL/glew.h>

#include "../drawable_objects/opnShader.h"
#include "opnTexture.h"
#include "../drawable_objects/opnMat4.h"

class opnBox
{
public:
	opnMat4 tr;

	opnBox (opnShader& shad_, const char path[] = "img.jpg", glm::vec3&& size = {1.f,1.f,1.f});

	~opnBox () {
		glDeleteVertexArrays (1, &VAO);
		glDeleteBuffers (1, &VBO);
	}

	inline void draw () {
		shad->setMat4 (tr, "transform");
		shad->setTexture (texture, "ourTexture");

		//draw qd-s
		glBindVertexArray (VAO);
		glDrawArrays (GL_TRIANGLES,0, 36);
		tr.setE ();
	}

private:
	GLuint VBO, VAO;
	opnShader* shad;
	opnTexture texture;
};

#endif