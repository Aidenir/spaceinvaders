/* /////////////////////////////////////////////////////////////////////
//	File:		Mesh.h
//	Author		Blankycan
// Copyright 2013 Blankycan
///////////////////////////////////////////////////////////////////// */
#ifndef MESH_H
#define MESH_H
////////////////////////////////////////////////////////////////////////
// OS include
#include "os.h"
// Std & General includes
#if defined (LINUX)
	#include <GL/glew.h>
#elif defined (WINDOWS)
	#include <Windows.h>
	#define GLEW_STATIC
	#include "../GL/glew.h"
	#include <GL/gl.h>
#endif
// Application includes
#include "MathLibrary.h"
#include "Texture.h"
#include "RenderState.h"
struct RenderState;
////////////////////////////////////////////////////////////////////////
enum Mesh_Types{
    MESH_TYPE_NULL,
    MESH_TYPE_AABB,
    MESH_TYPE_RIGIDBODY
};
////////////////////////////////////////////////////////////////////////

/**	Mesh
	Base class for a mesh.
*/
class Mesh
{
public:
	/* Default constructor */
	Mesh();
	/* Constructor taking indices to vertex array and buffers */
	Mesh(GLuint vao, GLuint vbo, GLuint tbo, GLuint nbo);
	/* Constructor taking indices to vertex array and buffers, Sets width and height of the mesh also for 2D selection */
	Mesh(GLuint vao, GLuint vbo, GLuint tbo, GLuint nbo, float width, float height);
	/* Default constructor */
	~Mesh();
    /* Returns what type of mesh */
    int GetType() { return type; }
	/* Render the mesh */
	virtual void Render(RenderState* renderState);
    
	/* Amount of vertices */
	GLuint vboVertexCount;
	/* Width and height of the mesh, for selection */
	float width, height, depth;
	/* Mesh color */
	Vector4f color;
	/* Mesh texture's index */
	GLuint textureIndex;
	/* If mesh should have a specific color */
	bool hasColor;
    /* AABB */
    GLuint aabbId;
	/* Vertex Array, and buffers */
	int vao, vbo, tbo, nbo;
    /* If mesh is intersectable */
    bool intersectable;
    
protected:
	/* Name of the mesh */
	char* name;
    /* Type of mesh */
    int type;
};

////////////////////////////////////////////////////////////////////////
#endif	// MESH_H
////////////////////////////////////////////////////////////////////////