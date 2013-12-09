/*////////////////////////////////////////////////////////
 * File:        Sleep.h
 * Author:      Blankycan
 * Date:        2013-09-05
/////////////////////////////////////// © Blankycan 2013 */
#ifndef UTIL_SLEEP_H
#define	UTIL_SLEEP_H
////////////////////////////////////////////////////////////////////////
// OS include
#include "os.h"
 // Std & General includes
#include <unistd.h>
////////////////////////////////////////////////////////////////////////

namespace Util
{
/**	Sleep
	A method to sleep milliseconds cross platform.
*/
class Sleep
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
}	// End of namespace Util

////////////////////////////////////////////////////////////////////////
#endif	// UTIL_SLEEP_H
////////////////////////////////////////////////////////////////////////

