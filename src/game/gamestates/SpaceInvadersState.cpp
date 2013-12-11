/* /////////////////////////////////////////////////////////////////////
//  File:       SpaceInvadersState.cpp
//  Author      Blankycan
// Copyright 2013 Blankycan
///////////////////////////////////////////////////////////////////// */
#include "SpaceInvadersState.h"
// Std & General includes
#if defined (LINUX)
    #include <cstdlib>
    #include <cmath>
#elif defined (WINDOWS)
    #include <winuser.rh>
#endif
#include <iostream>
#include <unistd.h>
// Application includes
#include "GraphicsManager.h"
#include "ShaderManager.h"
#include "InputManager.h"
#include "MeshMaker.h"
#include "ApplicationSettings.h"
////////////////////////////////////////////////////////////////////////

SpaceInvadersState::SpaceInvadersState(WindowState *windowState) : GameState("Physics Test", windowState){
	renderGrid = true;
    
    srand(time(NULL));

	Shader *shader = shaderMan->GetShader(SHADER_NORMAL);

	float xRatio = appSettings->xRatio;
	float yRatio = appSettings->yRatio;
	
	float width = ((float)appSettings->gameWidth / (float)appSettings->width);// * appSettings->xGameRatio;
	float height = ((float)appSettings->gameHeight / (float)appSettings->height);// * appSettings->yGameRatio;
	print("line width: " << width << ", line height: " << height);
    // Create horizontal lines
	meshMaker->Clear();
	lineXId = meshMaker->GetFreeMeshIndex();
	meshMaker->AddVertexPoint(-width, 0.f);
	meshMaker->AddVertexPoint( width, 0.f);
	meshMaker->AddVertexPoint(-width, 0.f);
	meshMaker->MakeMesh(lineXId);
	// Create vertical lines
	meshMaker->Clear();
	lineYId = meshMaker->GetFreeMeshIndex();
	meshMaker->AddVertexPoint(0.f, -height);
	meshMaker->AddVertexPoint(0.f,  height);
	meshMaker->AddVertexPoint(0.f, -height);
	meshMaker->MakeMesh(lineYId);

	// Setup the camera
    Vertex3f position(0.f, 0.f, 10.f);
    Vertex3f rotation(0.f, 0.f, 0.f);
    camera = new Camera(position, rotation);
}
SpaceInvadersState::~SpaceInvadersState(){
	meshMaker->DeleteMesh(lineXId);
	meshMaker->DeleteMesh(lineYId);
}

/*
########  ######## ##    ## ########  ######## ########  
##     ## ##       ###   ## ##     ## ##       ##     ## 
##     ## ##       ####  ## ##     ## ##       ##     ## 
########  ######   ## ## ## ##     ## ######   ########  
##   ##   ##       ##  #### ##     ## ##       ##   ##   
##    ##  ##       ##   ### ##     ## ##       ##    ##  
##     ## ######## ##    ## ########  ######## ##     ## 
*/
void SpaceInvadersState::Render(RenderState* renderState)
{
	// Apply the camera transformation
	ApplyCamera(renderState);

	Shader *shader = shaderMan->GetShader(SHADER_NORMAL);

    // Apply renderState settings
    //renderState->renderAABB = this->renderAABB;
    //renderState->renderOutline = this->renderOutline;

    // Render the grid
	if(renderGrid)
		RenderGrid(renderState);

	glUseProgram(shader->program);
    
    /*RigidBody **objects = physics->GetObjects();
    int amountObjects = physics->AmountObjects();
    for(int i = 0; i < amountObjects; ++i){
        if(objects[i])
            objects[i]->Render(renderState);
    }*/
    
	//PrintSentence(renderState, "Made by Blankycan", Vector2f(1.5f * 16.f * (float)windowState->GetWindow()->GetXPixel(), -4.5f * 16.f * (float)windowState->GetWindow()->GetYPixel()));

    
	glUseProgram(shader->program);
   
   
	glUseProgram(0);
}


