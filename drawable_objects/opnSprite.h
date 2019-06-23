#ifndef OPNSPRITE_H
#define OPNSPRITE_H

#include "../drawable_objects/opnShader.h"
#include "opnQuad.h"
#include <memory>

class opnSprite
{
public:
	opnMat4 tr;

	opnSprite (opnShader& shad, const char path[] = "img.jpg");
	~opnSprite ();
	void draw ();

private:
	opnTexture texture;
	opnQuad qd;
	opnShader* shad;
};

#endif
