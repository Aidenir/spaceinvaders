/* /////////////////////////////////////////////////////////////////////
//  File:       SpaceInvadersWindow.h
//  Author      Blankycan
// Copyright 2013 Blankycan
///////////////////////////////////////////////////////////////////// */
#ifndef SPACEINVADERSWINDOW_H
#define	SPACEINVADERSWINDOW_H
////////////////////////////////////////////////////////////////////////
// Application includes
#include "WindowState.h"
////////////////////////////////////////////////////////////////////////

/** SpaceInvadersWindow
    Handles the Space Invaders game play.
*/
class SpaceInvadersWindow : public WindowState
{
public:
    /* Default constructor */
    SpaceInvadersWindow(WindowHandler *window);
    /* Default destructor */
    ~SpaceInvadersWindow();
    
    /* Initialization function*/
    void Initialize();
    /* Resize */
    void Resize(int width, int height);
    /* Update/Render function */
    void Render(float dt);
    /* Function that collects the handles to the shaders uniforms */
    void GetUniformLocations();
    /* Loads the uniform values into the graphic card */
    void UpdateUniformValues();
    
private:
    
};

////////////////////////////////////////////////////////////////////////
#endif  // SPACEINVADERSWINDOW_H
////////////////////////////////////////////////////////////////////////

