#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QString>

namespace vrconstants {
    extern const int updateInterval; // in ms
    extern const int lookForRunningSimInterval; // in ms
    extern const int connectToSharedMemoryInterval; // in ms

    extern const wchar_t* r3eProcessName;
    extern const QString r3eSharedMemoryName;

    extern const wchar_t* acProcessName;
    extern const QString acSharedMemoryNameStatic;
    extern const QString acSharedMemoryNamePhysics;
    extern const QString acSharedMemoryNameGraphcics;
}

#endif // CONSTANTS_H
