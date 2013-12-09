/* /////////////////////////////////////////////////////////////////////
//  File:       WindowState.h
//  Author      Blankycan
// Copyright 2013 Blankycan
///////////////////////////////////////////////////////////////////// */
#ifndef WINDOWSTATE_H
#define	WINDOWSTATE_H
////////////////////////////////////////////////////////////////////////
#include "WindowHandler.h"
// OS include
#include "os.h"
// Std & General include
#if defined (LINUX)
    #include <GL/glew.h>
    #include <GL/glu.h>
#elif defined (WINDOWS)
    #include "../GL/glew.h"
#endif
// Application includes
#include "RenderState.h"
////////////////////////////////////////////////////////////////////////

/** WindowState
    Base class, will hold window content
*/
class WindowState
{
public:
    /* Default constructor */
    WindowState(WindowHandler *window);
    /* Default destructor */
    ~WindowState();
    
    /* Initialation function, to be overridden */
    virtual void Initialize();
    /* Resize function */
    virtual void Resize(int width, int height);
    /* Updates and renders, to be overridden */
    virtual void Render(float dt);
    /* collects the handles to the shaders uniforms */
    virtual void GetUniformLocations();
    /* Loads the uniform values into the graphic card */
    virtual void UpdateUniformValues();
    
    /* Get Window */
    WindowHandler * GetWindow() { return window; }
    /* Get Render state */
    RenderState * GetRenderState() { return &renderState; }
    
protected:
    /* Window that this state belongs to */
    WindowHandler *window;
    /* RenderState */
    RenderState renderState;
    
};

////////////////////////////////////////////////////////////////////////
#endif  // WINDOWSTATE_H
////////////////////////////////////////////////////////////////////////

