//
// Created by stark on 21-Oct-17.
//

#include "R3E_DataInterface.h"

R3E_DataInterface::R3E_DataInterface() : DataInterface() {
    this->access = new SharedMemoryAccess(R3E_SHARED_MEMORY_NAME, sizeof(r3e_shared));
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

std::string R3E_DataInterface::getProcessName() {
    return R3E_PROCESS_NAME;
}