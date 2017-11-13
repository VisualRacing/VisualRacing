#include "r3e_datainterface.h"

R3E_DataInterface::R3E_DataInterface() : DataInterface(constants::r3eProcessName) {
    this->access = new QSharedMemory();
    this->access->setNativeKey(constants::r3eSharedMemoryName);
}

R3E_DataInterface::~R3E_DataInterface() {
    this->stop();
    delete this->access;
}

bool R3E_DataInterface::start() {
    bool success = this->access->attach(QSharedMemory::AccessMode::ReadOnly);
    if (success)
        this->nativeBuffer = (r3e_shared*)this->access->data();

    return success;
}

void R3E_DataInterface::stop() {
    this->access->detach();
}

VRData* R3E_DataInterface::getBuffer() {
    if (!this->access->isAttached())
        return nullptr;

    { // This is where the mapping happens.
        this->buffer->gear = this->nativeBuffer->gear;
    }

    return this->buffer;
}
