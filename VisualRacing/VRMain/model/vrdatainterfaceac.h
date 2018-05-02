#ifndef AC_DATAINTERFACE_H
#define AC_DATAINTERFACE_H

#include "ac.h"
#include "vrdatainterface.h"

class VRDataInterfaceAC : public VRDataInterface {
private:
    QSharedPointer<QSharedMemory> accessStatic;
    QSharedPointer<QSharedMemory> accessPhysics;
    QSharedPointer<QSharedMemory> accessGraphics;

    SPageFileStatic* nativeBufferStatic;
    SPageFilePhysics* nativeBufferPhysics;
    SPageFileGraphics* nativeBufferGraphics;

public:
    VRDataInterfaceAC();
    ~VRDataInterfaceAC();

    bool start() override;
    void stop() override;

    bool update() override;
};


#endif //AC_DATAINTERFACE_H
