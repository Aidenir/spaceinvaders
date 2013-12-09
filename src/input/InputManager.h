/* /////////////////////////////////////////////////////////////////////
//	File:		InputManager.h
//	Author		Blankycan
// Copyright 2013 Blankycan
///////////////////////////////////////////////////////////////////// */
#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H
////////////////////////////////////////////////////////////////////////
// OS incnlude
#include "os.h"
// Std & General includes
#if defined(LINUX)
	#include <X11/Xlib.h>
#endif
// Application includes
#include "GameManager.h"
#include "Keys.h"
////////////////////////////////////////////////////////////////////////
#define MAX_KEYS                KEY::KEY_AMOUNT
#define MAX_COMMAND_LENGTH      256
#define MAX_COMMAND_ARGUMENTS	3
////////////////////////////////////////////////////////////////////////

/**	InputManager
	Class that can pre-handle the input and passes it on to current gamestate.
*/
class InputManager
{
public:
	/* Static instance function, to get a copy of the singleton */
	static InputManager* Instance();
	/* Managers default de-constructor */
	~InputManager();
	/* Initialized the Manager, needs to be executed before usage of Manager */
	bool Initialize();
#if defined (LINUX)
	/* Handle keys being pressed */
	void KeyDown(int keyCode);
	/* Handle keys being released */
	void KeyUp(int keyCode);
	/* Handles keys being pressed for writing */
	void InputChar( char keyCode );
	/* Let's current/global state handle mouse */
	void HandleMouse( int xPos, int yPos, XButtonEvent button );
#elif defined (WINDOWS)
	/* Handle keys being pressed */
	void KeyDown(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	/* Handle keys being released */
	void KeyUp(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	/* Handles keys being pressed for writing */
	void InputChar( WPARAM wParam );
	/* Let's current/global state handle mouse */
	void HandleMouse( int xPos, int yPos, WPARAM wParam );
#endif
	/* Let's current/global state handle the mouse wheel */
	void HandleMouseWheel( int delta );
	/* Converts a char array to uppercase */
	char* ToUppercase(char* str);
	/* Converts a char array to lowercase */
	char* ToLowercase(char* str);
	/* Checks if a char array is valid digits only */
	bool IsDigits(const char* str);

	/* Returns state of key */
	bool IsKey(char key);
	/* Sets state of key */
	void SetKey(char key, bool state);
	/* Returns mouse position */


private:
	/* Managers default constructor */
	InputManager();
	void HandleWriting( char keyCode );
	void ParseCommand();
	void ShowAvailableCommands();
	
	/// Boolean whether manager is initialized
	bool initialized;
	/* Key's states */
	bool* keys;
	/* Written text */
	char command[MAX_COMMAND_LENGTH];
};

////////////////////////////////////////////////////////////////////////
#define input InputManager::Instance()
#endif	// INPUTMANAGER_H
////////////////////////////////////////////////////////////////////////