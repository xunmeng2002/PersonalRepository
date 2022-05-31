#include "Platform.h"


#ifdef LINUX

int GetLastError()
{
    return errno;
}

#endif
