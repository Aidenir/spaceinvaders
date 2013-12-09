/* /////////////////////////////////////////////////////////////////////
//  File:       LinuxEventHandler.cpp
//  Author      Blankycan
// Copyright 2013 Blankycan
///////////////////////////////////////////////////////////////////// */
#include "LinuxEventHandler.h"
// OS include
#include "os.h"
// Std & General includes
#include <iostream>
// Application includes
#include "GraphicsManager.h"
#include "WindowHandler.h"
#include "InputManager.h"
#include "Keys.h"
////////////////////////////////////////////////////////////////////////
// Only for Linux
#ifdef LINUX
////////////////////////////////////////////////////////////////////////

LinuxEventHandler::LinuxEventHandler(WindowHandler *window)
{
    this->window = window;
    
    // Register XEvent for exposure, key-presses and button-presses
    XSelectInput(window->windowHandler->display, window->windowHandler->window,
            ExposureMask | StructureNotifyMask | KeymapStateMask | KeyPressMask | KeyReleaseMask | /*PointerMotionMask | */ButtonPressMask | ButtonReleaseMask);
    wmDeleteMessage = XInternAtom(window->windowHandler->display, "WM_DELETE_WINDOW", False);
    XSetWMProtocols(window->windowHandler->display, window->windowHandler->window, &wmDeleteMessage, 1);
}

LinuxEventHandler::~LinuxEventHandler() {}

void LinuxEventHandler::HandleXEvent(int times)
{
    // Handle 'times' amount of xEvents
    while (times-- > 0)
    {
        // Get the next xEvent
        XNextEvent(window->windowHandler->display, &event);
        // Handle the event
        switch(event.type)
        {
            // Redraws the window
            case Expose:
                std::cout << "I have been exposed!\n";
                break;
                
            case ConfigureNotify:
                // If current window size does not match with 
                if(window->GetWidth() != event.xconfigure.width || window->GetHeight() != event.xconfigure.height)
                {
                    window->SetWidth(event.xconfigure.width);
                    window->SetHeight(event.xconfigure.height);
                    std::cout << "Window changed to: " << window->GetWidth() << "x" << window->GetHeight() << "\n";
                }
                break;
                
            // State of keybord on pointer/keybord enter window
            case KeymapNotify:
                std::cout << "KeymapNotify\n";
                XRefreshKeyboardMapping(&event.xmapping);
                break;
                
            // Get KeyPress
            case KeyPress:{
                bool shift = input->IsKey(KEY::Shift);
                int keyCode = GetKeycodeFromXkey((int)XLookupKeysym(&event.xkey, shift));
                input->KeyDown(keyCode);
                
                if(keyCode == KEY::Space)
                    for(int i = 0; i < KEY::KEY_AMOUNT; ++i)
                        std::cout << "i " << input->IsKey(i) << " " << GetKeyString(i);
                break;
            }
            // KeyRelease
            case KeyRelease:{
                unsigned short repeated = 0;
                // TODO check if not writing
                if (XEventsQueued(window->windowHandler->display, QueuedAfterReading)){
                    XEvent nextevnt;
                    XPeekEvent(window->windowHandler->display, &nextevnt);
                    if (nextevnt.type == KeyPress && nextevnt.xkey.time == event.xkey.time){
                        // delete repeated KeyPress event
                        continue;
                        repeated = 1;
                    }
                }
                if (!repeated){
                    bool shift = input->IsKey(KEY::Shift);
                    int keyCode = GetKeycodeFromXkey((int)XLookupKeysym(&event.xkey, shift));
                    input->KeyUp(keyCode);
                }
                break;
            }
            /*case MotionNotify:{
                unsigned short handle = 1;
                if (XEventsQueued(window->windowHandler->display, QueuedAfterReading)){
                    XEvent nextevnt;
                    XPeekEvent(window->windowHandler->display, &nextevnt);
                    if (nextevnt.type == MotionNotify){
                        // Process next one rather than this
                        handle = 0;
                    }
                }
                if(times == 1 || handle)
                {
                    Window root, child;
                    int rootX, rootY, winX, winY;
                    unsigned int mask;
                    XQueryPointer(window->windowHandler->display, window->windowHandler->window, &root, &child, &rootX, &rootY, &winX, &winY, &mask);
                    std::cout << "X: " << winX << "\tY: " << winY << std::endl;
                }
                break;
            }*/
            // Get ButtonPress
            case ButtonPress:{
                std::cout << "Button: " << event.xbutton.button << " was pressed.\n";
                
                Window root, child;
                int rootX, rootY, winX, winY;
                unsigned int mask;
                XQueryPointer(window->windowHandler->display, window->windowHandler->window, &root, &child, &rootX, &rootY, &winX, &winY, &mask);
                input->HandleMouse(winX, winY, event.xbutton);
                
                break;
            }
            // Get ButtonRelease
            case ButtonRelease:
                // 1 - Left
                // 2 - Middle
                // 3 - Right
                // 4 - Scroll Up
                // 5 - Scroll Down
                std::cout << "Button: " << event.xbutton.button << " was released.\n";
                
                Window root, child;
                int rootX, rootY, winX, winY;
                unsigned int mask;
                XQueryPointer(window->windowHandler->display, window->windowHandler->window, &root, &child, &rootX, &rootY, &winX, &winY, &mask);
                input->HandleMouse(winX, winY, event.xbutton);
                break;
                
            case ClientMessage:
                // If closing
                if(event.xclient.data.l[0] == wmDeleteMessage)
                {
                    graphics->DeleteGLWindow(window->GetIndex());
                    return;
                }
                break;
                
            default:
                break;
        }
    } 
}

////////////////////////////////////////////////////////////////////////
#endif  // LINUX
////////////////////////////////////////////////////////////////////////
