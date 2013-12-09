/* /////////////////////////////////////////////////////////////////////
//  File:       MeshMaker.cpp
//  Author      Blankycan
// Copyright 2013 Blankycan
///////////////////////////////////////////////////////////////////// */
#include "MeshMaker.h"
// Application includes
#include "FileLoader.h"
#include "ApplicationSettings.h"
#include "Global.h"
////////////////////////////////////////////////////////////////////////

MeshMaker* MeshMaker::Instance(){
	static MeshMaker instance;
	return &instance;
}
MeshMaker::MeshMaker(){
	for(int i = 0; i < MAX_POINTS; ++i){
		points[i] = NULL;
		uvs[i] = NULL;
	}
	point = 0;
	uv = 0;
	vertexArrayIndex = -1;
	vertexBufferIndex = -1;
	textureBufferIndex = -1;
}
MeshMaker::~MeshMaker(){
	for(int i = 0; i < MAX_POINTS; ++i){
		if(points[i])
			delete points[i];
		points[i] = NULL;
		if(uvs[i])
			delete uvs[i];
		uvs[i] = NULL;
	}
	point = 0;
	uv = 0;
	vertexArrayIndex = -1;
	vertexBufferIndex = -1;
	textureBufferIndex = -1;
}
void MeshMaker::Clear(){
	for(int i = 0; i < MAX_POINTS; ++i){
		if(points[i])
			delete points[i];
		points[i] = NULL;
		if(uvs[i])
			delete uvs[i];
		uvs[i] = NULL;
	}
	point = 0;
	uv = 0;
	vertexArrayIndex = -1;
	vertexBufferIndex = -1;
	textureBufferIndex = -1;
}
void MeshMaker::ClearUvs(){
	for(int i = 0; i < MAX_POINTS; ++i){
		if(uvs[i])
			delete uvs[i];
		uvs[i] = NULL;
	}
	uv = 0;
	//vertexArrayIndex = -1;
	//vertexBufferIndex = -1;
	textureBufferIndex = -1;
}

void MeshMaker::AddVertexPoint(float x, float y){
    Vertex2f newVert(x, y);
	AddVertexToMesh(newVert);
}
void MeshMaker::AddVertexPoint(float x, float y, float u, float v){
    Vertex2f vert1(x, y);
    Vertex2f vert2(u, v);
	AddVertexToMesh(vert1, vert2);
}
void MeshMaker::AddVertexPoint(float *xy){
    Vertex2f newVert(xy[0], xy[1]);
	AddVertexToMesh(newVert);
}
void MeshMaker::AddVertexPoint(float *xy, float *uv){
    Vertex2f vert1(xy[0], xy[1]);
    Vertex2f vert2(uv[0], uv[1]);
	AddVertexToMesh(vert1, vert2);
}
void MeshMaker::AddVertexPoint(Vertex2f vertex){
    Vertex2f newVert(vertex);
	AddVertexToMesh(newVert);
}
void MeshMaker::AddVertexPoint(Vertex2f vertex, Vertex2f uv){
	AddVertexToMesh(vertex, uv);
}

void MeshMaker::AddUvPoint(float u, float v){
    Vertex2f newVert(u, v);
	AddUvToMesh(newVert);
}
void MeshMaker::AddUvPoint(float *uv){
    Vertex2f newVert(uv[0], uv[1]);
	AddUvToMesh(newVert);
}
void MeshMaker::AddUvPoint(Vertex2f uv){
	AddUvToMesh(uv);
}

void MeshMaker::AddVertexToMesh(Vertex2f vertex){
	for(int i = 0; i < MAX_POINTS; ++i){
		if(!points[i]){
			points[i] = new Vertex2f(vertex);
			point++;
			break;
		}
	}
}
void MeshMaker::AddVertexToMesh(Vertex2f vertex, Vertex2f uv){
	for(int i = 0; i < MAX_POINTS; ++i){
		if(!points[i]){
			points[i] = new Vertex2f(vertex);
			point++;
			break;
		}
	}
	for(int i = 0; i < MAX_POINTS; ++i){
		if(!uvs[i]){
			uvs[i] = new Vertex2f(uv);
			this->uv++;
			break;
		}
	}
}
void MeshMaker::AddUvToMesh(Vertex2f uv){
	for(int i = 0; i < MAX_POINTS; ++i){
		if(!uvs[i]){
			uvs[i] = new Vertex2f(uv);
			this->uv++;
			break;
		}
	}
}

