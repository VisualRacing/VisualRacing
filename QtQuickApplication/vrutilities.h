#ifndef UTILITIES_H
#define UTILITIES_H

#include <Windows.h>
#include <tlhelp32.h>
#include <chrono>

class VRUtilities {
public:
    static bool isProcessRunning(const wchar_t* name);
    static std::chrono::milliseconds getCurrentTime();
};


#endif //UTILITIES_H
