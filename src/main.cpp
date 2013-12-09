/* /////////////////////////////////////////////////////////////////////
//	File:		main.cpp
//	Author		Blankycan
// Copyright 2013 Blankycan
///////////////////////////////////////////////////////////////////// */
// OS include
#include "os.h"
// Std includes
#include <iostream>
// Application includes
#include "Global.h"
#include "Time.h"
#include "Sleep.h"
#include "Location.h"
#include "GraphicsManager.h"
#include "WindowHandler.h"
#include "SpaceInvadersWindow.h"
#include "GameManager.h"
#include "InputManager.h"
#include "FileLoader.h"
////////////////////////////////////////////////////////////////////////

/** MainLoop
    Creates window and runs the main loop.
*/
int MainLoop(int argc, char** argv)
{
	// Set up window resolution
    int windowX = 1024;
    int windowY = 768;
    // Create the main window
    print("* Window.. ");
    WindowHandler *mainWindow = graphics->CreateGLWindow(0, 0, windowX, windowY, "Space Invaders");
    if(!mainWindow){
        print("Failed to create GL Window!");
        return 1;
    }
    print("GL Window Successfully created!\n");
    
    print("Giving window a WindowState..");
    mainWindow->SetWindowState(new SpaceInvadersWindow(mainWindow));

    Util::Time time;
    long startTime = time.TimeMs();
    long timeStep = startTime;
    // The Main loop
    bool running = true;
    int sleepTime = 16;
    int frame = 0;
    double frametime = 0.0;
    while(running)
    {
        // Get time diff
        long currentTime = time.TimeMs();
        double dt = double(currentTime - timeStep) * 0.001;
        timeStep = currentTime;
        ++frame;
        if((frametime += dt) > 1.0)
        {
            print("FPS: " << frame);
            frametime -= 1.0;
            if(frame < 55)
                --sleepTime;
            else if(frame > 78)
                ++sleepTime;
            frame = 0;
        }
        
        // Exit if there is no main window
        if(!graphics->windows[0]){
            running = false;
            continue;
        }
        
        // Handle all window events
        for(int i = 0; i < MAX_WINDOWS; ++i){
            if(!graphics->windows[i])
                continue;
            // Let the window handle events
            graphics->windows[i]->HandleEvents();
        }
        
        // Update Game
        game->Update(dt);
        
        // Update Graphics
        graphics->Render(dt);
        
        Util::Sleep::SleepMS(sleepTime);
    }
    std::cout << "Runtime: " << (float(time.GetTimeMs() - startTime))/1000.0f << " s\n";
    return 0;
}

/** InitializeManagers
    Initialized all managers for the application.
*/
int InitializeManagers()
{
    // Initialize all managers
    print("\nInitializing Managers..");
    
    // GraphicsManager
    prints("* GraphicsManager.. ");
    if(!graphics->Initialize()){
        print("Failed to initialize!");
        return 1;
    }
    print("\tInitialized.");
    // GameManager
    prints("* GameManager.. ");
    if(!game->Initialize()){
        print("Failed to initialize!");
        return 1;
    }
    print("\tInitialized.");
    // InputManager
    prints("* InputManager.. ");
    if(!input->Initialize()){
        print("Failed to initialize!");
        return 1;
    }
    print("\tInitialized.");
    // FileLoader
    prints("* FileLoader.. ");
    if(!fileLoader->Initialize()){
        print("Failed to initialize!");
        return 1;
    }
    print("\t\tInitialized.");
    
    print("Initializing Managers finished!\n");
    return 0;
}

/** main
    Main function, application starts and ends here.
*/
int main(int argc, char** argv)
{
    print("SPACEINVADERS");
    print("OS: " << OS);
    print("CurrentDir: " << Util::GetCurrentDir());
    // Initialize managers
    if(InitializeManagers() != 0)
    {
        printl("Failed to initialize managers.", 1);
        return 1;
    }
    // Run the MainLoop
    return MainLoop(argc, argv);
}