/* /////////////////////////////////////////////////////////////////////
//  File:       Keys.h
//  Author      Blankycan
// Copyright 2013 Blankycan
///////////////////////////////////////////////////////////////////// */
#ifndef KEYS_H
#define KEYS_H
////////////////////////////////////////////////////////////////////////
//#include "InputManager.h"
#include "Global.h"
////////////////////////////////////////////////////////////////////////

namespace KEY
{
    /*  Key
     * All used keys.
     */
    enum KEY
    {
        NULL_KEY = 0,
        
        A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
        a=A, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, 
        Zero, One, Two, Three, Four, Five, Six, Seven, Eight, Nine,
        F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
        Enter, Space, Control, Shift, Escape, Alt, Tab, Backspace,
        Plus, Minus, Multiply, Divided,
        Period, Comma,
        Home, End,
        
        KEY_AMOUNT,
    };
};

char *  GetKeyString(int keyCode);
int     GetKeycodeFromXkey(int xKey);

////////////////////////////////////////////////////////////////////////
#endif  // KEYS_H