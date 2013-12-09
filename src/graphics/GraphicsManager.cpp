/* /////////////////////////////////////////////////////////////////////
//  File:       GraphicsManager.cpp
//  Author      Blankycan
// Copyright 2013 Blankycan
///////////////////////////////////////////////////////////////////// */
#include "GraphicsManager.h"
// Application includes
#include "Global.h"
#include "ShaderManager.h"
////////////////////////////////////////////////////////////////////////

GraphicsManager::GraphicsManager()
{
    initialized = false;
    for(int i = 0; i < MAX_VBOS; ++i){
        vertexArrayObjects[i] = NULL;
        vertexBufferObjects[i] = NULL;
        textureBufferObjects[i] = NULL;
        normalBufferObjects[i] = NULL;
    }
    for(int i = 0; i < MAX_MESHES; ++i)
        meshes[i] = NULL;
    for(int i = 0; i < MAX_TEXTURES; ++i)
        textures[i] = NULL;
    for(int i = 0; i < MAX_WINDOWS; ++i)
        windows[i] = NULL;
}

GraphicsManager::~GraphicsManager()
{
    for(int i = 0; i < MAX_VBOS; ++i){
        if(vertexArrayObjects[i]){
            glDeleteVertexArrays(1, &vertexArrayObjects[i]);
            vertexArrayObjects[i] = NULL;
        }
        if(vertexBufferObjects[i]){
            glDeleteBuffers(1, &vertexBufferObjects[i]);
            vertexBufferObjects[i] = NULL;
        }
        if(textureBufferObjects[i]){
            glDeleteBuffers(1, &textureBufferObjects[i]);
            textureBufferObjects[i] = NULL;
        }
        if(normalBufferObjects[i]){
            glDeleteBuffers(1, &normalBufferObjects[i]);
            normalBufferObjects[i] = NULL;
        }
    }
    for(int i = 0; i < MAX_MESHES; ++i){
        if(meshes[i]){
            delete meshes[i];
            meshes[i] = NULL;
        }
    }
    for(int i = 0; i < MAX_TEXTURES; ++i){
        if(textures[i]){
            delete textures[i];
            textures[i] = NULL;
        }
    }
}

GraphicsManager * GraphicsManager::Instance()
{
	static GraphicsManager instance;
	return &instance;
}

bool GraphicsManager::Initialize()
{
    initialized = true;
    return true;
}

WindowHandler * GraphicsManager::CreateGLWindow(int x, int y, int width, int height, char *windowTitle)
{
    // Try to see if there is an empty slot for a new window
    for(int i = 0; i < MAX_WINDOWS; ++i){
        if(windows[i])
            continue;
        
        // We found a free window slot!
        windows[i] = new WindowHandler(i);
    
        // Create the new Window
        if(!windows[i]->CreateWindow(x, y, width, height, windowTitle)){
            print("Failed to create window!");
            return NULL;
        }
        print("Window created.");

        // Setup OpenGL
        if(!windows[i]->SetupGL()){
            print("Failed to setup OpenGL!");
            return NULL;
        }
        print("OpenGL setup succeeded.");

        // Start the event handler
        if(!windows[i]->RegisterForEvents()){
            print("Failed to register for events!");
            return NULL;
        }
        print("Window registered for events.");

        // If this was the first window to be created, we should initialize ShaderManager
        static bool first = true;
        if(first)
        {
            first = false;
            // Initialize the ShaderManager
            print("\n* Initializing ShaderManager..");
            if(!shaderMan->Initialize()){
                print("- ShaderManager failed to initialize!");
                return false;
            }
            print("ShaderManager initialized.");
        }
        
        return windows[i];
    }
    print("Too many windows already, could not create another.");
    return NULL;
}
void GraphicsManager::DeleteGLWindow(int index)
{
    // Make sure there is a window
    if(index < 0 || index >= MAX_WINDOWS || !windows[index])
        return;
    
    delete windows[index];
    windows[index] = NULL;
	/*
    if(engineSettings->fullscreen){
		ChangeDisplaySettings(NULL, 0);
		ShowCursor(true);
	}
	// Do we have a Rendering Context
	if(hRC){
		// Release it
		if(!wglMakeCurrent(NULL, NULL)){
			print("- Release of DC and RC failed.");
		}
		// Delete the RC
		if(!wglDeleteContext(hRC)){
			print("- Release Rendering Context failed.");
		}
		hRC = NULL;
	}
	// Can we release the Device Context
	if(hDC){
		if(!ReleaseDC(hWnd, hDC)){
			print("- Release Device Context failed.");
		}
		hDC = NULL;
	}
	if(!DestroyWindow(hWnd)){
		print("- Failed to destroy window.");
	}
	// Unregister class
	if(!UnregisterClass(ClassName, hInstance)){
		print("- Could not unregister class.");
	}
	hInstance = NULL;
    */
}

void GraphicsManager::Render(float dt)
{
    // Check if we have encountered any errors
    int error = glGetError();
    if(error != 0)
        print("- GL ERROR: " << error); 
    
    // Render all windows
    for(int i = 0; i < MAX_WINDOWS; ++i){
        if(windows[i])
            windows[i]->Render(dt);
    }
}

void GraphicsManager::GetUniformLocations()
{
    for(int i = 0; i < MAX_WINDOWS; ++i)
    {
        if(!windows[i])
            continue;
        WindowState *windowState = windows[i]->GetWindowState();
        if(windowState)
            windowState->GetUniformLocations();
    }
}

void GraphicsManager::SetFullscreen(bool fullscreen, int screenWidth, int screenHeight)
{
    printl("Fullscreen not implemented yet.", 1)
}