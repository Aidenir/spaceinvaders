/* /////////////////////////////////////////////////////////////////////
//  File:       Keys.cpp
//  Author      Blankycan
// Copyright 2013 Blankycan
///////////////////////////////////////////////////////////////////// */
#include "Keys.h"
// Std & General includes
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <string.h>
////////////////////////////////////////////////////////////////////////

char keyString[KEY::KEY_AMOUNT][16];
bool initialized = false;

void InitializeKeyStrings()
{
    print("Initializing key strings..");
    for(int keyCode = 0; keyCode < KEY::KEY_AMOUNT; ++keyCode)
    {
        if(keyCode >= KEY::A && keyCode <= KEY::Z){
            char key[2];
            key[0] = char('A' + keyCode - KEY::A);
            key[1] = '\0';
            strncpy(keyString[keyCode], key, 16);
        }
        else if(keyCode >= KEY::a && keyCode <= KEY::z){
            char key[2];
            key[0] = char('a' + keyCode - KEY::a);
            key[1] = '\0';
            strncpy(keyString[keyCode], key, 16);
        }
        else if(keyCode >= KEY::F1 && keyCode <= KEY::F12){
            char key[4];
            key[0] = 'F';
            int index = 1;
            if(keyCode >= KEY::F10){
                key[index++] = '1';
                key[index++] = char('0' + keyCode - KEY::F10);
            }
            else
                key[index++] = char('1' + keyCode - KEY::F1);
            key[index++] = '\0';
            strncpy(keyString[keyCode], key, 16);
        }
        else
        {
            switch(keyCode)
            {
                case KEY::NULL_KEY:     strncpy(keyString[keyCode], "NULL_KEY",     16); break;
                
                case KEY::Zero:         strncpy(keyString[keyCode], "Zero",         16); break;
                case KEY::One:          strncpy(keyString[keyCode], "One",          16); break;
                case KEY::Two:          strncpy(keyString[keyCode], "Two",          16); break;
                case KEY::Three:        strncpy(keyString[keyCode], "Three",        16); break;
                case KEY::Four:         strncpy(keyString[keyCode], "Four",         16); break;
                case KEY::Five:         strncpy(keyString[keyCode], "Five",         16); break;
                case KEY::Six:          strncpy(keyString[keyCode], "Six",          16); break;
                case KEY::Seven:        strncpy(keyString[keyCode], "Seven",        16); break;
                case KEY::Eight:        strncpy(keyString[keyCode], "Eight",        16); break;
                case KEY::Nine:         strncpy(keyString[keyCode], "Nine",         16); break;
                
                case KEY::Enter:        strncpy(keyString[keyCode], "Enter",        16); break;
                case KEY::Space:        strncpy(keyString[keyCode], "Space",        16); break;
                case KEY::Control:      strncpy(keyString[keyCode], "Control",      16); break;
                case KEY::Shift:        strncpy(keyString[keyCode], "Shift",        16); break;
                case KEY::Escape:       strncpy(keyString[keyCode], "Escape",       16); break;
                case KEY::Alt:          strncpy(keyString[keyCode], "Alt",          16); break;
                case KEY::Tab:          strncpy(keyString[keyCode], "Tab",          16); break;
                case KEY::Backspace:    strncpy(keyString[keyCode], "Backspace",    16); break;
                
                case KEY::Plus:         strncpy(keyString[keyCode], "Plus",         16); break;
                case KEY::Minus:        strncpy(keyString[keyCode], "Minus",        16); break;
                case KEY::Multiply:     strncpy(keyString[keyCode], "Multiply",     16); break;
                case KEY::Divided:      strncpy(keyString[keyCode], "Divided",      16); break;
                
                case KEY::Period:       strncpy(keyString[keyCode], "Period",       16); break;
                case KEY::Comma:        strncpy(keyString[keyCode], "Comma",        16); break;
                
                case KEY::Home:         strncpy(keyString[keyCode], "Home",         16); break;
                case KEY::End:          strncpy(keyString[keyCode], "End",          16); break;
                //case KEY::A: case
                default:
                    break;
            }
            // Add NUll terminator in the end
            char end = '\0';
            strcat(keyString[keyCode], &end);
        }
    }
    initialized = true;
}

char * GetKeyString(int keyCode)
{
    if(!initialized)
        InitializeKeyStrings();

    return keyString[keyCode];
}

int GetKeycodeFromXkey(int xKey)
{
    if(xKey >= XK_A && xKey <= XK_Z)
        return KEY::A + xKey - XK_A;
    else if(xKey >= XK_a && xKey <= XK_z)
        return KEY::a + xKey - XK_a;
    else if(xKey >= XK_0 && xKey <= XK_9)
        return KEY::Zero + xKey - XK_0;
    else if(xKey >= XK_F1 && xKey <= XK_F12)
        return KEY::F1 + xKey - XK_F1;
    
    
    switch(xKey)
    {
        case XK_Return:                         return KEY::Enter;
        case XK_space:                          return KEY::Space;
        case XK_Control_L: case XK_Control_R:   return KEY::Control;
        case XK_Shift_L: case XK_Shift_R:       return KEY::Shift;
        case XK_Escape:                         return KEY::Escape;
        case XK_Alt_L: case XK_Alt_R:           return KEY::Alt;
        case XK_Tab:                            return KEY::Tab;
        case XK_BackSpace:                      return KEY::Backspace;
        
        case XK_plus:                           return KEY::Plus;
        case XK_minus:                          return KEY::Minus;
        case XK_multiply:                       return KEY::Multiply;
        case XK_division:                       return KEY::Divided;
        
        case XK_period:                         return KEY::Period;
        case XK_comma:                          return KEY::Comma;
        
        case XK_Home:                           return KEY::Home;
        case XK_End:                            return KEY::End;

        case XK_Up:                             return KEY::Up;
        case XK_Down:                           return KEY::Down;
        case XK_Left:                           return KEY::Left;
        case XK_Right:                          return KEY::Right;
        
        default:                                return KEY::NULL_KEY;
    }
}