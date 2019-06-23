#include "opnQuad.h"

void opnQuad::init (float width, float height)
{
	width *= 0.5f;
	height *= 0.5f;

	GLfloat vertices[] =
	{
		// Positions          // Colors           // Texture Coords
		width,  height, 0.0f,   /*1.0f, 0.0f, 0.0f,*/   1.0f, 1.0f, // Top Right
		width, -height, 0.0f,   /*0.0f, 1.0f, 0.0f,*/   1.0f, 0.0f, // Bottom Right
		-width, -height, 0.0f,   /*0.0f, 0.0f, 1.0f,*/   0.0f, 0.0f, // Bottom Left
		-width,  height, 0.0f,   /*1.0f, 1.0f, 0.0f,*/   0.0f, 1.0f  // Top Left
	};
	GLuint indices[] =
	{  // Note that we start from 0!
		0, 1, 3, // First Triangle
		1, 2, 3  // Second Triangle
	};
	glGenVertexArrays (1, &VAO);
	glGenBuffers (1, &VBO);
	glGenBuffers (1, &EBO);

	glBindVertexArray (VAO);

	glBindBuffer (GL_ARRAY_BUFFER, VBO);
	glBufferData (GL_ARRAY_BUFFER, sizeof (vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer (GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData (GL_ELEMENT_ARRAY_BUFFER, sizeof (indices), indices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof (GLfloat), (GLvoid *)0);
	glEnableVertexAttribArray (0);
	// Texture Coordinate attribute
	glVertexAttribPointer (1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof (GLfloat), (GLvoid *)(3 * sizeof (GLfloat)));
	glEnableVertexAttribArray (1);

	glBindVertexArray (0); // Unbind VAO
}

