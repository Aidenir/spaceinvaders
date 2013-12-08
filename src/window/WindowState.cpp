/* /////////////////////////////////////////////////////////////////////
//  File:       WindowState.cpp
//  Author      Blankycan
// Copyright 2013 Blankycan
///////////////////////////////////////////////////////////////////// */
#include "WindowState.h"
// Application includes
#include "WindowHandler.h"
////////////////////////////////////////////////////////////////////////

WindowState::WindowState(WindowHandler *window)
{
    this->window = window;
}

WindowState::~WindowState() {}

void WindowState::Initialize() {}

void WindowState::Resize(int width, int height) {}

void WindowState::Render(float dt)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void WindowState::GetUniformLocations() {}

void WindowState::UpdateUniformValues() {}