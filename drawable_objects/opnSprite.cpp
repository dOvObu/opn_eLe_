#include "opnSprite.h"



opnSprite::opnSprite (opnShader& shad_, const char path[])
	: texture (path), qd (texture), shad (&shad_)
{
}

opnSprite::~opnSprite () {}


void opnSprite::draw ()
{
	shad->setMat4 (tr, "transform");
	shad->setTexture (texture, "ourTexture");
	
	qd.draw ();
	tr.tr = glm::mat4x4 (1);
}
