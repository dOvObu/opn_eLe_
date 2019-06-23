#ifndef OPNQUADF_H
#define OPNQUADF_H

#include "../drawable_objects/opnShader.h"
#include "opnQuad.h"
#include <memory>


/*
Пусть шейдер выполняет преобразование из oldPos в newPos,
т.ч. для любой точки opnQuad-а верно

		a.0.0, c.0.1, tx.0.2,
		b.1.0, d.1.1, ty.1.2
		= MatrixFromFlash;

		x, y = oldPos;

		newPos = {
			x*a + y*c + tx,
			x*b + y*d + ty
		};
*/

class opnAnimation {
public:
	opnAnimation (const char path[]) {}
private:
};

class opnQuadF
{
public:
	opnMat4 tr;
	opnQuadF (const char path[] = "img.jpg");
	~opnQuadF ();
	void draw ();
	static void setShared (opnShader& sh) { shad = &sh; }

	inline void applyMat (glm::mat2& m) { currentMatrix = m; }
	inline void applyMat (glm::mat2&& m) { currentMatrix = m; }
	inline void setPosition (glm::vec2& v) { posAndOrig[0][0] = v.x; posAndOrig[0][1] = v.y; }
	inline void setPosition (glm::vec2&& v) { posAndOrig[0][0] = v.x; posAndOrig[0][1] = v.y; }
	inline void setOrigin (glm::vec2& v) { posAndOrig[1][0] = v.x; posAndOrig[1][1] = v.y; }
	inline void setOrigin (glm::vec2&& v) { posAndOrig[1][0] = v.x; posAndOrig[1][1] = v.y; }
	
	inline glm::vec2 getPosition () { return glm::vec2 (posAndOrig[0][0], posAndOrig[0][1]); }
	inline glm::vec2 getOrigin () { return glm::vec2 (posAndOrig[1][0], posAndOrig[1][1]); }

private:
	glm::mat2 currentMatrix {1.f, 0.f, 1.f, 0.f};
	glm::mat2 posAndOrig{0.f, 0.f, 0.f, 0.f};
	opnTexture texture;
	float depth{0.f};
	opnQuad qd;
	static opnShader* shad;
};

#endif
