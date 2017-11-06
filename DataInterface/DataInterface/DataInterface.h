//
// Created by stark on 21-Oct-17.
//

#ifndef VR_DATAINTERFACE_H
#define VR_DATAINTERFACE_H

#include "../DataStructures/Output/vr.h"
#include "../SharedMemoryAccess/SharedMemoryAccess.h"

class DataInterface {
protected:
    std::string processName;
    VRData* buffer;
public:
    DataInterface(std::string processName);
    virtual ~DataInterface();

    virtual bool start() = 0;
    virtual void stop() = 0;

    virtual VRData* getBuffer() = 0;
    std::string getProcessName();
};


#endif //VR_DATAINTERFACE_H