void MeshMaker::MakeMesh(GLuint id){
	if(vertexArrayIndex == -1)
		vertexArrayIndex = GetFreeVaoIndex();
	glGenVertexArrays(1, &graphics->vertexArrayObjects[vertexArrayIndex]);

	// Create vertices
	if(this->point && vertexBufferIndex == -1)
	{
		// Get a new vertex buffer object index
		vertexBufferIndex = GetFreeVboIndex();

		int size = (point-2)*3*3; // Triangles * points per triangle * coordinates per point
		float* vertex = new float[size];
		int index = 0;

		// Add the first point for each new triangle
		vertex[index++] = points[0]->coord[0];
		vertex[index++] = points[0]->coord[1];
		vertex[index++] = 0.0f;

		for(int i = 1; i < MAX_POINTS; ++i){
			if(points[i]){ // Add the other points of the triangle
				vertex[index++] = points[i]->coord[0];
				vertex[index++] = points[i]->coord[1];
				vertex[index++] = 0.0f;
			}
			else
				break;
			if(i > 1 && i != (point-1)){// Add the first point for each new triangle
				vertex[index++] = points[0]->coord[0];
				vertex[index++] = points[0]->coord[1];
				vertex[index++] = 0.0f;

				vertex[index++] = points[i]->coord[0];
				vertex[index++] = points[i]->coord[1];
				vertex[index++] = 0.0f;
			}
		}


		glBindVertexArray(graphics->vertexArrayObjects[vertexArrayIndex]);
		glGenBuffers(1, &graphics->vertexBufferObjects[vertexBufferIndex]);

		// Buffer vertex
		glBindBuffer(GL_ARRAY_BUFFER, graphics->vertexBufferObjects[vertexBufferIndex]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * size, vertex, GL_STATIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glBindVertexArray(0);

		delete[] vertex;
	}

	// If there are any UVs
	if(this->uv && textureBufferIndex == -1)
	{
		// Get a new texture buffer object index
		textureBufferIndex = GetFreeTboIndex();

		int size = (this->uv-2)*3*2; // Triangles * points per triangle * coordinates per point
		float* uv = new float[size];
		int index = 0;

		// Add the first point for each new triangle
		uv[index++] = uvs[0]->coord[0];
		uv[index++] = uvs[0]->coord[1];

		for(int i = 1; i < MAX_POINTS; ++i){
			if(uvs[i]){ // Add the other points of the triangle
				uv[index++] = uvs[i]->coord[0];
				uv[index++] = uvs[i]->coord[1];
			}
			else
				break;
			if(i > 1 && i != (this->uv-1)){// Add the first point for each new triangle
				uv[index++] = uvs[0]->coord[0];
				uv[index++] = uvs[0]->coord[1];

				uv[index++] = uvs[i]->coord[0];
				uv[index++] = uvs[i]->coord[1];
			}
		}
		glBindVertexArray(graphics->vertexArrayObjects[vertexArrayIndex]);
		glGenBuffers(1, &graphics->textureBufferObjects[textureBufferIndex]);

		// Buffer vertex
		glBindBuffer(GL_ARRAY_BUFFER, graphics->textureBufferObjects[textureBufferIndex]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * size, uv, GL_STATIC_DRAW);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);
		glBindVertexArray(0);

		delete[] uv;
	}
	// Disable our Vertex Array Object  
	glEnableVertexAttribArray(0);
	graphics->meshes[id] = new Mesh(vertexArrayIndex, vertexBufferIndex, textureBufferIndex, GLuint(-1));
	graphics->meshes[id]->vboVertexCount = (point-2)*3;
}

