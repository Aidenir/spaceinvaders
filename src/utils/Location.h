/* /////////////////////////////////////////////////////////////////////
//	File:		Location.h
//	Author		Blankycan
// Copyright 2013 Blankycan
///////////////////////////////////////////////////////////////////// */
#ifndef UTIL_LOCATION_H
#define UTIL_LOCATION_H
////////////////////////////////////////////////////////////////////////
// Std & General includes
#include <stdio.h>  /* defines FILENAME_MAX */
#if defined(WINDOWS)
    #include <direct.h>
    #define currentDir _getcwd
#elif defined(LINUX)
    #include <unistd.h>
	#include <errno.h>
    #define currentDir getcwd
 #endif
////////////////////////////////////////////////////////////////////////

namespace Util
{
static char * GetCurrentDir()
{
	char cCurrentPath[FILENAME_MAX];

	if (!currentDir(cCurrentPath, sizeof(cCurrentPath)))
	{
		return "";//errno;
	}

	cCurrentPath[sizeof(cCurrentPath) - 1] = '\0'; /* not really required */

	return cCurrentPath;
}
}	// End of Util namespace

////////////////////////////////////////////////////////////////////////
#endif UTIL_LOCATION_H
////////////////////////////////////////////////////////////////////////