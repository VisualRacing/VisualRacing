#include "constants.h"

namespace constants {
    const int updateInterval = 10; // in ms
    const int lookForRunningSimInterval = 100; // in ms
    const int connectToSharedMemoryInterval = 100; // in ms

    const wchar_t* r3eProcessName = L"RRRE.exe";
    const QString r3eSharedMemoryName("$R3E");

    const wchar_t* acProcessName = L"acs.exe";
    const QString acSharedMemoryNameStatic("acpmf_static");
    const QString acSharedMemoryNamePhysics("acpmf_physics");
    const QString acSharedMemoryNameGraphcics("acpmf_graphics");
}