void MeshMaker::Tilify( int textureIndex, int **tileArray2, int tileSize )
{
	// Make sure the tile size is larger than 0
	if(tileSize <= 0){
		print("- Invalid tile size!");
		return;
	}
	// Check so there is a valid texture at the texture index
	Texture *texture = graphics->textures[textureIndex];
	if(!texture){
		print("- Invalid texture index!");
		return;
	}
	// make some calculations
	int tileWidth = texture->width;
	int tileHeight = texture->height;
	int xTiles = tileWidth / tileSize;
	int yTiles = tileHeight / tileSize;
	float xStep = 1.f / float(xTiles);
	float yStep = 1.f / float(yTiles);

	// Make a tile
	meshMaker->Clear();
	float xSize = tileSize / 2.f * (float)appSettings->xPixel;
	float ySize = tileSize / 2.f * (float)appSettings->yPixel;
    Vertex2f vert1(-xSize, ySize);
    Vertex2f vert2(-xSize,-ySize);
    Vertex2f vert3( xSize,-ySize);
    Vertex2f vert4( xSize, ySize);
	meshMaker->AddVertexPoint(vert1);
	meshMaker->AddVertexPoint(vert2);
	meshMaker->AddVertexPoint(vert3);
	meshMaker->AddVertexPoint(vert4);

	// Then set each individual tiles texture and create it
	int tiles = xTiles * yTiles;
	int *tileArray = new int[tiles];
	for(int i = 0; i < tiles; ++i){
		tileArray[i] = GetFreeMeshIndex();
		ClearUvs();
		float leftX = (i%xTiles)*xStep;
		float rightX = (i%xTiles)*xStep + xStep;
		float topY = 1.f - ((i/yTiles)*yStep);
		float bottomY = 1.f - (((i/yTiles)+1)*yStep);
		meshMaker->AddUvPoint(leftX, topY);
		meshMaker->AddUvPoint(leftX, bottomY);
		meshMaker->AddUvPoint(rightX, bottomY);
		meshMaker->AddUvPoint(rightX, topY);

		meshMaker->MakeMesh(tileArray[i]);
		meshMaker->SetTexture(tileArray[i], textureIndex);
	}
	*tileArray2 = tileArray;
}

void MeshMaker::SetColor(GLuint id, float r, float g, float b, float a){
	graphics->meshes[id]->color = Vector4f(r, g, b, a);
	graphics->meshes[id]->hasColor = true;
}
void MeshMaker::SetColor(GLuint id, const Vector4f& color)
{
    graphics->meshes[id]->color = color;
    graphics->meshes[id]->hasColor = true;
}

void MeshMaker::SetTexture( GLuint id, GLuint textureId )
{
	if(graphics->meshes[id])
		graphics->meshes[id]->textureIndex = textureId;
}

int MeshMaker::GetFreeMeshIndex(){
	for(int i = MISC_MESH_ID_START; i < MAX_MESHES; ++i){
		if(!graphics->meshes[i])
			return i;
	}
	return -1;
}
int MeshMaker::GetFreeVaoIndex(){
	for(int i = 0; i < MAX_MESHES; ++i){
		if(!graphics->vertexArrayObjects[i])
			return i;
	}
}
int MeshMaker::GetFreeVboIndex(){
	for(int i = 0; i < MAX_MESHES; ++i){
		if(!graphics->vertexBufferObjects[i])
			return i;
	}
}
int MeshMaker::GetFreeTboIndex(){
	for(int i = 0; i < MAX_MESHES; ++i){
		if(!graphics->textureBufferObjects[i])
			return i;
	}
}
int MeshMaker::GetFreeNboIndex(){
	for(int i = 0; i < MAX_MESHES; ++i){
		if(!graphics->normalBufferObjects[i])
			return i;
	}
}
int MeshMaker::GetFreeTextureIndex(){
	for(int i = 0; i < MAX_TEXTURES; ++i){
		if(!graphics->textures[i])
			return i;
	}
}

void MeshMaker::DeleteMesh( GLuint id )
{
	if(graphics->meshes[id])
		delete graphics->meshes[id];
	if(graphics->vertexArrayObjects[id] != NULL)
		glDeleteVertexArrays(1, &graphics->vertexArrayObjects[id]);
	if(graphics->vertexBufferObjects[id] != NULL)
		glDeleteBuffers(1, &graphics->vertexBufferObjects[id]);
	if(graphics->textureBufferObjects[id] != NULL)
		glDeleteBuffers(1, &graphics->textureBufferObjects[id]);
	if(graphics->normalBufferObjects[id] != NULL)
		glDeleteBuffers(1, &graphics->normalBufferObjects[id]);
	graphics->meshes[id] = NULL;
}

GLuint MeshMaker::GetNewMeshFrom(GLuint meshID, Mesh *owner)
{
    Mesh *blueprint = graphics->meshes[meshID];
    if(!blueprint)
        return -1;
    GLuint newMeshID = GetFreeMeshIndex();
    if(newMeshID == -1)
        return -1;
    switch(blueprint->GetType())
    {
        case MESH_TYPE_NULL:{
            graphics->meshes[newMeshID] = new Mesh(blueprint->vao, blueprint->vbo, blueprint->tbo, blueprint->nbo);
            break;
        }
    }
    // Common for all
    Mesh *mesh = graphics->meshes[newMeshID];
    mesh->vboVertexCount    = blueprint->vboVertexCount;
    mesh->textureIndex      = blueprint->textureIndex;
    mesh->hasColor          = blueprint->hasColor;
    mesh->color             = blueprint->color;
    return newMeshID;
}