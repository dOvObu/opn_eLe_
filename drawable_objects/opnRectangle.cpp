#include "opnRectangle.h"

opnRectangle::opnRectangle (
	opnShader& shad_,
	float width_,
	float height_,
	glm::vec3&& pos_,
	glm::vec3&& color_)
	: shad (&shad_),
	width(width_), height(height_),
	pos(pos_),
	color(color_),
	quad (width_, height_)
{}

void opnRectangle::draw ()
{
	//glm::scale (tr.tr, glm::vec3 (width_scale, height_scale, 0));
	tr.translate (pos);
	shad->setMat4 (tr, "transform");
	shad->setVec3 (color, "colr");
	quad.draw ();
	tr.setE ();
}

opnRectangle::~opnRectangle(){}
