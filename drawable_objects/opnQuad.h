#ifndef OPNQUAD_H
#define OPNQUAD_H

#include "opnTexture.h"

class opnQuad
{
public:
	opnQuad (const opnTexture& texture) {
		auto size = texture.getSize ();
		init (static_cast<float>(size.first), static_cast<float>(size.second));
	}
	opnQuad (float width = 1.f, float height = 1.f) { init (width, height); }
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

private:
	GLuint VBO, VAO, EBO;
	void init (float width, float height);
};

#endif
