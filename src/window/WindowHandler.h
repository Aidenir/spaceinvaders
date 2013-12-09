/* /////////////////////////////////////////////////////////////////////
//  File:       WindowHandler.h
//  Author      Blankycan
// Copyright 2013 Blankycan
///////////////////////////////////////////////////////////////////// */
#ifndef WINDOWHANDLER_H
#define	WINDOWHANDLER_H
////////////////////////////////////////////////////////////////////////
// OS include
#include "os.h"
// Std & General includes
#if defined (LINUX)
    #include <GL/glew.h>
#elif defined (WINDOWS)
    //#include "../GL/glew.h"
#endif
// Application includes
#include "LinuxWindow.h"
#include "WindowState.h"
#include "Global.h"
class WindowState;
////////////////////////////////////////////////////////////////////////
#define MAX_EVENT_HANDLES 5
////////////////////////////////////////////////////////////////////////

/** WindowHandler
    Handles the window, and the OS specific stuff
*/
class WindowHandler
{
public:
    /* Default constructor */
    WindowHandler(int index);
    /* Default destructor */
    ~WindowHandler();
    
    /* Creates a window */
    bool CreateWindow(int x, int y, int width, int height, char *windowTitle);
    /* Setup OpenGL for a window */
    bool SetupGL();
    /* Resizes the OpenGL */
    bool ResizeGL(int width, int height);
    /* Registers for events */
    bool RegisterForEvents();
    /* Handle events */
    void HandleEvents();
    /* Gets Window State */
    WindowState * GetWindowState() { return windowState; }
    /* Set Window State */
    void SetWindowState(WindowState *windowState);
    /* Update/Render */
    void Render(float dt);
    
    /* Gets index */
    int GetIndex()                      { return index; }
    /* Gets width */
    int GetWidth()                      { return width; }
    /* Gets height */
    int GetHeight()                     { return height; }
    /* Gets x-ratio */
    float GetXRatio()                   { return xRatio; }
    /* Gets y-ratio */
    float GetYRatio()                   { return yRatio; }
    /* Gets x-pixel size */
    float GetXPixel()                   { return xPixel; }
    /* Gets y-pixel size */
    float GetYPixel()                   { return yPixel; }
    /* Sets width */
    void SetWidth(int newWidth)         { width = newWidth; }
    /* Sets height */
    void SetHeight(int newHeight)       { height = newHeight; }
    /* Sets x-ratio */
    void SetXRatio(float ratio)         { xRatio = ratio; }
    /* Sets y-ratio */
    void SetYRatio(float ratio)         { yRatio = ratio; }
    /* Sets x-pixel size */
    void SetXPixel(double size)         { xPixel = size; }
    /* Sets y-pixel size */
    void SetYPixel(double size)         { yPixel = size; }
    
#ifdef LINUX
    LinuxWindow *windowHandler;
#endif
private:
    /* Initializes the OpenGL*/
    bool InitializeGL();
    
    /* Width and height for window */
    int width, height;
    /* Window ratios*/
    float xRatio, yRatio;
    /* Pixel size */
    double xPixel, yPixel;
    /* Window index */
    int index;
    /* Windows state */
    WindowState *windowState;
};

////////////////////////////////////////////////////////////////////////
#endif  // WINDOWHANDLER_H
////////////////////////////////////////////////////////////////////////

