#ifndef AC_DATAINTERFACE_H
#define AC_DATAINTERFACE_H

#include "DataStructures/input/ac.h"
#include "datainterface.h"

class AC_DataInterface : public DataInterface {
private:
    QSharedMemory* accessStatic;
    QSharedMemory* accessPhysics;
    QSharedMemory* accessGraphics;

    SPageFileStatic* nativeBufferStatic;
    SPageFilePhysics* nativeBufferPhysics;
    SPageFileGraphics* nativeBufferGraphics;

public:
    AC_DataInterface();
    ~AC_DataInterface();

    bool start() override;
    void stop() override;

    VRData* getBuffer() override;
};


#endif //AC_DATAINTERFACE_H
