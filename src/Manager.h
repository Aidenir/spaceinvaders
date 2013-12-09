/* /////////////////////////////////////////////////////////////////////
//	File:		GameManager.h
//	Author		Blankycan
// Copyright 2013 Blankycan
///////////////////////////////////////////////////////////////////// */
#ifndef MANAGER_H
#define MANAGER_H
////////////////////////////////////////////////////////////////////////
// OS include
#include "OS/OS.h"
// Std & General includes
#if defined (LINUX)
	#include <GL/glew.h>
	#include <GL/glx.h>
	#include <X11/Xlib.h>
	#include <X11/Xutil.h>
#elif defined (WINDOWS)
	#include <Windows.h>			// Windows
	#define GLEW_STATIC
	#include "include/GL/glew.h"
	#include <gl/GL.h>				// OpenGL32
#endif
////////////////////////////////////////////////////////////////////////

/**	Manager
	Default manager, override in sub-managers.
*/
class Manager{
public:
	/* Default destructor */
	virtual ~Manager() {}
	/* Returns whether the Manager is initialized successfully */
	bool Initialized() {return initialized;}
	
protected:
	/* Default constructor */
	Manager() {}
	
	/* True if Manager is successfully initialized */
	bool initialized;
};

////////////////////////////////////////////////////////////////////////
#endif	// MANAGER_H
////////////////////////////////////////////////////////////////////////
