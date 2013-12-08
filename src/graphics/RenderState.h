/*////////////////////////////////////////////////////////
 * File:        RenderState.h
 * Author:      Blankycan
 * Date:        2013-09-04
/////////////////////////////////////// © Blankycan 2013 */
#ifndef RENDERSTATE_H
#define RENDERSTATE_H
///////////////////////////////////////////////////////////
#include "os.h"
///////////////////////////////////////////////////////////
#if defined (WINDOWS)
	#include "../GL/glew.h"
#endif
///////////////////////////////////////////////////////////
//#include "MathLibrary.h"
//#include "Mesh.h"
//class Mesh;
///////////////////////////////////////////////////////////


struct RenderState{
	RenderState(){
		/*modelMatrix.initIdentity();
		viewMatrix.initIdentity();
		projectionMatrix.initIdentity();*/

		handleModelMatrix =
		handleViewMatix =
		handleProjectionMatrix = 
		handleVisualMode = 
		handleTexture =
		handleColor = -1;

		vertexArrayObjects =
		vertexBufferObjects =
		textureBufferObjects =
		normalBufferObjects = NULL;
        
        dt = 0.f;
        
        renderAABB = 
        renderOutline = false;
	}

	/*Matrix4f modelMatrix;
	Matrix4f viewMatrix;
	Matrix4f projectionMatrix;
*/
	GLuint handleModelMatrix;
	GLuint handleViewMatix;
	GLuint handleProjectionMatrix;
	GLuint handleVisualMode;
	GLuint handleTexture;
	GLuint handleColor;

	/* Vertex array object array */
	GLuint *vertexArrayObjects;
	/* Vertex buffer object array */
	GLuint *vertexBufferObjects;
	/* Texture buffer object array */
	GLuint *textureBufferObjects;
	/* Normal buffer object array */
	GLuint *normalBufferObjects;
    
    /* Delta time */
    float dt;
    
    /* Render AABB */
    bool renderAABB;
    /* Render outline on Rigid Bodies */
    bool renderOutline;
};

///////////////////////////////////////////////////////////
#endif  /* RENDERSTATE_H */