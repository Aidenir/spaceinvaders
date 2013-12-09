/* /////////////////////////////////////////////////////////////////////
//  File:       LinuxWindow.h
//  Author      Blankycan
// Copyright 2013 Blankycan
///////////////////////////////////////////////////////////////////// */
#ifndef LINUXWINDOW_H
#define	LINUXWINDOW_H
////////////////////////////////////////////////////////////////////////
// OS include
#include "os.h"
// Std & General includes
#if defined (LINUX)
    #include <GL/glew.h>
    #include <GL/glx.h>
    #include <X11/Xlib.h>
    #include <X11/Xutil.h>
#endif
// Application includes
#include "WindowHandler.h"
#include "LinuxEventHandler.h"
class WindowHandler;
class LinuxEventHandler;
////////////////////////////////////////////////////////////////////////
// Only for Linux
#ifdef LINUX
////////////////////////////////////////////////////////////////////////

/** LinuxWindow
    Handles the window creation in Linux.
*/
class LinuxWindow
{
public:
    /* Default constructor */
    LinuxWindow(int x, int y, int width, int height, char *windowTitle, const char *displayName = 0);
    /* Default destructor */
    ~LinuxWindow();
    
    /* Creates and displays the window */
    bool Show();
    /* Registers for XEvents */
    bool RegisterForEvents(WindowHandler *window);
    /* Handle events */
    void HandleEvents(int times = 1);
    /* Returns if swapping buffers */
    bool SwapBuffers() { return swapBuffers; }
    
    /* Display */
    Display *display;
    /* Window */
    Window window;
private:
    /* Connects window to a display */
    bool ConnectDisplay(const char *displayName);
    /* Check if we can connect X server to OpenGL */
    bool CheckGL();
    /* Creates the window */
    bool CreateWindow();
    /* Bind OpenGL context */
    bool BindGLContext();
    
    /* Event handler */
    LinuxEventHandler *eventHandler;
    
    /* Position of the window */
    int x, y;
    /* Width and height of the window */
    int width, height;
    /* Window title */
    char title[32];
    /* Display name */
    const char *displayName;
    /* If swapping buffers */
    bool swapBuffers;
    /* Visual info */
    XVisualInfo *visualInfo;
    /* OpenGL GLX context */
    GLXContext context;
    
    /* For trying to enable double buffer OpenGL */
    int doubleBufferAttributes[10];
    /* For trying to enable single buffer OpenGL */
    int singleBufferAttributes[10];
};

////////////////////////////////////////////////////////////////////////
#endif  // LINUX
////////////////////////////////////////////////////////////////////////
#endif  // LINUXWINDOW_H
////////////////////////////////////////////////////////////////////////

