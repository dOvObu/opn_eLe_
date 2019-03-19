#ifndef OPNMAT4_H
#define OPNMAT4_H
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class opnMat4
{
private:
public:
	glm::mat4 tr;
	opnMat4() :tr(1) {}
	opnMat4& translate(float x, float y, float z) { tr = glm::translate(tr, glm::vec3(x, y, z)); return *this; }
	opnMat4& rotate(float angle, float xn, float yn, float zn) { tr = glm::rotate(tr, angle, glm::vec3(xn, yn, zn)); return *this; }
};

#endif
