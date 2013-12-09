/* /////////////////////////////////////////////////////////////////////
//  File:       MeshMaker.h
//  Author      Blankycan
// Copyright 2013 Blankycan
///////////////////////////////////////////////////////////////////// */
#ifndef MESHMAKER_H
#define MESHMAKER_H
////////////////////////////////////////////////////////////////////////
// Application includes
#include "MathLibrary.h"
#include "Mesh.h"
#include "GraphicsManager.h"
////////////////////////////////////////////////////////////////////////
#define MAX_POINTS 10
#define MISC_MESH_ID_START 32
////////////////////////////////////////////////////////////////////////

/*  MeshMaker
 * Can crate simple convex polygons 
 */
class MeshMaker{
public:
	/* Returns the singleton instance */
	static MeshMaker* Instance();
	/* Destructor, clears any left-over data */
	~MeshMaker();
	/* Clears all entered information, so a new mesh can be created */
	void Clear();
	/* Just clears all uv information */
	void ClearUvs();

	/* Add a vertex point to the mesh to be made */
	void AddVertexPoint(float x, float y);
	/* Add a vertex and uv point to the mesh to be made */
	void AddVertexPoint(float x, float y, float u, float v);
	/* Add a vertex point to the mesh to be made */
	void AddVertexPoint(float *xy);
	/* Add a vertex and uv point to the mesh to be made */
	void AddVertexPoint(float *xy, float *uv);
	/* Add a vertex point to the mesh to be made */
	void AddVertexPoint(Vertex2f vertex);
	/* Add a vertex and uv point to the mesh to be made */
	void AddVertexPoint(Vertex2f vertex, Vertex2f uv);

	/* Add a uv point to the mesh to be made */
	void AddUvPoint(float u, float v);
	/* Add a uv point to the mesh to be made */
	void AddUvPoint(float *uv);
	/* Add a uv point to the mesh to be made */
	void AddUvPoint(Vertex2f uv);

	/* Buffers the data into a mesh */
	void MakeMesh(GLuint id);
	/* Creates tiles */
	void Tilify( int textureIndex, int **tileArray, int tileSize );
	/* Sets the color of a mesh */
	void SetColor(GLuint id, float r, float g, float b, float a = 1.0f);
	/* Sets the color of a mesh */
	void SetColor(GLuint id, const Vector4f& color);
	/* Gives a mesh a texture */
	void SetTexture( GLuint id, GLuint textureId );
	/* Returns an index for a free mesh, -1 if none */
	int GetFreeMeshIndex();
	/* Returns a free index for the VAO, -1 if none */
	int GetFreeVaoIndex();
	/* Returns a free index for the VBO, -1 if none */
	int GetFreeVboIndex();
	/* Returns a free index for the TBO, -1 if none */
	int GetFreeTboIndex();
	/* Returns a free index for the NBO, -1 if none */
	int GetFreeNboIndex();
	/* Returns a free index for a texture, -1 if none */
	int GetFreeTextureIndex();
	/* Deletes specified mesh */
	void DeleteMesh(GLuint id);
    /* Makes a copy of a mesh, using same graphics, specify owner if it's an AABB */
    GLuint GetNewMeshFrom(GLuint meshID, Mesh *owner = NULL);

private:
	/* Private constructor */
	MeshMaker();
	/* Adds the vertex to the mesh */
	void AddVertexToMesh(Vertex2f vertex);
	/* Adds the vertex and uv to the mesh */
	void AddVertexToMesh(Vertex2f vertex, Vertex2f uv);
	/* Adds the uv to the mesh */
	void AddUvToMesh(Vertex2f uv);
	/* Vertices */
	Vertex2f* points[MAX_POINTS];
	/* UV coordinates */
	Vertex2f* uvs[MAX_POINTS];
	/* Amount of vertices */
	int point;
	/* Amount of uv coordinates */
	int uv;
	/* Index of current vertex array object */
	int vertexArrayIndex;
	/* Index of current vertex buffer object */
	int vertexBufferIndex;
	/* Index of current texture buffer object */
	int textureBufferIndex;
    /* Bounding box */
    GLuint boundingBoxId;
};

////////////////////////////////////////////////////////////////////////
#define meshMaker MeshMaker::Instance()
#endif	// MESHMAKER_H
////////////////////////////////////////////////////////////////////////