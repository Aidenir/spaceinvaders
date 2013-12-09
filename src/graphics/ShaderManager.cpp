/* /////////////////////////////////////////////////////////////////////
//	File:		ShaderManager.cpp
//	Author		Blankycan
// Copyright 2013 Blankycan
///////////////////////////////////////////////////////////////////// */
#include "ShaderManager.h"
// Std & General includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Application includes
#include "GraphicsManager.h"
//#include "../EngineSettings.h"
////////////////////////////////////////////////////////////////////////

ShaderManager* ShaderManager::Instance(){
	static ShaderManager instance;
	return &instance;
}

ShaderManager::ShaderManager(){
	initialized = false;
	
}

ShaderManager::~ShaderManager(){
	for(int i = 0; i < SHADER_AMOUNT; ++i){
		if(shaders[i].vertexShader != -1 && shaders[i].program < SHADER_AMOUNT){
			glDetachShader(shaders[i].program, shaders[i].vertexShader);
			glDeleteShader(shaders[i].vertexShader);
			shaders->vertexShader = NULL;
		}
		if(shaders[i].tesselationShader != -1 && shaders[i].program < SHADER_AMOUNT){
			glDetachShader(shaders[i].program, shaders[i].tesselationShader);
			glDeleteShader(shaders[i].tesselationShader);
			shaders->tesselationShader = NULL;
		}
		if(shaders[i].geometryShader != -1 && shaders[i].program < SHADER_AMOUNT){
			glDetachShader(shaders[i].program, shaders[i].geometryShader);
			glDeleteShader(shaders[i].geometryShader);
			shaders->geometryShader = NULL;
		}
		if(shaders[i].fragmentShader != -1 && shaders[i].program < SHADER_AMOUNT){
			glDetachShader(shaders[i].program, shaders[i].fragmentShader);
			glDeleteShader(shaders[i].fragmentShader);
			shaders->fragmentShader = NULL;
		}
		if(shaders[i].program < SHADER_AMOUNT){
			glDeleteProgram(shaders[i].program);
			shaders[i].program = NULL;
		}
	}
}

bool ShaderManager::Initialize(){
	// Create the shaders
	print("\n* Initializing Shaders..")
	if(!InitializeShaders()){
		print("- Failed to Initialize Shaders!");
		return false;
	}

	initialized = true;
	return true;
}

bool ShaderManager::InitializeShaders(){
	// Get the GL version number
	char glVersionNumber[10];
	//char glMajor[4], glMinor[4];
	//itoa((int)engineSettings->glVersion, glMajor, 10);
	//itoa((int)((engineSettings->glVersion - (float)((int)engineSettings->glVersion)) * 10.0f + 0.5f), glMinor, 10);
	strcpy(glVersionNumber, "_");
	strcat(glVersionNumber, "3");
	strcat(glVersionNumber, "_");
	strcat(glVersionNumber, "3");

	// Allocate for all shaders
	shaders = new Shader[SHADER_AMOUNT];
	ShaderEmuns shaderType;
	bool success = true;
	char shaderFileVert[64];
	char shaderFileTess[64];
	char shaderFileGeom[64];
	char shaderFileFrag[64];
	char* vertFileEnd = {".vert"};
	char* tessFileEnd = {".tess"};
	char* geomFileEnd = {".geom"};
	char* fragFileEnd = {".frag"};

	// The Normal Shader
	for(int i = 0; i < SHADER_AMOUNT; ++i){
		Shader* shader = &shaders[i];
		shader->vertFile = new char[64];
		shader->fragFile = new char[64];

		// Create the file name without extensions
		char shaderfile[64];
		strcpy(shaderfile, SHADER_DIRECTORY);
		strcat(shaderfile, "normal");
		strcat(shaderfile, glVersionNumber);

		// Fragment Shader
		strcpy(shaderFileVert, shaderfile);
		strcat(shaderFileVert, vertFileEnd);
		strcpy(shader->vertFile, shaderFileVert);

		// Vertex Shader
		strcpy(shaderFileFrag, shaderfile);
		strcat(shaderFileFrag, fragFileEnd);
		strcpy(shader->fragFile, shaderFileFrag);

		success = CreateShader(shader);
		if(!success){
			print("- Failed to create shader number " << i);
			return false;
		}
	}

	// Reset the program
	glUseProgram(0);
	return success;
}

