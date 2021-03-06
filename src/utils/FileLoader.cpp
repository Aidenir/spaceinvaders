/* /////////////////////////////////////////////////////////////////////
//  File:       FileLoader.cpp
//  Author      Blankycan
// Copyright 2013 Blankycan
///////////////////////////////////////////////////////////////////// */
#include "FileLoader.h"
// Std & General includes
#include <fstream>
#include <sstream>
// Application includes
#include "Global.h"
#include "InputManager.h"
#include "ShaderManager.h"
#include "GraphicsManager.h"
#include "MeshMaker.h"
////////////////////////////////////////////////////////////////////////

FileLoader* FileLoader::Instance(){
	static FileLoader instance;
	return &instance;
}

FileLoader::FileLoader(){
	initialized = false;
	meshID = -1;
    meshType = MESH_TYPE_NULL;
}

FileLoader::~FileLoader(){

}

bool FileLoader::Initialize(){

	initialized = true;
	return true;
}

bool FileLoader::Initialized(){
	return initialized;
}

void FileLoader::LoadMesh(char* fileName, GLuint id, int meshType){
    this->meshID = id;
    this->meshType = meshType;
	// Make sure the filename has a null terminator at the end
	char file[74];
	strcpy(file, fileName);

	// Add the Mesh directory to the filepath
	char filePath[74];
	strcpy(filePath, MESH_DIRECTORY);
	strcat(filePath, fileName);

	// Split the filename by the '.'
	char *split = strtok(file, ".");

	// Get the extension
	split = strtok(NULL, ".");
	input->ToUppercase(split);

	// Check what filetype we're loading
	bool status;
	if(strcmp(split, "OBJ") == 0)
		status = fileLoader->LoadObj(filePath);
	else{
		print("-Unknown file extension.");
        this->meshID = -1;
		return;
	}

	if(status){
		print("File '" << fileName << "' loaded successfully!");
	}
	else{
		print("- File could not be loaded.");
	}
    this->meshID = -1;
}

