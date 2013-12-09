/* /////////////////////////////////////////////////////////////////////
//	File:		GameState.cpp
//	Author		Blankycan
// Copyright 2013 Blankycan
///////////////////////////////////////////////////////////////////// */
#include "GameState.h"
// Std & General includes
#include <string.h>
// Application includes
#include "ShaderManager.h"
////////////////////////////////////////////////////////////////////////

int GameState::idCount = 0;

GameState::GameState(char* stateName, WindowState *windowState)
{
	// Set the state's name
	strncpy(this->stateName, stateName, MAX_NAME_LENGTH);
	// Set window state
    this->windowState = windowState;
    
	camera = NULL;
}

GameState::~GameState()
{
	if(camera)
		delete camera;
}

void GameState::ApplyCamera(RenderState* renderState)
{
	// Add camera orientation
	if(camera)
	{
		Shader *shader = shaderMan->GetShader(SHADER_NORMAL);
		glUseProgram(shader->program);

		Vector3f front(camera->GetRotation());
		
        /*
		glBegin(GL_LINES);
			glColor3f(1.f, 0.f, 0.f);
			glVertex3f(-camera->GetPositionX(), -camera->GetPositionY(), -camera->GetPositionZ());
			glVertex3f(front.coord[X], front.coord[Y], front.coord[Z]);
        glEnd();
        */
		// Zoom
		renderState->viewMatrix.scale(camera->GetZoom(), camera->GetZoom(), camera->GetZoom());

		// Rotation
		renderState->viewMatrix.rotateX(-camera->GetRotationZ()); //Z
		renderState->viewMatrix.rotateY(-camera->GetRotationX()); //X
		//renderState->viewMatrix.rotateZ(camera->GetRotationY()); //Y

		// Translations
		renderState->viewMatrix.translate(-camera->GetPositionX(), -camera->GetPositionY(), -camera->GetPositionZ());


		// Apply transform
		glUniformMatrix4fv(renderState->handleViewMatix, 1, GL_FALSE, renderState->viewMatrix.getContentColumnWise());

		glUseProgram(NULL);
	}
}