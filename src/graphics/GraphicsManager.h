/* /////////////////////////////////////////////////////////////////////
//	File:		GraphicsManager.h
//	Author		Blankycan
// Copyright 2013 Blankycan
///////////////////////////////////////////////////////////////////// */
#ifndef GRAPHICSMANAGER_H
#define GRAPHICSMANAGER_H
////////////////////////////////////////////////////////////////////////
// Application includes
#include "WindowHandler.h"
////////////////////////////////////////////////////////////////////////
#define MAX_WINDOWS     10
////////////////////////////////////////////////////////////////////////

/**	GraphicsManager
	Handle windows.
*/
class GraphicsManager
{
public:
	/**	Returns instance of the GraphicsManager singleton. */
	static GraphicsManager * Instance();
	/**	Destructor */
	~GraphicsManager();
	/**	Creates a window with OpenGL, returns window or NULL */
	WindowHandler * CreateGLWindow(int x, int y, int width, int height, char *windowTitle);
	/**	Deletes the OpenGL window at index. */
	void DeleteGLWindow(int index);
	/**	Updates the GraphicsManager, calls all rendering function for all windows, render all their states. */
	void Render(float dt);
	
    /// Windows
    WindowHandler *windows[MAX_WINDOWS];
private:
	/**	Private constructor. */
	GraphicsManager();
};

////////////////////////////////////////////////////////////////////////
#define graphics GraphicsManager::Instance()
#endif	//GRAPHICSMANAGER_H
////////////////////////////////////////////////////////////////////////