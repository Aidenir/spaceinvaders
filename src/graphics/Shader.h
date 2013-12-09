/* /////////////////////////////////////////////////////////////////////
//	File:		Shader.h
//	Author		Blankycan
// Copyright 2013 Blankycan
///////////////////////////////////////////////////////////////////// */
#ifndef SHADER_H
#define SHADER_H
////////////////////////////////////////////////////////////////////////
// OS includes
#include "os.h"
// Std & General includes
#if defined (LINUX)
    #include <GL/glew.h>
#elif defined (WINDOWS)
	#include <Windows.h>			// Windows
	#define GLEW_STATIC
	#include "include/GL/glew.h"
	#include <gl/GL.h>				// OpenGL32
#endif
// Application includes
#include "Global.h"
////////////////////////////////////////////////////////////////////////

/**	Shader
	Holds the shader information.
*/
struct Shader{
public:
	Shader(){
		vertexShader = 
		tesselationShader =	
		geometryShader = 
		fragmentShader = 
		program = -1;
		vertFile = NULL;
		tessFile = NULL;
		geomFile = NULL;
		fragFile = NULL;
	}
	~Shader(){
		if(vertFile)
			delete[] vertFile;
		if(tessFile)
			delete[] tessFile;
		if(geomFile)
			delete[] geomFile;
		if(fragFile)
			delete[] fragFile;
	}

	GLuint vertexShader;
	GLuint tesselationShader;
	GLuint geometryShader;
	GLuint fragmentShader;
	GLuint program;

	char* vertFile;
	char* tessFile;
	char* geomFile;
	char* fragFile;
};

////////////////////////////////////////////////////////////////////////
#endif	// SHADER_H
////////////////////////////////////////////////////////////////////////