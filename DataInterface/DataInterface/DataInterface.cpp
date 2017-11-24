#include "datainterface.h"

DataInterface::DataInterface(const wchar_t* processName) {
    this->processName = processName;
    this->buffer = new VRData();
}

DataInterface::~DataInterface() {
    delete this->buffer;
}

const wchar_t* DataInterface::getProcessName(){
    return this->processName;
}
