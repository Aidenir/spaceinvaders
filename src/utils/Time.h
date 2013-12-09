/* /////////////////////////////////////////////////////////////////////
//  File:       Time.h
//  Author      Blankycan
// Copyright 2013 Blankycan
///////////////////////////////////////////////////////////////////// */
#ifndef UTIL_TIME_H
#define	UTIL_TIME_H
////////////////////////////////////////////////////////////////////////
// OS include
#include "os.h"
// Std & General includes
#if defined (LINUX)
	#include <time.h>
#elif defined (WINDOWS)

#endif
///////////////////////////////////////////////////////////

namespace Util
{
class Time
{
public:
    /* Returns current time in milliseconds */
    long TimeMs();
    /* Returns current time in milliseconds */
    static long GetTimeMs();
private:
    /* Keeps the time */
    static struct timespec time;
};
}   // End of namespace Util

////////////////////////////////////////////////////////////////////////
#endif	// UTIL_TIME_H
////////////////////////////////////////////////////////////////////////