bool ShaderManager::CreateProgram(Shader* shader){
	// Delete old program if there is one
	if(shader->program){
		glDeleteProgram(shader->program);
	}

	// Create the new Shader program
	shader->program = glCreateProgram();
	if(shader->vertFile)
		glAttachShader(shader->program, shader->vertexShader);
	if(shader->tessFile)
		glAttachShader(shader->program, shader->tesselationShader);
	if(shader->geomFile)
		glAttachShader(shader->program, shader->geometryShader);
	if(shader->fragFile)
		glAttachShader(shader->program, shader->fragmentShader);

	// Specify attribute locations before linking program
	glBindAttribLocation(shader->program, 0, "in_Position");
	glBindAttribLocation(shader->program, 1, "in_uvCoord");
	glBindAttribLocation(shader->program, 2, "in_Normal");

	// We must link the program after binding attributes
	glLinkProgram(shader->program);

	// Get the info log and check for errors
	int status = NULL;
	glGetProgramiv(shader->program, GL_LINK_STATUS, &status);
	if(status == GL_FALSE){
		char errorMsg[256];
		int length;
		glGetProgramInfoLog(shader->program, 256, &length, errorMsg);
		print(errorMsg);
		return false;
	}
	
	// Set the current shader as active
	glUseProgram(shader->program);

	// Check so the attributes
	print("* Checking shader attributes..")
	if(glGetAttribLocation(shader->program, "in_Position") == -1)
		print("'in_Position' not used.");
	if(glGetAttribLocation(shader->program, "in_uvCoord") == -1)
		print("'in_uvCoord' not used.");
	if(glGetAttribLocation(shader->program, "in_Normal") == -1)
		print("'in_Normal' not used.");

	// Update the uniform locations
	graphics->GetUniformLocations();

	// Stop using current shader
	glUseProgram(0);

	return true;
}

bool ShaderManager::CreateShader(Shader* shader){
	if(!CompileShaders(shader))
		return false;

	if(!CreateProgram(shader))
		return false;

	return true;
}

char* ShaderManager::TextFileRead(char* fn){
	FILE* fp;
	char* content = NULL;
	int count = 0;

	if(fn != NULL){ // Is filename okay?
		fp = fopen(fn, "rt");

		if(fp != NULL){ // Is file okay?
			fseek(fp, 0, SEEK_END);
			count = ftell(fp);
			rewind(fp);

			if(count > 0){ // Did we read something?
				content = (char*)malloc(sizeof(char) * (count+1));
				count = fread(content, sizeof(char), count, fp);
				content[count] = '\0';
			}
			fclose(fp);
		}
	}
	return content;
}

void ShaderManager::ReCompileShader( Shader* shader )
{
	Shader &cpy = *shader;

	print("\n* Recompiling Shader..");
	if(!CreateShader(shader)){
		print("- Compiling failed, reverting to old shader.");
		*shader = cpy;
	}
}

