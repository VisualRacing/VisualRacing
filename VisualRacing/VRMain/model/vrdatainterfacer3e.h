#ifndef R3E_DATAINTERFACE_H
#define R3E_DATAINTERFACE_H

#include <math.h>
#include "r3e.h"
#include "vrdatainterface.h"

class VRDataInterfaceR3E : public VRDataInterface
{
private:
    QSharedPointer<QSharedMemory> access;
    r3e_shared* nativeBuffer;

public:
    VRDataInterfaceR3E();
    ~VRDataInterfaceR3E();

    bool start() override;
    void stop() override;

    bool update() override;
};


#endif //R3E_DATAINTERFACE_H
