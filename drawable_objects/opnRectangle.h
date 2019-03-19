#ifndef OPNRECTANGLE_H
#define OPNRECTANGLE_H

#include "../opnMat4.h"
#include "../opnShader.h"

class opnRectangle
{
public:
	opnRectangle (
		opnShader& shad_,
		float width_ = 0.f, float height_ = 0.f,
		float x_ = 0.f, float y_ = 0.f, float z_ = 0.f,
		float r_= 1.f, float g_ = 1.f, float b_ = 1.f);
	~opnRectangle ();

	void setPos (glm::vec3&& pos)
	{
		x = pos.x, y = pos.y, z = pos.z;
	}

	void draw ();

	opnMat4 tr;
private:
	opnQuad quad;
	opnShader* shad;
	float width, height;
	float x, y, z;
	float r, g, b;
	float width_scale{1.f};
	float height_scale{1.f};
};

#endif
