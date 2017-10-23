//
// Created by stark on 21-Oct-17.
//

#ifndef VR_AC_DATAINTERFACE_H
#define VR_AC_DATAINTERFACE_H

#include "../DataStructures/Input/ac.h"
#include "DataInterface.h"

class AC_DataInterface : public DataInterface {
private:
    SharedMemoryAccess* accessStatic;
    SharedMemoryAccess* accessPhysics;
    SharedMemoryAccess* accessGraphics;

    SPageFileStatic* nativeBufferStatic;
    SPageFilePhysics* nativeBufferPhysics;
    SPageFileGraphics* nativeBufferGraphics;

public:
    AC_DataInterface();
    ~AC_DataInterface();

    bool start();
    void stop();

    VRData* getBuffer();
    std::string getProcessName();
};


#endif //VR_AC_DATAINTERFACE_H
