#ifndef OPNSPRITE_H
#define OPNSPRITE_H

#include "../opnShader.h"
#include <memory>

class opnSprite
{
	opnTexture texture;
	opnQuad qd;
	opnShader* shad;

public:
	opnMat4 tr;

	opnSprite (opnShader& shad, const char path[] = "img.jpg");
	~opnSprite ();

	void draw ();
};

#endif