bool FileLoader::LoadObj( char* filePath ){
	

	// Mesh data
	std::vector<Vertex3f*> vertex;
	std::vector<Vertex2f*> uv;
	std::vector<Vertex3f*> normal;

	// Read data
	unsigned int vertices = 0, uvs = 0, normals = 0, faces = 0;
	std::vector<unsigned int> vertexIndices, uvIndices, normalIndices, polycount;
	char buff[32];
	unsigned int firstVertIndex, firstUvIndex, firstNormIndex;
	unsigned int lastVertIndex, lastUvIndex, lastNormIndex;

	// Get the file open and read the file until the end
	char* data;
	int size;
	std::fstream file(filePath, std::ios::in | std::ios::ate);
	if(file.is_open()){
		// Assume that the file won't be larger than 2GB
		size = (int)file.tellg();
		data = new char[size];
		file.seekg(0, std::ios::beg);
		file.read(data, size);
		file.close();
	}else{
		print("- Faled to open file: " << filePath);
		return false;
	}

	// Read the content of the file
	int cursor = 0;
	while(true){
		// Start with reading the first word
		// Until encounter whitespace, newline or null
		std::string section;
		ReadNextWord(data, cursor, &section);

		// Start with validating the string
		if(section.length() == 0){
			if(cursor < size){
				//SkipToNextLine(data, cursor);
				continue;
			}
			else
				break;
		}

		// Check our current line
		if(strcmp(&section[0], "#") == 0){
			// Skip the whole line
			SkipToNextLine(data, cursor);
			continue;
		}
		else if(strcmp(section.c_str(), "v") == 0){
			Vertex3f* vert = new Vertex3f();
			int i = 0;
			// Read the vertex coords
			while(true){
				std::string coord;
				ReadNextWord(data, cursor, &coord);
				// Check if the coords invalid
				if(coord.length() == 0 || !input->IsDigits(coord.c_str())){
					cursor -= coord.length()+1;
					break;
				}
				else {
                    std::stringstream ss;
                    ss << coord.c_str();
                    ss >> vert->coord[i++];
				}
			}
			// Add the vertex
			vertex.push_back(vert);
			++vertices;
		}
		else if(strcmp(section.c_str(), "vt") == 0){
			Vertex2f* uv_coord = new Vertex2f();
			int i = 0;
			// Read the uv coords
			while(true){
				std::string coord;
				ReadNextWord(data, cursor, &coord);
				// Check if the coords invalid
				if(coord.length() == 0 || !input->IsDigits(coord.c_str())){
					cursor -= coord.length()+1;
					break;
				}
				else {
                    std::stringstream ss;
                    ss << coord.c_str();
                    ss >> uv_coord->coord[i++];
				}
			}
			// Add the uv
			uv.push_back(uv_coord);
			++uvs;
		}
		else if(strcmp(section.c_str(), "vn") == 0){
			Vertex3f* norm = new Vertex3f();
			int i = 0;
			// Read the normal coords
			while(true){
				std::string coord;
				ReadNextWord(data, cursor, &coord);
				// Check if the coords invalid
				if(coord.length() == 0 || !input->IsDigits(coord.c_str())){
					cursor -= coord.length()+1;
					break;
				}
				else {
                    std::stringstream ss;
                    ss << coord.c_str();
                    ss >> norm->coord[i++];
				}
			}
			// Add the normal
			normal.push_back(norm);
			++normals;
		}
		else if(strcmp(section.c_str(), "f") == 0){
			//Vertex3f* element = new Vertex3f();
			int i = 0;
			// Read the face elements
			while(true){
				std::string indices;
				ReadNextWord(data, cursor, &indices);

				// Check if the indices are invalid
				if(indices.length() == 0)
					break;
				if(!isdigit(indices[0])){
					cursor -= indices.length()+1;
					break;
				}

				// Get the string
				strcpy(buff, indices.c_str());

				// Triangulate
				if(i > 3){
					vertexIndices.push_back(firstVertIndex);
					vertexIndices.push_back(lastVertIndex);
					uvIndices.push_back(firstUvIndex);
					uvIndices.push_back(lastUvIndex);
					normalIndices.push_back(firstNormIndex);
					normalIndices.push_back(lastNormIndex);
				}

				// Process each element
				int elem = -1;
				char* element = strtok(buff, "/");

				do{
					elem++;
					// Convert the element to float
					int index ;
                    std::stringstream ss;
                    ss << element;
                    ss >> index;

					// Add index
					switch(elem){
						case 0: // Vertex
							vertexIndices.push_back(index);
							if(i){ lastVertIndex = index; }
							else { firstVertIndex = index;}
							break;
						case 1: // UV
							uvIndices.push_back(index);
							if(i){ lastUvIndex = index; }
							else { firstUvIndex = index;}
							break;
						case 2: // Normal
							normalIndices.push_back(index);
							if(i){ lastNormIndex = index; }
							else { firstNormIndex = index;}
							break;
					}
					element = strtok(NULL, "/");
				} while(element != NULL);
				++i;
			}
			// Write out amount of triangles
			for(int polys = i; polys >= 3; --polys)
				polycount.push_back(3);
			++faces;
		}

		// If we are at end of file
		if(cursor >= size)
			break;
	}

	// Buff the data
	CreateMesh(vertex, uv, normal, vertexIndices, uvIndices, normalIndices, polycount);
	// Create the Mesh
	//Mesh* mesh = new Mesh();
	

	// Cleanup
	delete[] data;
    while(vertex.size() != 0){
        Vertex3f *vert = vertex.back();
        delete vert;
        vertex.pop_back();
    }
    while(uv.size() != 0){
        Vertex2f *vert = uv.back();
        delete vert;
        uv.pop_back();
    }
    while(normal.size() != 0){
        Vertex3f *vert = normal.back();
        delete vert;
        normal.pop_back();
    }

	return true;
}

void FileLoader::ReadNextWord( char* data, int& cursor, std::string* section ){
	int startValue = cursor;
	while( data[cursor] != char(0)	&& data[cursor] != char(10) && data[cursor] != char(13) && data[cursor] != char(32) && data[cursor] != char(12)){
		// Append one char
		section->append(1, data[cursor++]);
	}
	++cursor;
}

void FileLoader::SkipToNextLine( char *data, int &cursor ){
	while(true){
		char tmp = data[cursor++];
		if(data[cursor] == char(0) || data[cursor] == char(10) || data[cursor] == char(13) || data[cursor] == char(12)){
			break;
		}
	}
	++cursor;
}

