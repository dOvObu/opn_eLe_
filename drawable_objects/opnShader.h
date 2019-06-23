#ifndef OPNSHADER_H
#define OPNSHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#define GLEW_STATIC
#define DGLEW_NO_GLU
#include <GL/glew.h>
#include "opnTexture.h"
#include "opnMat4.h"

class opnShader {
public:
	opnShader (const char vertPath[] = "core.vert", const char fragPath[] = "core.frag");

	inline void use (void) {
		glUseProgram (program);
	}
	inline void setTexture (opnTexture& texture, const char name[]) {
		glActiveTexture (GL_TEXTURE0);
		texture.bind ();
		glUniform1i (glGetUniformLocation (program, name), 0);
	}

	//uniform aliases
	inline void viewAndProjection (opnMat4& view, opnMat4& projection) {
		setMat4 (projection, "projection");
		setMat4 (view, "view");
	}
	inline void setMat4 (const opnMat4& m, const char name[]) {
		int trLocation = glGetUniformLocation (program, name);
		glUniformMatrix4fv (trLocation, 1, GL_FALSE, glm::value_ptr (m.tr));
	}
	inline void setMat2 (const glm::mat2& m, const char name[]) {
		int trLocation = glGetUniformLocation (program, name);
		glUniformMatrix2fv (trLocation, 1, GL_FALSE, glm::value_ptr (m));
	}
	inline void setFloat (const float& value, const char name[]) {
		int trLocation = glGetUniformLocation (program, name);
		glUniform1f (trLocation, value);
	}
	inline void setVec3 (glm::vec3&& v, const char name[]) {
		int vLocation = glGetUniformLocation (program, name);
		glUniform3fv (vLocation, 1, glm::value_ptr (v));
	}
	inline void setVec3 (const glm::vec3& v, const char name[]) {
		int vLocation = glGetUniformLocation (program, name);
		glUniform3fv (vLocation, 1, glm::value_ptr (v));
	}

private:
	GLuint program;
};

#endif
