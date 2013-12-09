/* /////////////////////////////////////////////////////////////////////
//	File:		InputManager.cpp
//	Author		Blankycan
// Copyright 2013 Blankycan
///////////////////////////////////////////////////////////////////// */
#include "InputManager.h"
// Application includes
#include "Global.h"
#include "GraphicsManager.h"
////////////////////////////////////////////////////////////////////////

InputManager* InputManager::Instance(){
	static InputManager instance;
	return &instance;
}

InputManager::InputManager(){
	initialized = false;
	keys = new bool[MAX_KEYS];
	for(int i = 0; i < MAX_KEYS; ++i)
		keys[i] = false;
    for(int i = 0; i < MAX_COMMAND_LENGTH; ++i)
		command[i] = '\0';
}
InputManager::~InputManager(){
	if(keys)
		delete[] keys;
	keys = NULL;
}

bool InputManager::Initialize(){

	initialized = true;
	return true;
}

#if defined (LINUX)
void InputManager::KeyDown(int keyCode){
	// Make sure the pressed key is supported
	if(keyCode < 0 || keyCode >= KEY::KEY_AMOUNT){
		print("- Unsupported key");
		return;
	}

	keys[keyCode] = true;

	// Let the gamestate handle the key down action
	GameState* gameState = game->GetGameState();
	if(gameState)
		gameState->HandleKey(keys);
}

void InputManager::KeyUp(int keyCode){
	// Make sure the pressed key is supported
	if(keyCode < 0 || keyCode >= KEY::KEY_AMOUNT){
		print("- Unsupported key");
		return;
	}
	
	keys[keyCode] = false;

	// Let the current gamestate handle the key up action
	GameState* gameState = game->GetGameState();
	if(gameState)
		gameState->HandleKey(keys);
}

void InputManager::InputChar( char keyCode ){
	// Handle writing
	HandleWriting(keyCode);
}

void InputManager::HandleMouse( int xPos, int yPos, XButtonEvent button )
{
	GameState* gameState = game->GetGameState();
	if(gameState)
		gameState->HandleMouse(xPos, yPos, button);
}
#elif defined (WINDOWS)
void InputManager::KeyDown(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
	// Make sure the pressed key is supported
	if(wParam >= MAX_KEYS){
		print("- Unsupported key");
		return;
	}

	keys[wParam] = true;

	// Let the gamestate handle the key down action
	GameState* gameState = game->GetGameState();
	if(gameState)
		gameState->HandleKey(keys);
}

void InputManager::KeyUp(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
	// Make sure the pressed key is supported
	if(wParam >= MAX_KEYS){
		print("- Unsupported key");
		return;
	}
	
	keys[wParam] = false;

	// Let the current gamestate handle the key up action
	GameState* gameState = game->GetGameState();
	if(gameState)
		gameState->HandleKey(keys);
}

void InputManager::InputChar( WPARAM wParam ){
	// Handle writing
	HandleWriting(wParam);
}

void InputManager::HandleMouse( int xPos, int yPos, WPARAM wParam )
{
	GameState* gameState = game->GetGameState();
	if(gameState)
		gameState->HandleMouse(xPos, yPos, wParam);
}
#endif

void InputManager::HandleMouseWheel( int delta )
{
	GameState* gameState = game->GetGameState();
	if(gameState)
		gameState->HandleMouseWheel(delta);
}

void InputManager::HandleWriting( char keyCode )
{
	/*if(keyCode == 91){
		print("Windows key!");
		return;
	}*/

	bool writing = game->GetGameState()->IsWriting();
	// Check if ENTER/RETURN is pressed, then toggle writing
	if(keyCode == KEY::Enter){
		// Toggle writing
		writing = !writing;
		game->GetGameState()->SetWriting(writing);

		if(writing){
			print("\n* Enter command:");
		}
		else{
			print("\n* Parsing command..");
			ParseCommand();
		}
	}
	// Check if TAB is presses, then show available commands
	else if(writing && keyCode == KEY::Tab){
		ShowAvailableCommands();
	}
	// Check if we're trying to erase using BACKSPACE
	else if(keyCode == KEY::Backspace){
		int i = 0;
		// Go to end of string
		while(command[i] != '\0')
			i++;
		// Then remove last char
		if(i != 0)
			command[i-1] = '\0';
		// Then print shiet
		char buff[MAX_COMMAND_LENGTH];
		strcpy(buff, ">> ");
		strcat(buff, &command[0]);
		strcat(buff, "\n");
		print(buff);
	}
	// Else try writing it to the command
	else if(writing){
		
		const char charStr = (char)keyCode;
		strncat(command, &charStr, 1);
		
		char buff[MAX_COMMAND_LENGTH];
		strcpy(buff, ">> ");
		strcat(buff, &command[0]);
		strcat(buff, "\n");
		print(buff);
	}
	
}