/*
##     ## ########  ########     ###    ######## ######## 
##     ## ##     ## ##     ##   ## ##      ##    ##       
##     ## ##     ## ##     ##  ##   ##     ##    ##       
##     ## ########  ##     ## ##     ##    ##    ######   
##     ## ##        ##     ## #########    ##    ##       
##     ## ##        ##     ## ##     ##    ##    ##       
 #######  ##        ########  ##     ##    ##    ######## 
 */
void SpaceInvadersState::Update(float dt){
	// Camera transformation
	Vertex3f trans;
	
	// Speed
	float speed = 0.1f;
	if(input->IsKey(KEY::Shift))	// Shift
		speed *= 5.f;

	// Check control and Rotation
    bool move = false;
	bool control = false;
	bool rotation = false;
	if(input->IsKey(KEY::Control)){	// Control
		control = rotation = true;
        speed *= 0.5f;
    }

	// Camera movement
	if(input->IsKey(KEY::W)){	// Up
        Vertex3f vertex(0.f, speed, 0.f);
        trans += vertex;
        move = true;
	}
    
	if(input->IsKey(KEY::S)){	// Down
        Vertex3f vertex(0.f, -speed, 0.f);
        trans += vertex;
        move = true;
	}
	if(input->IsKey(KEY::A)){	// Left
        Vertex3f vertex(-speed, 0.f, 0.f);
		trans += vertex;
        move = true;
    }
	if(input->IsKey(KEY::D)){	// Right
        Vertex3f vertex(speed, 0.f, 0.f);
		trans += vertex;
        move = true;
    }
    
	/*if(input->IsKey(KEY::E)){	// Forward
        Vertex3f vertex(0.f, 0.f, -speed);
        trans += vertex;
        move = true;
    }
	if(input->IsKey(KEY::Q)){	// Backward
        Vertex3f vertex(0.f, 0.f, speed);
        trans += vertex;
        move = true;
    }*/

    if(move)
    {
        //renderRay = false;
        if(!rotation)
            camera->Move(trans);
        else
            camera->Rotate(trans);
    }
}
/*
##    ## ######## ##    ## 
##   ##  ##        ##  ##  
##  ##   ##         ####   
#####    ######      ##    
##  ##   ##          ##    
##   ##  ##          ##    
##    ## ########    ##    
*/
void SpaceInvadersState::HandleKey(bool* keys)
{
	// Check if control is pressed
	bool control = false;
	if(input->IsKey(KEY::Control))	// Control
		control = true;
	
	// Toggle grid
	if(input->IsKey(KEY::G) && control){
		input->SetKey(KEY::G, false);
		renderGrid = !renderGrid;
	}
	
	// If HOME key is pressed, reset view
	if(input->IsKey(KEY::Home)){
		input->SetKey(KEY::Home, false);
        Vertex3f position;//(3.f, 6.f, 13.f);
        Vertex3f rotation;//(PI / 16.f, 0.f, -PI / 8.f);
        camera->SetPosition(position);
		camera->SetRotation(rotation);
		camera->SetZoom(1.f);
	}
	
}

/*
##     ##  #######  ##     ##  ######  ######## 
###   ### ##     ## ##     ## ##    ## ##       
#### #### ##     ## ##     ## ##       ##       
## ### ## ##     ## ##     ##  ######  ######   
##     ## ##     ## ##     ##       ## ##       
##     ## ##     ## ##     ## ##    ## ##       
##     ##  #######   #######   ######  ######## 
*/
void SpaceInvadersState::HandleMouseWheel(int delta)
{
	camera->Zoom(float(delta) / 10.f);
}

