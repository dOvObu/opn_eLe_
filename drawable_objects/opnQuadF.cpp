#include "opnQuadF.h"

opnShader* opnQuadF::shad{nullptr};

opnQuadF::opnQuadF (const char path[])
	: texture (path), qd (texture)
{}

opnQuadF::~opnQuadF () {}


void opnQuadF::draw ()
{
	shad->setMat2 (currentMatrix, "opnQuadMat");
	shad->setMat2 (posAndOrig, "transpose");
	shad->setFloat (depth, "opnQuadDepth");

	shad->setMat4 (tr, "transform");
	shad->setTexture (texture, "ourTexture");
	
	qd.draw ();
	tr.tr = glm::mat4x4 (1);
}
