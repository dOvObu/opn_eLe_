#ifndef OPNRECTANGLE_H
#define OPNRECTANGLE_H

#include "../drawable_objects/opnMat4.h"
#include "../drawable_objects/opnShader.h"
#include "opnQuad.h"

// flash-like rectangles
class opnRectangle
{
public:
	opnRectangle (
		opnShader& shad_,
		float width_ = 0.f, float height_ = 0.f,
		glm::vec3&& pos = {0.f,0.f,0.f},
		glm::vec3&& color = {1.f,1.f,1.f});

	~opnRectangle ();

	void setPos (glm::vec3&& pos_) { pos = pos_; }
	void setPos (glm::vec2&& pos_) { pos.x = pos_.x, pos.y = pos_.y; }
	void setDepth (float z_) { pos.z = z_; }
	void draw ();
	opnMat4 tr;

private:
	opnQuad quad;
	opnShader* shad;
	float width, height;
	glm::vec3 pos;
	glm::vec3 color;
	float width_scale{1.f};
	float height_scale{1.f};
};

#endif
