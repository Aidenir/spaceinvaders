/* /////////////////////////////////////////////////////////////////////
//	File:		Texture.cpp
//	Author		Blankycan
// Copyright 2013 Blankycan
///////////////////////////////////////////////////////////////////// */
#include "Texture.h"
// OS include
#include "os.h"
// Std & General include
#if defined (LINUX)
	#include <GL/glew.h>
#elif defined (WINDOWS)
	#include "include/GL/glew.h"
#endif
#include <vector>
#include <iostream>
// Application includes
#include "GraphicsManager.h"
#include "Location.h"
////////////////////////////////////////////////////////////////////////

Texture::Texture(char *filename)
{
	/*
	std::vector<unsigned char, std::allocator<unsigned char>> data;
	lodepng::load_file(data, "img/BlankEngineLogo.png");

	if(data.empty())
		return;
	*/
	char filelocation[256];
	strcpy(filelocation, Util::GetCurrentDir());
	strcat(filelocation, "/images/");
	strcat(filelocation, filename);

	
	// Load file and decode image.
	//unsigned error = lodepng::decode(source, width, height, "img/blankEngineLogo.png");
	//unsigned error = lodepng::decode(source, width, height, "img/Floor.png");
	//unsigned error = lodepng::decode(source, width, height, "img/red.png");
	//unsigned error = lodepng::decode(source, width, height, "img/rb.png");
	unsigned error = lodepng::decode(source, width, height, filelocation);

	// If there's an error, display it.
	if(error != 0)
	{
		std::cout << "error " << error << ": " << lodepng_error_text(error) << std::endl;
		return;
	}

	// Texture size must be power of two for the primitive OpenGL version this is written for. Find next power of two.
	u2 = 1; while(u2 < width) u2 *= 2;
	v2 = 1; while(v2 < height) v2 *= 2;
	// Ratio for power of two version compared to actual version, to render the non power of two image with proper size.
	u3 = (double)width / u2;
	v3 = (double)height / v2;

	// Make power of two version of the image. 
	image = std::vector<unsigned char>(u2 * v2 * 4);
	for(size_t y = 0; y < height; y++){
		for(size_t x = 0; x < width; x++){
			for(size_t c = 0; c < 4; c++)
			{
				// Flip the row
				int row = 4 * width * (height-1) - 4 * width * y;
				int column = 4 * x + c;
				image[4 * u2 * y + 4 * x + c] = source[row + column];
			}
		}
	}

	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &image[0]);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);


	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); //GL_NEAREST = no smoothing
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	//glTexImage2D(GL_TEXTURE_2D, 0, 4, u2, v2, 0, GL_RGBA, GL_UNSIGNED_BYTE, &image[0]);

			/*
	// Enable the texture for OpenGL.
	glEnable(GL_TEXTURE_2D);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); //GL_NEAREST = no smoothing
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, 4, u2, v2, 0, GL_RGBA, GL_UNSIGNED_BYTE, &image[0]);

	bool done = false;
	SDL_Event event = {0};
	glColor4ub(255, 255, 255, 255);

	while(!done)
	{
		// Quit the loop when receiving quit event.
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT) done = 1;
		}

		// Draw the texture on a quad, using u3 and v3 to correct non power of two texture size.
		glBegin(GL_QUADS);
		glTexCoord2d( 0,  0); glVertex2f(    0,      0);
		glTexCoord2d(u3,  0); glVertex2f(width,      0);
		glTexCoord2d(u3, v3); glVertex2f(width, height);
		glTexCoord2d( 0, v3); glVertex2f(    0, height);
		glEnd();

		// Redraw and clear screen.
		SDL_GL_SwapBuffers();
		glClearColor(0, 0, 0, 0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Limit frames per second, to not heat up the CPU and GPU too much.
		SDL_Delay(16);
	}
	*/
}

Texture::~Texture()
{

}