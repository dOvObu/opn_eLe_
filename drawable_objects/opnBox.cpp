#include "opnBox.h"


opnBox::opnBox (opnShader& shad_, const char path[], glm::vec3&& size)
	: texture (path), shad (&shad_)
{
	const auto x = size.x * 0.5f;
	const auto y = size.y * 0.5f;
	const auto z = size.z * 0.5f;
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

	glGenVertexArrays (1, &VAO);
	glGenBuffers (1, &VBO);

	glBindVertexArray (VAO);

	glBindBuffer (GL_ARRAY_BUFFER, VBO);
	glBufferData (GL_ARRAY_BUFFER, sizeof (vertices), vertices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof (GLfloat), (GLvoid *)0);
	glEnableVertexAttribArray (0);
	// TexCoord attribute
	glVertexAttribPointer (1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof (GLfloat), (GLvoid *)(3 * sizeof (GLfloat)));
	glEnableVertexAttribArray (1);

	glBindVertexArray (0); // Unbind VAO
}

