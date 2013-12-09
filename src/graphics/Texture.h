/* /////////////////////////////////////////////////////////////////////
//	File:		Texture.h
//	Author		Blankycan
// Copyright 2013 Blankycan
///////////////////////////////////////////////////////////////////// */
#ifndef TEXTURE_H
#define TEXTURE_H
////////////////////////////////////////////////////////////////////////
#include "lodepng.h"
////////////////////////////////////////////////////////////////////////

/**	Texture
	Contains information of a 'picture'
*/
struct Texture
{
public:
	Texture(char *filename);
	~Texture();

	std::vector<unsigned char> image, source;
	unsigned width, height;
	// Texture size must be power of two for the primitive OpenGL version this is written for. Find next power of two.
	size_t u2, v2;
	// Ratio for power of two version compared to actual version, to render the non power of two image with proper size.
	double u3, v3;

	// Texture id
	unsigned int id;
private:

};

////////////////////////////////////////////////////////////////////////
#endif	// TEXTURE_H
////////////////////////////////////////////////////////////////////////