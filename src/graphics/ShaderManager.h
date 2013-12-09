/* /////////////////////////////////////////////////////////////////////
//	File:		ShaderManager.h
//	Author		Blankycan
// Copyright 2013 Blankycan
///////////////////////////////////////////////////////////////////// */
#ifndef SHADERMANAGER_H
#define SHADERMANAGER_H
////////////////////////////////////////////////////////////////////////
// Application includes
#include "Global.h"
#include "Shader.h"
////////////////////////////////////////////////////////////////////////
#define SHADER_DIRECTORY "shaders/"
enum ShaderEmuns{
	SHADER_NORMAL,

	SHADER_AMOUNT
};
////////////////////////////////////////////////////////////////////////

/**	ShaderManager
	Manager that handles all the shaders.
*/
class ShaderManager
{
public:
	/* Returns singleton instance of the manager */
	static ShaderManager* Instance();
	/* Default destructor */
	~ShaderManager();
	/* Initializes the manager */
	bool Initialize();
	/* Initializes and creates the shaders */
	bool InitializeShaders();
	/* Creates a program */
	bool CreateProgram(Shader* shader);
	/* Crate the shaders vertex/fragment shaders */
	bool CreateShader(Shader* shader);
	/* Recompiles a shader, if compilation fails, it will not change */
	void ReCompileShader(Shader* shader);
	/* Returns a pointer to requested shader, NULL is invalid ShaderEnum */
	Shader* GetShader( ShaderEmuns shaderType );
	/**	Returns whether ShaderManager has been initialized. */
	bool Initialized() { return initialized; }

private:
	/* Default constructor */
	ShaderManager();
	/* Compiles the shaders */
	bool CompileShaders(Shader* shader);
	/* Reads in a shader text file */
	char* TextFileRead(char* fn);

	/// Boolean whether manager is initialized
	bool initialized;
	/* Array with all the shaders */
	Shader* shaders;
};

////////////////////////////////////////////////////////////////////////
#define shaderMan ShaderManager::Instance()
#endif	// SHADERMANAGER_H
////////////////////////////////////////////////////////////////////////