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
#include "GraphicsManager.h"
#include "WindowHandler.h"
#include "Time.h"
#include "Sleep.h"
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
    //mainWindow->SetWindowState(new PhysicsWindow(mainWindow));

    Util::Time time;
    long startTime = time.TimeMs();
    long timeStep = startTime;
    // The Main loop
    bool running = true;
    while(running)
    {
        // Get time diff
        long currentTime = time.TimeMs();
        float dt = float(currentTime - timeStep) * 0.001f;
        timeStep = currentTime;
        
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
        //game->Update(dt);
        
        // Update Graphics
        //graphics->Render(dt);
        
        Util::Sleep::SleepMS(20);
    }
    std::cout << "Runtime: " << (float(time.GetTimeMs() - startTime))/1000.0f << " s\n";
    return 0;
}

/** main
    Main function, application starts and ends here.
*/
int main(int argc, char** argv)
{
    print("SPACEINVADERS");
    print("OS: " << OS);
    // Run the MainLoop
    return MainLoop(argc, argv);
}