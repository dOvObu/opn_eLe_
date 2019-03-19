#ifndef OPNBOX_H
#define OPNBOX_H

#define GLEW_STATIC
#include <GL/glew.h>

#include "../opnShader.h"
#include "opnTexture.h"
#include "../opnMat4.h"

class opnBox
{
	GLuint VBO, VAO;
	opnShader* shad;
	opnTexture texture;
public:
	opnMat4 tr;

	opnBox(opnShader& shad_, const char path[] = "img.jpg", float x = 1.f, float y = 1.f, float z = 1.f)
		: texture (path), shad (&shad_)
	{
		x *= 0.5f;
		y *= 0.5f;
		z *= 0.5f;
		// use with Perspective Projection
		GLfloat vertices[] = {
			-x, -y, -z,  0.0f, 0.0f,
			x, -y, -z,  1.0f, 0.0f,
			x,  y, -z,  1.0f, 1.0f,
			x,  y, -z,  1.0f, 1.0f,
			-x,  y, -z,  0.0f, 1.0f,
			-x, -y, -z,  0.0f, 0.0f,

			-x, -y,  z,  0.0f, 0.0f,
			x, -y,  z,  1.0f, 0.0f,
			x,  y,  z,  1.0f, 1.0f,
			x,  y,  z,  1.0f, 1.0f,
			-x,  y,  z,  0.0f, 1.0f,
			-x, -y,  z,  0.0f, 0.0f,

			-x,  y,  z,  1.0f, 0.0f,
			-x,  y, -z,  1.0f, 1.0f,
			-x, -y, -z,  0.0f, 1.0f,
			-x, -y, -z,  0.0f, 1.0f,
			-x, -y,  z,  0.0f, 0.0f,
			-x,  y,  z,  1.0f, 0.0f,

			x,  y,  z,  1.0f, 0.0f,
			x,  y, -z,  1.0f, 1.0f,
			x, -y, -z,  0.0f, 1.0f,
			x, -y, -z,  0.0f, 1.0f,
			x, -y,  z,  0.0f, 0.0f,
			x,  y,  z,  1.0f, 0.0f,

			-x, -y, -z,  0.0f, 1.0f,
			x, -y, -z,  1.0f, 1.0f,
			x, -y,  z,  1.0f, 0.0f,
			x, -y,  z,  1.0f, 0.0f,
			-x, -y,  z,  0.0f, 0.0f,
			-x, -y, -z,  0.0f, 1.0f,

			-x,  y, -z,  0.0f, 1.0f,
			x,  y, -z,  1.0f, 1.0f,
			x,  y,  z,  1.0f, 0.0f,
			x,  y,  z,  1.0f, 0.0f,
			-x,  y,  z,  0.0f, 0.0f,
			-x,  y, -z,  0.0f, 1.0f
		};

		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);

		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		// Position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid *)0);
		glEnableVertexAttribArray(0);
		// TexCoord attribute
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid *)(3 * sizeof(GLfloat)));
		glEnableVertexAttribArray(1);

		glBindVertexArray(0); // Unbind VAO
	}

	~opnBox ()
	{
		glDeleteVertexArrays (1, &VAO);
		glDeleteBuffers (1, &VBO);
	}

	inline void draw ()
	{
		shad->setMat4 (tr, "transform");
		shad->setTexture (texture, "ourTexture");

		//draw qd-s
		glBindVertexArray (VAO);
		glDrawArrays (GL_TRIANGLES,0, 36);
		tr.tr = glm::mat4x4 (1);
	}
};

#endif