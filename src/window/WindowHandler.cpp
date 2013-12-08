/* /////////////////////////////////////////////////////////////////////
//  File:       WindowHandler.cpp
//  Author      Blankycan
// Copyright 2013 Blankycan
///////////////////////////////////////////////////////////////////// */
#include "WindowHandler.h"
////////////////////////////////////////////////////////////////////////

WindowHandler::WindowHandler(int index)
{
    this->index = index;
    windowHandler = NULL;
    windowState = NULL;
    xRatio = yRatio = 1.0f;
    xPixel = yPixel = 0.002;
}

WindowHandler::~WindowHandler()
{
    if(windowHandler){
        // Destroy window
        XDestroyWindow(windowHandler->display, windowHandler->window);
        XCloseDisplay(windowHandler->display);
        
        delete windowHandler;
        windowHandler = NULL;
    }
}

bool WindowHandler::CreateWindow(int x, int y, int width, int height, char *windowTitle)
{
    this->width = width;
    this->height = height;
#ifdef LINUX
    windowHandler = new LinuxWindow(x, y, width, height, windowTitle);
    return windowHandler->Show();
#else
    return false;
#endif
}
bool WindowHandler::SetupGL()
{
    if(!windowHandler)
        return false;
    
    // Setup the OpenGL
    if(!InitializeGL()){
        std::cout << "Failed to initialize OpenGL.\n";
        return false;
    }
    
    // Resize the OpenGL
    if(!ResizeGL(width, height)){
        std::cout << "Failed to resize OpenGL.\n";
        return false;
    }
    
    return true;
}

bool WindowHandler::InitializeGL()
{
    static bool first = true;
    if(first)
    {
        first = false;
        glewExperimental = GL_TRUE;
        // Initialize GLEW
        GLuint result = glewInit();
        if(result != GLEW_OK){
            print("- GLEW could not initialize!\nError: " << glewGetErrorString(result));
            return false;
        }
        print("Using GLEW version: " << glewGetString(GLEW_VERSION));
        if(glGetString(GL_SHADING_LANGUAGE_VERSION))
        {
            print("Current version of hardware: " << glGetString(GL_SHADING_LANGUAGE_VERSION));
        }

        // Check so the graphic card supports at least OpenGL v. 3.3
        if(glewIsSupported("GL_VERSION_3_3")){
            print("Using OpenGL version 3.3");
        }
        else{
            print("- Lowest OpenGL version 3.3 not suported!");
            print("Try updating to newest graphical drivers, but your graphic card may not support it.");
            return false;
        }
    }
    /*
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glFrontFace(GL_CCW);
	glCullFace(GL_FRONT_AND_BACK);
	//glClearDepth(1.0f);
	glClearColor(0.1f, 0.06f, 0.0f, 1.0f);
    */
    return true;
}

bool WindowHandler::ResizeGL(int width, int height)
{
    this->width = width;
    this->height = height;
    
    glViewport(0, 0, width, height);
    float xRatio = 1.0f;
    float yRatio = 1.0f;
    
    if(width > height)
		xRatio = float(width) / float(height);
	else if(width < height)
		yRatio = float(height) / float(width);
    

	//renderState.projectionMatrix = Matrix4f::getInitProjectionPerspective(-engineSettings->xRatio, engineSettings->xRatio, -engineSettings->yRatio, engineSettings->yRatio, 3.0f, 64.f);
	//renderState.projectionMatrix = Matrix4f::getInitProjectionOrthogonal(-engineSettings->xRatio, engineSettings->xRatio, -engineSettings->yRatio, engineSettings->yRatio, 0.f, 64.f);
    return true;
}

bool WindowHandler::RegisterForEvents()
{
#ifdef LINUX
    if(!windowHandler)
        return false;
    return windowHandler->RegisterForEvents(this);
#else
    return false;
#endif
}

void WindowHandler::HandleEvents()
{
#ifdef LINUX
    if(!windowHandler)
        return;

    // Get amount of pending events
    int pendingEvents = XPending(windowHandler->display);
    // If there is no pending events, don't process
    if(!pendingEvents)
        return;
    
    // Check so we don't handle more than defined maximum per loop
    int eventsToHandle = pendingEvents;
    if(eventsToHandle > MAX_EVENT_HANDLES)
        eventsToHandle = MAX_EVENT_HANDLES;
    
    windowHandler->HandleEvents(eventsToHandle);
#else
    return;
#endif
}

void WindowHandler::SetWindowState(WindowState* windowState)
{
    // Check if we already have one and must delete that first
    if(this->windowState)
        delete windowState;
    // Then apply the new windowState
    this->windowState = windowState;
    windowState->Initialize();
    windowState->Resize(width, height);
}

void WindowHandler::Render(float dt)
{
    // If we have an state, let it render
    if(windowState)
        windowState->Render(dt);
    else {
        // Clear the Screen and the Depth buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(1.0f, 0.f, 1.0f, 1.0f);
    }
    
    if(windowHandler->SwapBuffers()){
        #if defined (LINUX)
            glXSwapBuffers(windowHandler->display, windowHandler->window);
        #elif defined (WINDOWS)
            SwapBuffers(hDC);
        #endif
    }
    else
        glFlush();
}