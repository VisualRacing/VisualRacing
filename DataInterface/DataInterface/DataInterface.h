#ifndef DATAINTERFACE_H
#define DATAINTERFACE_H

#include <QSharedMemory>

#include "main.h"
#include "DataStructures/Output/vrdata.h"

class DataInterface {
private:
    const wchar_t* processName;
protected:
    VRData* buffer;
public:
    DataInterface(const wchar_t* processName);
    virtual ~DataInterface();

    virtual bool start() = 0;
    virtual void stop() = 0;

    virtual VRData* getBuffer() = 0;
    const wchar_t* getProcessName();
};


#endif //DATAINTERFACE_H
