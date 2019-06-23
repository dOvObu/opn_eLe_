#ifndef OPNTEXTURE_H
#define OPNTEXTURE_H


#define GLEW_STATIC
#define DGLEW_NO_GLU
#include <GL/glew.h>

#include <SOIL2/SOIL2.h>

#include <utility>
#include <string>
#include <memory>
#include <map>

struct _____RealTexture_____ {
	GLuint texture;
	int width, height;
};

class opnTexture
{
public:
	inline void bind () const { glBindTexture(GL_TEXTURE_2D, rt->texture); }
	opnTexture (const char name[] = "img.jpg");
	~opnTexture () {}
	inline const std::pair<int,int> getSize () const { return {rt->width, rt->height}; }

private:
	_____RealTexture_____ *rt{nullptr};
	static std::map<std::string, std::shared_ptr<_____RealTexture_____> > textures;
};


#endif
