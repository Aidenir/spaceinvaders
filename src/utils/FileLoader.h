/* /////////////////////////////////////////////////////////////////////
//  File:       FileLoader.h
//  Author      Blankycan
// Copyright 2013 Blankycan
///////////////////////////////////////////////////////////////////// */
#ifndef FILELOADER_H
#define FILELOADER_H
////////////////////////////////////////////////////////////////////////
// Std & General includes
#include <string>
#include <vector>
// Application includes
#include "Manager.h"
#include "MathLibrary.h"
#include "Mesh.h"
////////////////////////////////////////////////////////////////////////
#define MESH_DIRECTORY "Meshes/"
////////////////////////////////////////////////////////////////////////

/* Reads data from files */
class FileLoader : public Manager{
public:
	/* Returns singleton instance of the Manager */
	static FileLoader* Instance();
	/* Default destructor */
	~FileLoader();
	/* Initializes the manager */
	bool Initialize();
	/* Returns whether the Manager is initialized successfully */
	bool Initialized();

	/* Load an mesh file, determines what file type it is */
	void LoadMesh(char* fileName, GLuint id, int meshType = MESH_TYPE_NULL);

private:
	/* Default constructor */
	FileLoader();
	/* Loads an OBJ file */
	bool LoadObj(char* filePath);
	/* Read next word */
	void ReadNextWord(char* data, int& cursor, std::string* section);
	/* Skips all chars in data until new line */
	void SkipToNextLine( char *data, int &cursor );
	/* Puts data into buffers */
	void CreateMesh(const std::vector<Vertex3f*>& vertex, const std::vector<Vertex2f*>& uv, const std::vector<Vertex3f*>& normal, const std::vector<unsigned int>& vertexIndices, const std::vector<unsigned int>& uvIndices, const std::vector<unsigned int>& normalIndices, const std::vector<unsigned int>& polycount);
	/* True if Manager is successfully initialized */
	bool initialized;
    /* Current Mesh ID to be created */
    GLuint meshID;
    /* Current mesh type */
    int meshType;
};

////////////////////////////////////////////////////////////////////////
#define fileLoader FileLoader::Instance()
#endif  // FILELOADER_H
////////////////////////////////////////////////////////////////////////