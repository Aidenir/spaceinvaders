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
#include "Mesh.h"
////////////////////////////////////////////////////////////////////////
#define MAX_WINDOWS     10
#define MAX_MESHES		4096
#define MAX_TEXTURES	512
#define MAX_VBOS		4096
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
	/** Initializes the manager */
	bool Initialize();
	/**	Deletes the OpenGL window at index. */
	void DeleteGLWindow(int index);
	/**	Updates the GraphicsManager, calls all rendering function for all windows, render all their states. */
	void Render(float dt);
	/* Function that collects the handles to the shaders uniforms */
	void GetUniformLocations();
	
    /// Windows
    WindowHandler *windows[MAX_WINDOWS];
	// Meshes
	Mesh *meshes[MAX_MESHES];
	// Textures
	Texture *textures[MAX_TEXTURES];
	// Vertex array object array.
	GLuint vertexArrayObjects[MAX_VBOS];
	// Vertex buffer object array.
	GLuint vertexBufferObjects[MAX_VBOS];
	// Texture buffer object array.
	GLuint textureBufferObjects[MAX_VBOS];
	// Normal buffer object array.
	GLuint normalBufferObjects[MAX_VBOS];
private:
	/**	Private constructor. */
	GraphicsManager();
	
	/// Boolean whether manager is initialized
	bool initialized;
};

////////////////////////////////////////////////////////////////////////
#define graphics GraphicsManager::Instance()
#endif	//GRAPHICSMANAGER_H
////////////////////////////////////////////////////////////////////////