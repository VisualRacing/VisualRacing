//
// Created by stark on 21-Oct-17.
//

#include "R3E_DataInterface.h"

R3E_DataInterface::R3E_DataInterface() : DataInterface(constants::r3eProcessName) {
    this->access = new SharedMemoryAccess(constants::r3eSharedMemoryName, sizeof(r3e_shared));
}

R3E_DataInterface::~R3E_DataInterface() {
    delete this->access;
}

bool R3E_DataInterface::start() {
    bool success = this->access->open();
    if (success)
        this->nativeBuffer = (r3e_shared*)this->access->getBuffer();

    return success;
}

void R3E_DataInterface::stop() {
    this->access->close();
}

VRData* R3E_DataInterface::getBuffer() {
    if (!this->access->opened())
        return nullptr;

    { // This is where the mapping happens.
        this->buffer->gear = this->nativeBuffer->gear;
    }

    return this->buffer;
}