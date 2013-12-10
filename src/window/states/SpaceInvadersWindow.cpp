/* /////////////////////////////////////////////////////////////////////
//  File:       SpaceInvadersWindow.cpp
//  Author      Blankycan
// Copyright 2013 Blankycan
///////////////////////////////////////////////////////////////////// */
#include "SpaceInvadersWindow.h"
// Std & General includes
#include <stdlib.h>
#include <cmath>
// Application includes
#include "GraphicsManager.h"
#include "ShaderManager.h"
#include "SpaceInvadersState.h"
#include "ApplicationSettings.h"
////////////////////////////////////////////////////////////////////////

SpaceInvadersWindow::SpaceInvadersWindow(WindowHandler *window) : WindowState(window)
{
    
}

SpaceInvadersWindow::~SpaceInvadersWindow()
{
    
}

void SpaceInvadersWindow::Initialize()
{
    GetUniformLocations();
    
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glFrontFace(GL_CCW);
	glCullFace(GL_FRONT_AND_BACK);
	glClearDepth(1.0f);
	glClearColor(.0f, .0f, .0f, 1.0f);
    
	   /* 
	    float xRatio = window->GetXRatio();
		float yRatio = window->GetYRatio();
		// Create horizontal lines
		meshMaker->Clear();
		lineHorizontalId = meshMaker->GetFreeMeshIndex();
		meshMaker->AddVertexPoint(-xRatio, 0.f);
		meshMaker->AddVertexPoint( xRatio, 0.f);
		meshMaker->AddVertexPoint(-xRatio, 0.f);
		meshMaker->MakeMesh(lineHorizontalId);
		// Create vertical lines
		meshMaker->Clear();
		lineVerticalId = meshMaker->GetFreeMeshIndex();
		meshMaker->AddVertexPoint(0.f, -yRatio);
		meshMaker->AddVertexPoint(0.f,  yRatio);
		meshMaker->AddVertexPoint(0.f, -yRatio);
		meshMaker->MakeMesh(lineVerticalId);
	    */
    game->ChangeGameState(new SpaceInvadersState(this));
}

void SpaceInvadersWindow::Resize(int width, int height)
{
	glViewport(0, 0, width, height);

	// Game aspect ratio
	int gameWidth = appSettings->gameWidth;
	int gameHeight = appSettings->gameHeight;
	
	float xGameRatio = appSettings->xGameRatio;
	float yGameRatio = appSettings->yGameRatio;
	if(gameWidth > gameHeight)
		xGameRatio = float(gameWidth) / float(gameHeight);
	else if(gameWidth < gameHeight)
		yGameRatio = float(gameHeight) / float(gameWidth);

	// Screen aspect ratio
	float xRatio = 1.0f;
	float yRatio = 1.0f;
	if(width > height)
		xRatio = float(width) / float(height);
	else if(width < height)
		yRatio = float(height) / float(width);
	
	// Scale game screen to application screen
	float nxa = (float)width/(float)gameWidth;
	float nya = (float)height/(float)gameHeight;
	float scale = (nxa <= nya)? nxa : nya;
	// Update the game screen
	gameWidth = int((float)gameWidth * scale);
	gameHeight = int((float)gameHeight * scale);

	// Calculate pixel-size
	appSettings->xPixel = ((1.0 / (double)appSettings->xGameRatio) / (double)gameWidth) * 2.0;
	appSettings->yPixel = ((1.0 / (double)appSettings->yGameRatio) / (double)gameHeight) * 2.0;
	appSettings->minPixel = (appSettings->xPixel <= appSettings->yPixel)? appSettings->xPixel : appSettings->yPixel;

	// Apply settings
	appSettings->width = width;
	appSettings->height = height;
	appSettings->xRatio = xRatio;
	appSettings->yRatio = yRatio;
	appSettings->gameWidth = gameWidth;
	appSettings->gameHeight = gameHeight;
	appSettings->xGameRatio = xGameRatio;
	appSettings->yGameRatio = yGameRatio;

	print("width: " << appSettings->width << ", height: " << appSettings->height);
	print("gameWidth: " << appSettings->gameWidth << ", gameHeight: " << appSettings->gameHeight);
    print("xRatio: " << appSettings->xRatio << ", yRatio: " << appSettings->yRatio);
    print("xPixel: " << appSettings->xPixel << ", yPixel: " << appSettings->yPixel);

	//renderState.projectionMatrix.initProjectionOtherPerspective(-window->GetXRatio(), window->GetXRatio(), -window->GetYRatio(), window->GetYRatio(), -16.0f, 16.f);
	    //renderState.projectionMatrix.initProjectionPerspective(-window->GetXRatio(), window->GetXRatio(), -window->GetYRatio(), window->GetYRatio(), -10.0f, 100.f);
	renderState.projectionMatrix.initProjectionOrthogonal(-window->GetXRatio(), window->GetXRatio(), -window->GetYRatio(), window->GetYRatio(), -16.f, 16.f);
	if(shaderMan->Initialized())
	{
		glUseProgram(shaderMan->GetShader(SHADER_NORMAL)->program);
        UpdateUniformValues();
		glUseProgram(0);
	}
}

