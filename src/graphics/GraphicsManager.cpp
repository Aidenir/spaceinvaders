#include "GraphicsManager.h"
#include "Global.h"

GraphicsManager::GraphicsManager()
{

}

GraphicsManager::~GraphicsManager()
{

}

GraphicsManager * GraphicsManager::Instance()
{
	static GraphicsManager instance;
	return &instance;
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
        /*static bool first = true;
        if(first){
            first = false;
            // Initialize the ShaderManager
            print("\n* Initializing ShaderManager..");
            if(!shaderMan->Initialize()){
                print("- ShaderManager failed to initialize!");
                return false;
            }
            print("ShaderManager initialized.");

            /*
            // Assign values to uniforms
            print("\n* Assigning uniforms..");
            Shader* shader = shaderMan->GetShader(SHADER_NORMAL);
            glUseProgram(shader->program);
            UpdateUniformValues();
            glUseProgram(0);
             */
        //}
        
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