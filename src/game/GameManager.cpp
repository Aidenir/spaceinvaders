/* /////////////////////////////////////////////////////////////////////
//	File:		GameManager.cpp
//	Author		Blankycan
// Copyright 2013 Blankycan
///////////////////////////////////////////////////////////////////// */
#include "GameManager.h"
////////////////////////////////////////////////////////////////////////

GameManager* GameManager::Instance(){
	static GameManager instance;
	return &instance;
}

GameManager::GameManager(){
	initialized = false;
	currentGameState = NULL;
	lastGameState = NULL;
	nextGameState = NULL;
}

GameManager::~GameManager(){

}

bool GameManager::Initialize(){

	initialized = true;
	return true;
}

void GameManager::Update(float dt){
	// See if a new gamestate is requested
	if(nextGameState){
		SetGameState();
	}
    // Update physics
    //physics->Update(dt);
    // Update current game-state
	currentGameState->Update(dt);
}

GameState* GameManager::GetGameState(){
	return currentGameState;
}
GameState* GameManager::GetNextGameState(){
	return nextGameState;
}
GameState* GameManager::GetLastGameState(){
	return lastGameState;
}
void GameManager::ChangeGameState(GameState* gameState){
	if(nextGameState)
		delete nextGameState;
    if(!currentGameState){
        nextGameState = NULL;
        currentGameState = gameState;
        return;
    }
	nextGameState = gameState;
}
void GameManager::SetGameState(){
	if(lastGameState)
		delete lastGameState;
	lastGameState = currentGameState;
	currentGameState = nextGameState;
	nextGameState = NULL;
}