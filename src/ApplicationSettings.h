/* /////////////////////////////////////////////////////////////////////
//  File:       ApplicationSettings.h
//  Author      Blankycan
// Copyright 2013 Blankycan
///////////////////////////////////////////////////////////////////// */
#ifndef APPLICATIONSETTINGS_H
#define APPLICATIONSETTINGS_H
////////////////////////////////////////////////////////////////////////

struct ApplicationSettings{
public:/* Static instance function, to get a copy of the singleton */
	static ApplicationSettings* Instance();
	/* Managers default de-constructor */
	~ApplicationSettings();
	/* Initialized the Manager, needs to be executed before usage of Manager */
	bool Initialize();

	/* Is window fullscreen */
	bool fullscreen;
	/* Windows width and height */
	int width, height;
	/* Remember previous width and height when maximizing */
	int prevWidth, prevHeight;
	/* Screen ratio */
	float xRatio, yRatio;
	/// Origin game width and height
	int originGameWidth, originGameHeight;
	/// Game width and height
	int gameWidth, gameHeight;
	/// Game ratio
	float xGameRatio, yGameRatio;
	/* Pixel height and width */
	double xPixel, yPixel;
	/// Smallest pixel size
	double minPixel;
	/// 1 if game screen is touching left/right borders, 2 if screen is touching top/bottom, else 0
	int appSize;
	/* Color bits */
	int bits;
	/* Describes the used OpenGL version (4.2 or 3.3) */
	float glVersion;
private:
	/* Managers default constructor */
	ApplicationSettings();

};

////////////////////////////////////////////////////////////////////////
#define appSettings ApplicationSettings::Instance()
#endif	// APPLICATIONSETTINGS_H
////////////////////////////////////////////////////////////////////////