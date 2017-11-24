#ifndef R3E_DATAINTERFACE_H
#define R3E_DATAINTERFACE_H

#include "DataStructures/Input/r3e.h"
#include "datainterface.h"

class R3E_DataInterface : public DataInterface {
private:
    QSharedMemory* access;
    r3e_shared* nativeBuffer;

public:
    R3E_DataInterface();
    ~R3E_DataInterface();

    bool start() override;
    void stop() override;

    VRData* getBuffer() override;
};


#endif //R3E_DATAINTERFACE_H
