/* /////////////////////////////////////////////////////////////////////
//	File:		SpaceShip.cpp
//	Author		Blankycan
// Copyright 2013 Blankycan
///////////////////////////////////////////////////////////////////// */
#include "SpaceShip.h"
// Application includes
#include "MeshMaker.h"
#include "ApplicationSettings.h"
////////////////////////////////////////////////////////////////////////

SpaceShip::SpaceShip(GLuint meshId)
{
	this->meshId = meshId;

	float xPixel = appSettings->xPixel;
	float yPixel = appSettings->yPixel;

	meshMaker->Clear();
    laserID = meshMaker->GetFreeMeshIndex();
    meshMaker->AddVertexPoint(-xPixel * 4.f, yPixel * 8.f);
    meshMaker->AddVertexPoint(-xPixel * 4.f,-yPixel * 8.f);
    meshMaker->AddVertexPoint( xPixel * 4.f,-yPixel * 8.f);
    meshMaker->AddVertexPoint( xPixel * 4.f, yPixel * 8.f);
	meshMaker->AddUvPoint(0, 1);
	meshMaker->AddUvPoint(0, 0);
	meshMaker->AddUvPoint(1, 0);
	meshMaker->AddUvPoint(1, 1);
    meshMaker->MakeMesh(laserID);
    // Texture
    laserTexID = meshMaker->GetFreeTextureIndex();
    graphics->textures[laserTexID] = new Texture("laser_00.png");
    meshMaker->SetTexture(laserID, laserTexID);

    laserAmount = 0;
    for(int i = 0; i < MAX_LASERS; ++i)
    	lasers[i] = NULL;

    fireVelocity = Vector2f(0.f, 0.88f);
}
SpaceShip::~SpaceShip()
{

}

void SpaceShip::Fire()
{
	if(laserAmount < MAX_LASERS)
		lasers[laserAmount++] = new Laser(laserID, laserTexID, pos, fireVelocity);
}

void SpaceShip::Render(RenderState *renderState)
{
	RenderState oldRenderState = *renderState;

	// Render all lasers
	for(int i = 0; i < laserAmount; ++i)
	{
		Laser *laser = lasers[i];
		renderState->modelMatrix.initTranslation(laser->pos[X], laser->pos[Y], 2.f);
	    glUniformMatrix4fv(renderState->handleModelMatrix, 1, GL_FALSE, renderState->modelMatrix.getContentColumnWise());
		graphics->meshes[laser->meshID]->Render(renderState);
	}

	renderState->modelMatrix.initTranslation(pos[X], pos[Y], 5.f);
    glUniformMatrix4fv(renderState->handleModelMatrix, 1, GL_FALSE, renderState->modelMatrix.getContentColumnWise());
	graphics->meshes[meshId]->Render(renderState);

	*renderState = oldRenderState;
}

void SpaceShip::Update(float dt)
{
	for(int i = 0; i < laserAmount; ++i)
	{
		lasers[i]->pos += lasers[i]->vel * dt;
		if(lasers[i]->pos[Y] > appSettings->yRatio)
		{
			delete lasers[i];
			lasers[i--] = lasers[--laserAmount];
			lasers[laserAmount] = NULL;
		}
	}
}