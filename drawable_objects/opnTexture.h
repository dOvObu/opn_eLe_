#ifndef OPNTEXTURE_H
#define OPNTEXTURE_H

#define GLEW_STATIC

#define OPN_SCALE 500.f

#include "GL/glew.h"

#include <SOIL2/SOIL2.h>

class opnTexture
{
private:
	GLuint texture;
	int width, height;
	unsigned char *image;

public:
	void bind () const { glBindTexture(GL_TEXTURE_2D, texture); }


	opnTexture (const char name[] = "img.jpg")
	{
		// ===================
		// Texture
		// ===================
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		// Set our texture parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		// Set texture filtering
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		// Load, create texture and generate mipmaps
		image = SOIL_load_image (name, &width, &height, 0, SOIL_LOAD_RGBA);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
		glGenerateMipmap(GL_TEXTURE_2D);
		SOIL_free_image_data (image);
		glBindTexture (GL_TEXTURE_2D, 0);
	}
	~opnTexture () {}
	inline const int getWidth () const { return width; }
	inline const int getHeight () const { return height; }
};






class opnQuad
{
	GLuint VBO, VAO, EBO;
	void init (float width, float height)
	{
		width *= 0.5f / OPN_SCALE;
		height *= 0.5f / OPN_SCALE;

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
public:

	opnQuad (const opnTexture& texture)
	{
		init (static_cast<float>(texture.getWidth ()),
		      static_cast<float>(texture.getHeight ()));
	}

	opnQuad (float width = 1.f, float height = 1.f)
	{
		init (width, height);
	}

	~opnQuad ()
	{
		glDeleteVertexArrays (1, &VAO);
		glDeleteBuffers (1, &VBO);
		glDeleteBuffers (1, &EBO);
	}

	inline void draw ()
	{
		glBindVertexArray (VAO);
		glDrawElements (GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray (0);
	}
};

#endif