#if defined (LINUX)
void SpaceInvadersState::HandleMouse(int xPos, int yPos, XButtonEvent button)
{
    // Left/middle/right mouse button pressed, not released
    if((button.button >= 1 && button.button <= 3) && !(button.state & Button1Mask || button.state & Button2Mask || button.state & Button3Mask))
    {
        // Picking
        // http://www.antongerdelan.net/opengl/raycasting.html

    }
}
#elif defined (WINDOWS)
void SpaceInvadersState::HandleMouse(int xPos, int yPos, WPARAM wParam)
{

}
#endif

/*
 ######   ########  #### ########  
##    ##  ##     ##  ##  ##     ## 
##        ##     ##  ##  ##     ## 
##   #### ########   ##  ##     ## 
##    ##  ##   ##    ##  ##     ## 
##    ##  ##    ##   ##  ##     ## 
 ######   ##     ## #### ########  
 */
void SpaceInvadersState::RenderGrid(RenderState *renderState){
	RenderState oldRenderState = *renderState;
	/*
	tile 16x16
	height 40, = 640px
	width 60 = 960px
	*/

	Shader *shader = shaderMan->GetShader(SHADER_NORMAL);

	// Go into wireframe mode
	glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

	glUseProgram(shader->program);
    /*
    // Start with the x-axis lines
    renderState->modelMatrix.initTranslation(0.f, ((float)appSettings->gameHeight / (float)appSettings->height), 0.f);
    glUniformMatrix4fv(renderState->handleModelMatrix, 1, GL_FALSE, renderState->modelMatrix.getContentColumnWise());
	graphics->meshes[lineXId]->Render(renderState);

    renderState->modelMatrix.initTranslation(0.f, -((float)appSettings->gameHeight / (float)appSettings->height), 0.f);
    glUniformMatrix4fv(renderState->handleModelMatrix, 1, GL_FALSE, renderState->modelMatrix.getContentColumnWise());
	graphics->meshes[lineXId]->Render(renderState);

	// Then do the y-axis lines, but rotate them to fit at z-grid
    renderState->modelMatrix.initTranslation(-((float)appSettings->gameWidth / (float)appSettings->width), 0.f, 0.f);
    glUniformMatrix4fv(renderState->handleModelMatrix, 1, GL_FALSE, renderState->modelMatrix.getContentColumnWise());
	graphics->meshes[lineYId]->Render(renderState);

    renderState->modelMatrix.initTranslation(((float)appSettings->gameWidth / (float)appSettings->width), 0.f, 0.f);
    glUniformMatrix4fv(renderState->handleModelMatrix, 1, GL_FALSE, renderState->modelMatrix.getContentColumnWise());
	graphics->meshes[lineYId]->Render(renderState);
    */

    // Start with the x-axis lines
    renderState->modelMatrix.initTranslation(0.f, ((float)appSettings->gameHeight / (float)appSettings->height), 0.f);

    for(int i = 0; i < 41; ++i)
    {
        glUniformMatrix4fv(renderState->handleModelMatrix, 1, GL_FALSE, renderState->modelMatrix.getContentColumnWise());
    	if(i == 0 || i == 40 || i%10 != 0)
        	graphics->meshes[lineXId]->Render(renderState);
        renderState->modelMatrix.translate(0.f, -(float)appSettings->yPixel * 16.f , 0.f);
    }
  
    // Then do the y-axis lines, but rotate them to fit at z-grid
    renderState->modelMatrix.initTranslation(((float)appSettings->gameWidth / (float)appSettings->width), 0.f, 0.f);
    
    for(int i = 0; i < 61; ++i)
    {
        glUniformMatrix4fv(renderState->handleModelMatrix, 1, GL_FALSE, renderState->modelMatrix.getContentColumnWise());
    	if(i == 0 || i == 60 || i%10 != 0)
    		graphics->meshes[lineYId]->Render(renderState);
        renderState->modelMatrix.translate(-(float)appSettings->xPixel * 16.f, 0.f, 0.f);
    }
    

    
	glUseProgram(0);

	// Go back to normal mode
	glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );

	*renderState = oldRenderState;
}
