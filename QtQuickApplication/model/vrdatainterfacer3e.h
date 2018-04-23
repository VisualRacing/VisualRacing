#ifndef R3E_DATAINTERFACE_H
#define R3E_DATAINTERFACE_H

#include <math.h>
#include "r3e.h"
#include "vrdatainterface.h"
#include "vrdata.h"

class VRDataInterfaceR3E : public VRDataInterface
{
private:
    QSharedPointer<QSharedMemory> access;
    r3e_shared* nativeBuffer;

public:
    VRDataInterfaceR3E(QSharedPointer<VRData> vrData);
    ~VRDataInterfaceR3E();

    bool start() override;
    void stop() override;

    bool update() override;
};


#endif //R3E_DATAINTERFACE_H
