#ifndef OPNSHADER_H
#define OPNSHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <GL/glew.h>
#include "drawable_objects/opnTexture.h"
#include "opnMat4.h"

class opnShader {
private:
public:
	GLuint program;
	inline void use (void) { glUseProgram (program); }
	inline void viewAndProjection (opnMat4& view, opnMat4& projection)
	{
		setMat4 (view, "view");
		setMat4 (projection, "projection");
	}
	inline void setMat4(opnMat4& m, const char name[])
	{
		int trLocation = glGetUniformLocation(program, name);
		glUniformMatrix4fv(trLocation, 1, GL_FALSE, glm::value_ptr(m.tr));
	}
	inline void setVec3 (glm::vec3&& v, const char name[])
	{
		int vLocation = glGetUniformLocation (program, name);
		glUniform3fv (vLocation, 1, glm::value_ptr (v));
	}
	inline void setTexture(opnTexture& texture, const char name[])
	{
		// Draw our first triangle
		glActiveTexture (GL_TEXTURE0);
		texture.bind ();
		glUniform1i (glGetUniformLocation (program, name), 0);
	}

	opnShader(const char vertPath[] = "core.vert", const char fragPath[] = "core.frag")
	{
		// 1. Retrieve the vertex/fragment source code from filePath
		std::string vertexCode;
		std::string fragmentCode;
		std::ifstream vShaderFile;
		std::ifstream fShaderFile;
		// ensures ifstream objects can throw exceptions:
		vShaderFile.exceptions(std::ifstream::badbit);
		fShaderFile.exceptions(std::ifstream::badbit);
		try
		{
			// Open files
			vShaderFile.open (vertPath);
			fShaderFile.open (fragPath);
			std::stringstream vShaderStream, fShaderStream;
			// Read file's buffer contents into streams
			vShaderStream << vShaderFile.rdbuf();
			fShaderStream << fShaderFile.rdbuf();
			// close file handlers
			vShaderFile.close();
			fShaderFile.close();
			// Convert stream into string
			vertexCode = vShaderStream.str ();
			fragmentCode = fShaderStream.str ();
		}
		catch (std::ifstream::failure e)
		{
			std::cerr << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ\n";
		}
		const GLchar *vShaderCode = vertexCode.c_str();
		const GLchar *fShaderCode = fragmentCode.c_str();
		// 2. Compile shaders
		GLuint vertex, fragment;
		GLint success;
		GLchar infoLog[512];
		// Vertex Shader
		vertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex, 1, &vShaderCode, NULL);
		glCompileShader(vertex);
		// Print compile errors if any
		glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertex, 512, NULL, infoLog);
			std::cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << '\n';
		}
		// Fragment Shader
		fragment = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment, 1, &fShaderCode, NULL);
		glCompileShader(fragment);
		// Print compile errors if any
		glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragment, 512, NULL, infoLog);
			std::cerr << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << '\n';
		}
		// Shader Program
		program = glCreateProgram();
		glAttachShader (program, vertex);
		glAttachShader (program, fragment);
		glLinkProgram (program);
		// Print linking errors if any
		glGetProgramiv (program, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog (program, 512, NULL, infoLog);
			std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << '\n';
		}
		// Delete the shaders as they're linked into our program now and no longer necessery
		glDeleteShader(vertex);
		glDeleteShader(fragment);
	}
};

#endif
