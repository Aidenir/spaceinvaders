/* /////////////////////////////////////////////////////////////////////
//  File:       SpaceInvadersState.h
//  Author      Blankycan
// Copyright 2013 Blankycan
///////////////////////////////////////////////////////////////////// */
#ifndef SPACEINVADERSSTATE_H
#define SPACEINVADERSSTATE_H
////////////////////////////////////////////////////////////////////////
// OS include
#include "os.h"
// Std & General includes
#if defined (LINUX)
#elif defined (WINDOWS)
    #include <Windows.h>			// Windows
    #define GLEW_STATIC
    #include "include/GL/glew.h"
    #include <gl/GL.h>				// OpenGL32
#endif
// Application includes
#include "GameManager.h"
#include "GameState.h"
////////////////////////////////////////////////////////////////////////

/*  PhysicsTest
 * Test state for Physics
 */
class SpaceInvadersState : public GameState{
public:
	SpaceInvadersState(WindowState *windowState);
	~SpaceInvadersState();
    /* Renders the scene */
	void Render(RenderState *renderState);
    /* Update, updates all physic bodies and reacts to some input */
    void Update(float dt);
    /* Called when a key-action happens */
	void HandleKey(bool* keys);
    /* Called when a mouse-wheel-action happens */
	void HandleMouseWheel(int delta);
#if defined (LINUX)
    /* Called when a mouse-button/move-action happens */
	void HandleMouse(int xPos, int yPos, XButtonEvent button);
#elif defined (WINDOWS)
    /* Called when a mouse-button/move-action happens */
	void HandleMouse(int xPos, int yPos, WPARAM wParam);
#endif
    
private:
    /* Renders the grid */
    void RenderGrid(RenderState *renderState);
    void RenderOtherGrid(RenderState *renderState);
	GLuint lineXId;
	GLuint lineYId;
	bool renderGrid;
};

////////////////////////////////////////////////////////////////////////
#endif  // SPACEINVADERSSTATE_H
////////////////////////////////////////////////////////////////////////