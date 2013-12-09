/* /////////////////////////////////////////////////////////////////////
//	File:		GameManager.h
//	Author		Blankycan
// Copyright 2013 Blankycan
///////////////////////////////////////////////////////////////////// */
#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
////////////////////////////////////////////////////////////////////////
// OS include
#include "os.h"
// Std & General includes
#if defined (WINDOWS)
	#include <Windows.h>
	#define GLEW_STATIC
	#include "../GL/glew.h"
	#include <GL/gl.h>
#endif
// Application includes
#include "GameState.h"
////////////////////////////////////////////////////////////////////////

/**	GameManager
	Handle gamestates.
*/
class GameManager 
{
public:
	/* Returns instance of the Manager */
	static GameManager* Instance();
	/* Managers default destructor */
	~GameManager();
	/* Initializes the Manager, needs to be executed before usage of Manager */
	bool Initialize();
    /* Updates current game state, takes delta time */
	void Update(float dt);

	/* Returns current gamestate */
	GameState* GetGameState();
	/* Returns next gamestate */
	GameState* GetNextGameState();
	/* Returns previous gamestate */
	GameState* GetLastGameState();
	/* Changes GameState at the start of next frame */
	void ChangeGameState(GameState* gameState);

private:
	/* Managers default constructor */
	GameManager();
	/* Sets the game state */
	void SetGameState();

	/// Boolean whether manager is initialized
	bool initialized;
	/* Current active Game State */
	GameState* currentGameState;
	/* Last game state */
	GameState* lastGameState;
	/* Next game state */
	GameState* nextGameState;

};

////////////////////////////////////////////////////////////////////////
#define game GameManager::Instance()
#endif	// GAMEMANAGER_H
////////////////////////////////////////////////////////////////////////