void SpaceInvadersWindow::Render(float dt)
{
    // Clear the Screen and the Depth buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
	// Take a copy of the render state
	RenderState oldState = renderState;

	// Update Camera Position and update uniform MVP
	Shader* shader = shaderMan->GetShader(SHADER_NORMAL);
	glUseProgram(shader->program);
	// Set view matrix to zero
	renderState.viewMatrix.initTranslation(0.f, 0.f, 0.f);
	UpdateUniformValues();
	renderState.vertexArrayObjects = graphics->vertexArrayObjects;
	renderState.vertexBufferObjects = graphics->vertexBufferObjects;
	renderState.textureBufferObjects = graphics->textureBufferObjects;
	renderState.normalBufferObjects = graphics->normalBufferObjects;
    // Set variables in the render state
    renderState.dt = dt;
	glUseProgram(0);
    
	// Render the Game State
	GameState *gameState = game->GetGameState();
    if(gameState)
        gameState->Render(&renderState);
    else
        print("No gamestate!");
    
	// Revert render state
	renderState = oldState;
     
}

void SpaceInvadersWindow::GetUniformLocations()
{
	Shader* shader = shaderMan->GetShader(SHADER_NORMAL);
	if(!shader)
	{
		printl("Shader is NULL", 1);
		return;
	}

	// Get uniform location
	renderState.handleProjectionMatrix = glGetUniformLocation(shader->program, "projectionMatrix");
	if(renderState.handleProjectionMatrix == -1) print("- Uniform 'projectionMatrix' inactive.");

	renderState.handleViewMatix = glGetUniformLocation(shader->program, "viewMatrix");
	if(renderState.handleViewMatix == -1) print("- Uniform 'viewMatrix' inactive.");

	renderState.handleModelMatrix = glGetUniformLocation(shader->program, "modelMatrix");
	if(renderState.handleModelMatrix == -1) print("- Uniform 'modelMatrix' inactive.");

	renderState.handleVisualMode = glGetUniformLocation(shader->program, "in_visualMode");
	if(renderState.handleVisualMode == -1) print("- Uniform 'in_visualMode' inactive.");

	renderState.handleTexture = glGetUniformLocation(shader->program, "in_texture");
	if(renderState.handleTexture == -1) print("- Uniform 'in_texture' inactive.");

	renderState.handleColor = glGetUniformLocation(shader->program, "in_color");
	if(renderState.handleColor == -1) print("- Uniform 'in_color' inactive.");
}

void SpaceInvadersWindow::UpdateUniformValues()
{
	if(renderState.handleProjectionMatrix != -1) glUniformMatrix4fv(renderState.handleProjectionMatrix, 1, GL_FALSE, renderState.projectionMatrix.getContentColumnWise());
	if(renderState.handleViewMatix != -1) glUniformMatrix4fv(renderState.handleViewMatix, 1, GL_FALSE, renderState.viewMatrix.getContentColumnWise());
	if(renderState.handleModelMatrix != -1) glUniformMatrix4fv(renderState.handleModelMatrix, 1, GL_FALSE, renderState.modelMatrix.getContentColumnWise());
	if(renderState.handleVisualMode != -1) glUniform1i(renderState.handleVisualMode, GLuint(0));
	if(renderState.handleTexture != -1) glUniform1i(renderState.handleTexture, GLuint(0));
	if(renderState.handleColor != -1) glUniform4f(renderState.handleColor, 1.f, 1.f, 0.f, 1.f);
}
