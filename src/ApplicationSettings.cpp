/* /////////////////////////////////////////////////////////////////////
//  File:       ApplicationSettings.cpp
//  Author      Blankycan
// Copyright 2013 Blankycan
///////////////////////////////////////////////////////////////////// */
#include "ApplicationSettings.h"
////////////////////////////////////////////////////////////////////////

ApplicationSettings* ApplicationSettings::Instance()
{
	static ApplicationSettings instance;
	return &instance;
}
ApplicationSettings::ApplicationSettings()
{
	fullscreen = false;
	width = 800;
	height = 600;
	prevWidth = width;
	prevHeight = height;
	xRatio = yRatio = 1.0f;
	gameWidth = 960;
	gameHeight = 640;
	xGameRatio = yGameRatio = 1.0f;
	minPixel = xPixel = yPixel = 0.001;
	bits = 32;
}
ApplicationSettings::~ApplicationSettings()
{

}
bool ApplicationSettings::Initialize()
{
	return true;
}