bool ShaderManager::CompileShaders(Shader* shader){
	// Detach the shaders before creating new and recompiling them
	if(shader->vertexShader != -1){
		glDetachShader(shader->program, shader->vertexShader);
		glDeleteShader(shader->vertexShader);
	}
	if(shader->tesselationShader != -1){
		glDetachShader(shader->program, shader->tesselationShader);
		glDeleteShader(shader->tesselationShader);
	}
	if(shader->geometryShader != -1){
		glDetachShader(shader->program, shader->geometryShader);
		glDeleteShader(shader->geometryShader);
	}
	if(shader->fragmentShader != -1){
		glDetachShader(shader->program, shader->fragmentShader);
		glDeleteShader(shader->fragmentShader);
	}

	// Initialize the shaders
	if(shader->vertFile){
		shader->vertexShader = glCreateShader(GL_VERTEX_SHADER);
		if(glGetError() == GL_INVALID_ENUM)
			print("- Invalid shader type, Vertex.");
	}
	if(shader->tessFile){
		shader->tesselationShader = glCreateShader(GL_TESS_CONTROL_SHADER);
		if(glGetError() == GL_INVALID_ENUM)
			print("- Invalid shader type, Tesselation.");
	}
	if(shader->geomFile){
		shader->geometryShader = glCreateShader(GL_GEOMETRY_SHADER);
		if(glGetError() == GL_INVALID_ENUM)
			print("- Invalid shader type, Geometry.");
	}
	if(shader->fragFile){
		shader->fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		if(glGetError() == GL_INVALID_ENUM)
			print("- Invalid shader type, Fragment.");
	}

	// Read the shader source from a file
	char* vs = TextFileRead(shader->vertFile);
	char* ts = TextFileRead(shader->tessFile);
	char* gs = TextFileRead(shader->geomFile);
	char* fs = TextFileRead(shader->fragFile);
	// Check content
	if(!vs && shader->vertFile){
		print("- Error when reading vertex shader file.");
		return false;
	}
	if(!ts && shader->tessFile){
		print("- Error when reading tesselation shader file.");
		return false;
	}
	if(!gs && shader->geomFile){
		print("- Error when reading geometry shader file.");
		return false;
	}
	if(!fs && shader->fragFile){
		print("- Error when reading fragment shader file.");
		return false;
	}
	// Convert the content to fit next function
	const char* vv = vs;
	const char* tt = ts;
	const char* gg = gs;
	const char* ff = fs;
	// Replace the source code in the shader object
	if(vs)	glShaderSource(shader->vertexShader, 1, &vv, NULL);
	if(ts)	glShaderSource(shader->fragmentShader, 1, &tt, NULL);
	if(gs)	glShaderSource(shader->fragmentShader, 1, &gg, NULL);
	if(fs)	glShaderSource(shader->fragmentShader, 1, &ff, NULL);
	// Finally compile the shader
	if(vs)	glCompileShader(shader->vertexShader);
	if(ts)	glCompileShader(shader->tesselationShader);
	if(gs)	glCompileShader(shader->geometryShader);
	if(fs)	glCompileShader(shader->fragmentShader);
	// Empties possible errors
	glGetError();
	// Free memory
	if(vs)	delete vs;
	if(ts)	delete ts;
	if(gs)	delete gs;
	if(fs)	delete fs;
	int status = NULL;

	if(shader->vertexShader != -1){
		print("* Compiling Vertex shader..");
		// Get the info log for the vertex shader
		glGetShaderiv(shader->vertexShader, GL_COMPILE_STATUS, &status);
		// Check if compilation failed
		if(status == GL_FALSE){
			char errorMsg[256];
			int length;
			glGetShaderInfoLog(shader->vertexShader, 256, &length, errorMsg);
			// Write the error message to the compilation log
			print("- Error occured when compiling the vertex shader:\n" << errorMsg);
			// Empties possible errors
			glGetError();
			return false;
		}
		else
			print("Vertex shader compiled successfully!");
	}
	if(shader->tesselationShader != -1){
		print("* Compiling Tesselation shader..");
		// Get the info log for the fragment shader
		glGetShaderiv(shader->tesselationShader, GL_COMPILE_STATUS, &status);
		// Check if compilation failed
		if(status == GL_FALSE){
			char errorMsg[256];
			int length;
			glGetShaderInfoLog(shader->tesselationShader, 256, &length, errorMsg);
			// Write the error message to the compilation log
			print("- Error occured when compiling the tesselation shader:\n" << errorMsg);
			// Empties possible errors
			glGetError();
			return false;
		}
		else
			print("Tesselation shader compiled successfully!");
	}
	if(shader->geometryShader != -1){
		print("* Compiling Geometry shader..");
		// Get the info log for the fragment shader
		glGetShaderiv(shader->geometryShader, GL_COMPILE_STATUS, &status);
		// Check if compilation failed
		if(status == GL_FALSE){
			char errorMsg[256];
			int length;
			glGetShaderInfoLog(shader->geometryShader, 256, &length, errorMsg);
			// Write the error message to the compilation log
			print("- Error occured when compiling the geometry shader:\n" << errorMsg);
			// Empties possible errors
			glGetError();
			return false;
		}
		else
			print("Geometry shader compiled successfully!");
	}
	if(shader->fragmentShader != -1){
		print("* Compiling Fragment shader..");
		// Get the info log for the fragment shader
		glGetShaderiv(shader->fragmentShader, GL_COMPILE_STATUS, &status);
		// Check if compilation failed
		if(status == GL_FALSE){
			char errorMsg[256];
			int length;
			glGetShaderInfoLog(shader->fragmentShader, 256, &length, errorMsg);
			// Write the error message to the compilation log
			print("- Error occured when compiling the fragment shader:\n" << errorMsg);
			// Empties possible errors
			glGetError();
			return false;
		}
		else
			print("Fragment shader compiled successfully!");
	}
	return true;
}

Shader* ShaderManager::GetShader( ShaderEmuns shaderType )
{
	if(shaderType >= SHADER_AMOUNT || shaderType < 0)
		return NULL;
	return &shaders[shaderType];
}
