/*////////////////////////////////////////////////////////
 * File:        Util_Sleep.h
 * Author:      Blankycan
 * Date:        2013-09-05
/////////////////////////////////////// © Blankycan 2013 */
#ifndef UTIL_SLEEP_H
#define	UTIL_SLEEP_H
///////////////////////////////////////////////////////////
#include "os.h"
#include <unistd.h>
///////////////////////////////////////////////////////////

/*  Util_Sleep
 * A method to sleep milliseconds on both Linux and Windows.
 */
class Util_Sleep
{
public:
    static void SleepMS(int milliseconds)
    {
        #if defined (LINUX)
            usleep(milliseconds*10);
        #elif defined (WINDOWS)
            Sleep(milliseconds);
        #endif
    }
};

///////////////////////////////////////////////////////////
#endif	/* UTIL_SLEEP_H */

