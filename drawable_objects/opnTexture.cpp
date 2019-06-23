#include "opnTexture.h"

std::map<std::string, std::shared_ptr<_____RealTexture_____> > opnTexture::textures;

opnTexture::opnTexture (const char name[])
{
	if (textures.count (name) > 0) {
		rt = textures[name].get ();
		return;
	}
	textures[name] = std::shared_ptr<_____RealTexture_____> (rt = new _____RealTexture_____ ());
	glGenTextures (1, &rt->texture);
	glBindTexture (GL_TEXTURE_2D, rt->texture);
	// Set our texture parameters
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// Set texture filtering
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// Load, create texture and generate mipmaps
	unsigned char *image = SOIL_load_image (name, &rt->width, &rt->height, 0, SOIL_LOAD_RGBA);
	glTexImage2D (GL_TEXTURE_2D, 0, GL_RGBA, rt->width, rt->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap (GL_TEXTURE_2D);
	SOIL_free_image_data (image);
	glBindTexture (GL_TEXTURE_2D, 0);
}
