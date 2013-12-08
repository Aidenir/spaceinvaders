/* /////////////////////////////////////////////////////////////////////
//  File:       WindowsHandler.cpp
//  Author      Blankycan
// Copyright 2013 Blankycan
///////////////////////////////////////////////////////////////////// */
#include "WindowHandler.h"
////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string.h>
////////////////////////////////////////////////////////////////////////
#include "os.h"
#include "LinuxWindow.h"
#include "LinuxEventHandler.h"
////////////////////////////////////////////////////////////////////////
// Only for Linux
#ifdef LINUX

LinuxWindow::LinuxWindow(int x, int y, int width, int height, char *windowTitle, const char *displayName) : 
    singleBufferAttributes {GLX_RGBA, GLX_DEPTH_SIZE, 24, None},
    doubleBufferAttributes {GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None}
{
    this->x             = x;
    this->y             = y;
    this->width         = width;
    this->height        = height;
    strncpy(this->title, windowTitle, 32);
    this->displayName   = displayName;
    this->swapBuffers   = false;
    
    this->display = NULL;
}
   
LinuxWindow::~LinuxWindow()
{
    
}

bool LinuxWindow::Show()
    {
    // First connect to a display
    std::cout << "Connecting display..";
    if(!ConnectDisplay(displayName)){
        std::cout << "\tCould not connect to display.\n";
        return false;
    }
    std::cout << "\tSucceeded.\n";
    
    // Make the window itself
    std::cout << "Creating window..";
    if(!CreateWindow()){
        std::cout << "\tCould not create the window.\n";
        return false;
    }
    std::cout << "\tSucceeded.\n";
    
    // Check if we can connect X server to OpenGL
    std::cout << "Checking OpenGL compatibility..";
    if(!CheckGL()){
        std::cout << "\tCould not connect X server to OpenGL.\n";
        return false;
    }
    std::cout << "\tSucceeded.\n";
    
    // If so, bind the OpenGL context
    std::cout << "Binding OpenGL context..";
    if(!BindGLContext()){
        std::cout << "\tCould not bind the OpenGL context.\n";
        return false;
    }
    std::cout << "\tSucceeded.\n";
   
    // Put the window on the screen and display it
    XMapWindow(display, window);
    
    return true;
}

bool LinuxWindow::RegisterForEvents(WindowHandler *window)
{
    // Setup the xEventHandler
    eventHandler = new LinuxEventHandler(window);
    if(eventHandler)
        return true;
    return false;
}

void LinuxWindow::HandleEvents(int times)
{
    if(eventHandler)
        eventHandler->HandleXEvent(times);
}

bool LinuxWindow::ConnectDisplay(const char *displayname)
{
    try{
        display = XOpenDisplay(displayname);
    }
    catch(...){
        std::cout << "";
        display = NULL;
    }
    if(display)
        return true;
    return false;
}

bool LinuxWindow::CreateWindow()
{
    if(display) {
        // Create the window
        window = XCreateWindow(display, DefaultRootWindow(display), x, y, width, height, 0, CopyFromParent, CopyFromParent, CopyFromParent, 0, 0);
        // Set the title
        XStoreName(display, window, title);
        return true;
    }
    return false;
}

bool LinuxWindow::CheckGL()
{
    // First check the GLX extension
    int test;
    if(!glXQueryExtension(display, &test, &test))
        return false;
    
    // Find if OpenGL can work with double-buffer
    visualInfo = glXChooseVisual(display, DefaultScreen(display), doubleBufferAttributes);
    if(!visualInfo)
    {
        // Check if we at least can have single-buffer
        visualInfo = glXChooseVisual(display, DefaultScreen(display), singleBufferAttributes);
        if(!visualInfo)
        {
            // Then we have no depth buffer
            std::cout << "No depth buffer.\n";
            return false;
        }
    }
    else
        swapBuffers = true;
    return true;
}

bool LinuxWindow::BindGLContext()
{
    // First create the rendering context
    context = glXCreateContext(display, visualInfo, None, true);
    if(!context){
        // Failed to create the rendering context
        std::cout << "Failed to create the rendering context.\n";
        return false;
    }
    // Then bind the rendering context to the window
    if(!glXMakeContextCurrent(display, window, window, context)){
        // Failed to bind the context
        std::cout << "Failed to bind the context.\n";
        return false;
    }
    return true;
}

////////////////////////////////////////////////////////////////////////
#endif  // LINUX