void InputManager::ParseCommand()
{
	int size = 1;
	char pCmd[MAX_COMMAND_ARGUMENTS][MAX_COMMAND_LENGTH] = { 0 };
	int i = 0, count = 0;

	// Split the command into multiple arrays
	while(command[i] != '\0'){
		if(command[i] == ' '){
			++size;
			++i;
			count = 0;
			// Make sure we're not using to many arguments
			if(size > MAX_COMMAND_ARGUMENTS){
				print("- Max arguments reached!");
				break;
			}
			continue;
		}
		pCmd[size-1][count++] = command[i++];
	}

	// Check the command
	if(size == 2 && strcmp(ToUppercase(pCmd[0]), "FULLSCREEN") == 0){
		print("Command: Toggle Fullscreen");
		if(strcmp(pCmd[1], "ON") == 0){
			print("Toggle Fullscreen ON");
			//engineSettings->fullscreen = true;
			//graphics->SetFullscreen(engineSettings->fullscreen, 1366, 768);
		}
		else if(strcmp(pCmd[1], "OFF") == 0){
			print("Toggle Fullscreen OFF");
			//engineSettings->fullscreen = false;
			//graphics->SetFullscreen(engineSettings->fullscreen, 800, 600);
		}
		else
			print("- Invalid second argument!");
	}
	else if(size == 3 && strcmp(pCmd[0], "SET") == 0){
		if((strcmp(ToUppercase(pCmd[1]), "SIZE") == 0 || strcmp(ToUppercase(pCmd[1]), "RESOLUTION") == 0)){
			char res[2][4] = { 0 };
			int j = 0, r = 1, s = 3;
			while(pCmd[2][j] != '\0'){
				if(j > 9){
					print("- Invalid resolution, should be 'DDDDxDDDD' (Digit 0-9)");
					return;
				}
				j++;
			}
			for(int k = j-1; j > 0; --k){
				if(pCmd[2][k] == 'X'){
					--r;
					s = 3;
					continue;
				}
				if(s < 0)
					break;
				int digit = ((int)pCmd[2][k])-48;
				res[r][s--] = (digit < 0 || digit > 9)? 0 : digit;
			}
			int resWidth = 0, resHeight = 0;
			int mod = 1000;
			for(int k = 0; k < 4; ++k){
				resWidth += res[0][k] * mod;
				resHeight += res[1][k] * mod;
				mod /= 10;
			}

			if(resWidth == 0 || resHeight == 0){
				print("- Invalid resolution, should be 0000x0000 (0-9)");
			}
			else{
				print("Setting resolution: " << resWidth << "x" << resHeight);
				//graphics->SetFullscreen(engineSettings->fullscreen, resWidth, resHeight);
			}
		}
	}
	else if(size == 1 && (strcmp(ToUppercase(pCmd[0]), "EXIT") == 0 || strcmp(ToUppercase(pCmd[0]), "QUIT") == 0)){
		print("Command: Quit/Exit");
		#if defined (LINUX)
		graphics->DeleteGLWindow(0);
		#elif defined (WINDOWS)
		PostQuitMessage(0);
		#endif
	}
	else if(size == 2 && (strcmp(ToUppercase(pCmd[0]), "LOAD") == 0 || strcmp(ToUppercase(pCmd[0]), "READ") == 0)){
		// Trying to load a file
		// Get filename
		char fileName[256];
		strcpy(fileName, pCmd[1]);
		//GLuint meshID = meshMaker->GetFreeMeshIndex();
		//fileLoader->LoadMesh(fileName, meshID);
	}
	else
		print("Command: Unknown");

	const char emptyStr[2] = "";
	strcpy(command, emptyStr);
}

void InputManager::ShowAvailableCommands()
{
	int size = 1;
	char pCmd[MAX_COMMAND_ARGUMENTS][MAX_COMMAND_LENGTH] = { 0 };
	int i = 0, count = 0;

	// Split the command into multiple arrays
	while(command[i] != '\0'){
		if(command[i] == ' '){
			++size;
			++i;
			count = 0;
			// Make sure we're not using to many arguments
			if(size > MAX_COMMAND_ARGUMENTS){
				print("- Max arguments reached!");
				break;
			}
			continue;
		}
		pCmd[size-1][count++] = command[i++];
	}




}

char* InputManager::ToUppercase( char* str ){
	int index = 0;
	while(str[index] != '\0'){
		str[index] = toupper(str[index]);
		++index;
	}
	return str;
}

char* InputManager::ToLowercase( char* str ){
	int index = 0;
	while(str[index] != '\0'){
		str[index] = tolower(str[index]);
		++index;
	}
	return str;
}

bool InputManager::IsDigits(const char* str ){
	int index = 0;
	while(str[index] != '\0'){
		if(!isdigit(str[index]) && !(str[0] != '-' || str[index] != '.' || str[index] != ','))
			return false;
		++index;
	}
	return true;
}

bool InputManager::IsKey(char key)
{
	if(key >= 0 && key < MAX_KEYS)
		return keys[key];
	else
		return false;
}
void InputManager::SetKey(char key, bool state)
{
	if(key >= 0 && key < MAX_KEYS)
		keys[key] = state;
}