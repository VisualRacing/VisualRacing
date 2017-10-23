//
// Created by stark on 21-Oct-17.
//

#ifndef VR_UTILITIES_H
#define VR_UTILITIES_H

#include "../main.h"
#include <TlHelp32.h>
#include <tchar.h>

class Utilities {
public:
    static bool isProcessRunning(std::string name);
};


#endif //VR_UTILITIES_H
