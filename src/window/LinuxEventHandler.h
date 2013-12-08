/* /////////////////////////////////////////////////////////////////////
//  File:       LinuxEventHandler.h
//  Author      Blankycan
// Copyright 2013 Blankycan
///////////////////////////////////////////////////////////////////// */
#ifndef LINUXEVENTHANDLER_H
#define	LINUXEVENTHANDLER_H
////////////////////////////////////////////////////////////////////////
// OS include
#include "os.h"
// Std & General includes
#if defined (LINUX)
    #include <X11/Xlib.h>
#endif
// Application includes
#include "WindowHandler.h"
class WindowHandler;
////////////////////////////////////////////////////////////////////////
// Only for Linux
#ifdef LINUX
////////////////////////////////////////////////////////////////////////

/** LinuxEventHandler
    Handles events from the OS, takes input into application.
*/
class LinuxEventHandler
{
public:
    /* Default constructor */
    LinuxEventHandler(WindowHandler *window);
    /* Default destructor */
    ~LinuxEventHandler();
    
    /* Handles next XNextEvent */
    void HandleXEvent(int times = 1);
    
private:
    /* Main window */
    WindowHandler *window;
    /* XEvent */
    XEvent event;
    /* Delete message, for when closing window */
    Atom wmDeleteMessage;
    
};

////////////////////////////////////////////////////////////////////////
#endif  // LINUX
////////////////////////////////////////////////////////////////////////
#endif  // LINUXEVENTHANDLER_H
////////////////////////////////////////////////////////////////////////
