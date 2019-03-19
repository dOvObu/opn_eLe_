#include "opnRectangle.h"

opnRectangle::opnRectangle (
	opnShader& shad_,
	float width_,
	float height_,
	float x_, float y_, float z_,
	float r_, float g_, float b_)
	: shad (&shad_),
	width(width_), height(height_),
	x(x_), y(y_), z(z_),
	r(r_), g(g_), b(b_),
	quad (width_, height_)
{}

void opnRectangle::draw ()
{
	//glm::scale (tr.tr, glm::vec3 (width_scale, height_scale, 0));
	tr.translate (x, y, z);
	shad->setMat4 (tr, "transform");
	shad->setVec3 (glm::vec3(r,g,b), "colr");
	quad.draw ();
	tr.tr = glm::mat4x4 (1);
}

opnRectangle::~opnRectangle(){}
