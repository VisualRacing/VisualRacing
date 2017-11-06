//
// Created by stark on 21-Oct-17.
//

#ifndef VR_R3E_DATAINTERFACE_H
#define VR_R3E_DATAINTERFACE_H

#include "../DataStructures/Input/r3e.h"
#include "DataInterface.h"

class R3E_DataInterface : public DataInterface {
private:
    SharedMemoryAccess* access;
    r3e_shared* nativeBuffer;

public:
    R3E_DataInterface();
    ~R3E_DataInterface();

    bool start() override;
    void stop() override;

    VRData* getBuffer() override;
};


#endif //VR_R3E_DATAINTERFACE_H
