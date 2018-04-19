#include "vrdatainterface.h"

VRDataInterface::VRDataInterface(const wchar_t* processName, QSharedPointer<VRData> vrData) {
    this->processName = processName;
    this->buffer = vrData;
}

VRDataInterface::~VRDataInterface() {
}

QSharedPointer<VRData> VRDataInterface::getBuffer() {
    return this->buffer;
}

const wchar_t* VRDataInterface::getProcessName(){
    return this->processName;
}