void FileLoader::CreateMesh(
	const std::vector<Vertex3f*>& vertex,
	const std::vector<Vertex2f*>& uv,
	const std::vector<Vertex3f*>& normal,
	const std::vector<unsigned int>& vertexIndices,
	const std::vector<unsigned int>& uvIndices,
	const std::vector<unsigned int>& normalIndices,
	const std::vector<unsigned int>& polycount)
{
	Shader *shader = shaderMan->GetShader(SHADER_NORMAL);
	glUseProgram(shader->program);

	int totSize = int(vertexIndices.size()) * 3;
	int polSize = int(polycount.size());
	float* vertices = new float[polSize * 3 * 3];
	float* uvs = new float[polSize * 3 * 2];
	float* normals = new float[polSize * 3 * 3];
	unsigned int* indices = new unsigned int[totSize];
	unsigned int vertCount = 0, uvCount = 0, normCount = 0, indCount = 0;

	/*
	for(int i = 0; i < vertexIndices.size(); ++i){
		vertices[vertCount++] = vertex[i].coord[0];
		vertices[vertCount++] = vertex[i].coord[1];
		vertices[vertCount++] = vertex[i].coord[2];
	}
	for(int i = 0; i < uvIndices.size(); ++i){
		uvs[uvCount++] = uv[i].coord[0];
		uvs[uvCount++] = uv[i].coord[1];
	}
	for(int i = 0; i < normalIndices.size(); ++i){
		normals[normCount++] = normal[i].coord[0];
		normals[normCount++] = normal[i].coord[1];
		normals[normCount++] = normal[i].coord[2];
	}
	for(int i = 0; i < ; ++i){
		indices[indCount++] = vertexIndices[i];
	}
	*/
    
	// Reorganize the data
	for(int i = 0; i < polycount.size(); ++i){
		for(int j = 0; j < 3; ++j){
            
			int index   = i*3;
            
            int vInd    = vertexIndices[index + j]-1;
            int tInd    = uvIndices[index + j]-1;
            int nInd    = normalIndices[index + j]-1;
            
			vertices[vertCount++]   = vertex[vInd]->coord[0];
			vertices[vertCount++]   = vertex[vInd]->coord[1];
			vertices[vertCount++]   = vertex[vInd]->coord[2];
			uvs[uvCount++]          = uv[tInd]->coord[0];
			uvs[uvCount++]          = uv[tInd]->coord[1];
			normals[normCount++]    = normal[nInd]->coord[0];
			normals[normCount++]    = normal[nInd]->coord[1];
			normals[normCount++]    = normal[nInd]->coord[2]; 
		}
	}
	for(int i = 0; i < totSize; ++i){
		indices[i] = i;
	}
	

	/*
	indexArraySize = 9;
	indexArray = new unsigned int[indexArraySize];

	unsigned int indices[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
	for(int i = 0; i < indexArraySize; ++i)
		indexArray[i] = indices[i];
		*/
	// First create VAO and bind it
    GLuint vao = meshMaker->GetFreeVaoIndex();
	glGenVertexArrays(1, &graphics->vertexArrayObjects[vao]);
	glBindVertexArray(graphics->vertexArrayObjects[vao]);

	// For each attribute we create a buffer, bind it, fill it and then
	// associate it with an input attribute of the graphics pipeline

	// Position buffer
    GLuint vbo = meshMaker->GetFreeVboIndex();
	glGenBuffers(1, &graphics->vertexBufferObjects[vbo]);
	// Bind the buffer for positions and copy data into buffer
	glBindBuffer(GL_ARRAY_BUFFER, graphics->vertexBufferObjects[vbo]);
	// Feed the buffer
	glBufferData(GL_ARRAY_BUFFER, vertCount * sizeof(float), vertices, GL_STATIC_DRAW);
	// Enable the attribute at that location
	glEnableVertexAttribArray(0);
	// Tell OpenGL what the array contains
	glVertexAttribPointer(0, 3, GL_FLOAT, 0, 0, 0);

	// uvCoord buffer
	GLuint tbo = meshMaker->GetFreeTboIndex();
	glGenBuffers(1, &graphics->textureBufferObjects[tbo]);
	// Bind the buffer for uv coordinates and copy data into buffer
	glBindBuffer(GL_ARRAY_BUFFER, graphics->textureBufferObjects[tbo]);
	// Feed the buffer
	glBufferData(GL_ARRAY_BUFFER, uvCount * sizeof(float), uvs, GL_STATIC_DRAW);
	// Enable the attribute at that location
	glEnableVertexAttribArray(1);
	// Tell OpenGL what the array converttains
	glVertexAttribPointer(1, 2, GL_FLOAT, 0, 0, 0);

	// Normal buffer
	GLuint nbo = meshMaker->GetFreeNboIndex();
	glGenBuffers(1, &graphics->normalBufferObjects[nbo]);
	// Bind the buffer for normals and copy data into buffer
	glBindBuffer(GL_ARRAY_BUFFER, graphics->normalBufferObjects[nbo]);
	// Feed the buffer
	glBufferData(GL_ARRAY_BUFFER, normCount * sizeof(float), normals, GL_STATIC_DRAW);
	// Enable the attribute at that location
	glEnableVertexAttribArray(2);
	// Tell OpenGL what the array contains
	glVertexAttribPointer(2, 3, GL_FLOAT, 0, 0, 0);

    glBindVertexArray(0);
    /*
	// Index buffer
	GLuint bufferIndex;
	glGenBuffers(1, &bufferIndex);
	// Bind buffer for positions and copy data into buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferIndex);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, totSize * sizeof(unsigned int), indices, GL_STATIC_DRAW);
     */
    
    delete[] vertices;
    delete[] uvs;
    delete[] normals;
    
    // Save the mesh information into a mesh
    switch(meshType)
    {
        case MESH_TYPE_NULL:
            graphics->meshes[meshID] = new Mesh(vao, vbo, tbo, nbo);
            break;
    }
    graphics->meshes[meshID]->vboVertexCount = vertCount;
    

	glUseProgram(0);
}