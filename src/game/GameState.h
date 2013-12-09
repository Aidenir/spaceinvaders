/* /////////////////////////////////////////////////////////////////////
//	File:		GameState.h
//	Author		Blankycan
// Copyright 2013 Blankycan
///////////////////////////////////////////////////////////////////// */
#ifndef GAMESTATE_H
#define GAMESTATE_H
////////////////////////////////////////////////////////////////////////
// OS include
#include "os.h"
// Std & General includes
#if defined (LINUX)
	#include <GL/glew.h>
	#include <GL/glx.h>
	#include <X11/Xlib.h>
	#include <X11/Xutil.h>
#elif defined (WINDOWS)
	#include "include/GL/glew.h"	//<GL/glew.h>
	#include <gl/GL.h>				// OpenGL32
	#include <Windows.h>			// Windows
#endif
// Application includes
#include "RenderState.h"
#include "WindowState.h"
#include "Camera.h"
////////////////////////////////////////////////////////////////////////
#define MAX_NAME_LENGTH				32
////////////////////////////////////////////////////////////////////////

/**	GameState
	Base class for a gamestate, a gamestate has its own render function,
	update function and input handling. 
*/
class GameState
{
public:
	/* Constructor, requires a name for each new gamestate */
	GameState(char* stateName, WindowState *windowState);
	/* Destructor */
	~GameState();
	/* A method to update the gamestate */
	virtual void Update(float dt) = 0;
	/* Render gamestate specific geometry */
	virtual void Render(RenderState* renderState) = 0;
	/* Transforming the view-matrix into camera space */
	virtual void ApplyCamera(RenderState* renderState);
	/* Lets the specific gamestate handle the keyboard input */
	virtual void HandleKey(bool* keys) = 0;
	/* Lets the specific gamestate handle the mouse scroll */
	virtual void HandleMouseWheel(int delta) = 0;
#if defined (LINUX)
	/* Lets the specific gamestate handle the mouse movement/actions */
	virtual void HandleMouse(int xPos, int yPos, XButtonEvent button) = 0;
#elif defined (WINDOWS)
	/* Lets the specific gamestate handle the mouse movement/actions */
	virtual void HandleMouse(int xPos, int yPos, WPARAM wParam) = 0;
#endif
    
	/* Returns the gamestates unique id */
	int ID() {return id;}
	/* Returns whether the specific gamestate is in write mode or not */
	bool IsWriting() {return writing; }
	/* Function to set the writing state */
	void SetWriting( bool isWriting ) { writing = isWriting; }
protected:
	/* Camera of the gamestate */
	Camera *camera;
	/* Specific name for the gamestate */
	char stateName[MAX_NAME_LENGTH];
	/* A id counter to ensure that every gamestate has a unique id */
	static int idCount;
	/* The gamestates unique id */
	int id;
	/* Whether the specific gamestate is capturing writing or not */
	bool writing;
    /* Owner window state */
    WindowState *windowState;
};

////////////////////////////////////////////////////////////////////////
#endif	// GAMESTATE_H
////////////////////////////////////////////////////////////////////////