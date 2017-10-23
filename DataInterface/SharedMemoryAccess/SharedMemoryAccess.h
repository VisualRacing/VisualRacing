//
// Created by stark on 21-Oct-17.
//

#ifndef VR_SHAREDMEMORYACCESS_H
#define VR_SHAREDMEMORYACCESS_H

#include "../main.h"

class SharedMemoryAccess {
private:
    HANDLE handle;
    void* buffer;
    std::string sharedMemoryName;
    int size;
    bool isOpen;

public:

    SharedMemoryAccess(std::string sharedMemoryName, int size);
    ~SharedMemoryAccess();

    bool open();
    bool opened();
    void close();

    void* getBuffer();
};


#endif //VR_SHAREDMEMORYACCESS_H
