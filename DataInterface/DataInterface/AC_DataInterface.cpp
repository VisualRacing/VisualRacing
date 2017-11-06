//
// Created by stark on 21-Oct-17.
//

#include "AC_DataInterface.h"

AC_DataInterface::AC_DataInterface() : DataInterface(constants::acProcessName) {
    this->accessStatic = new SharedMemoryAccess(constants::acSharedMemoryNameStatic, sizeof(SPageFileStatic));
    this->accessPhysics = new SharedMemoryAccess(constants::acSharedMemoryNamePhysics, sizeof(SPageFilePhysics));
    this->accessGraphics = new SharedMemoryAccess(constants::acSharedMemoryNameGraphcics, sizeof(SPageFileGraphics));
}

AC_DataInterface::~AC_DataInterface() {
    delete this->accessStatic;
    delete this->accessPhysics;
    delete this->accessGraphics;
}

bool AC_DataInterface::start() {
    if (this->accessStatic->open())
        this->nativeBufferStatic = (SPageFileStatic*)this->accessStatic->getBuffer();
    else {
        return false;
    }

    if (this->accessPhysics->open())
        this->nativeBufferPhysics = (SPageFilePhysics*)this->accessPhysics->getBuffer();
    else {
        this->accessStatic->close();
        return false;
    }

    if(this->accessGraphics->open())
        this->nativeBufferGraphics = (SPageFileGraphics*)this->accessGraphics->getBuffer();
    else {
        this->accessStatic->close();
        this->accessPhysics->close();
        return false;
    }

    return true;
}

void AC_DataInterface::stop() {
    this->accessStatic->close();
    this->accessPhysics->close();
    this->accessGraphics->close();
}

VRData* AC_DataInterface::getBuffer() {
    if(!this->accessStatic->opened() || !this->accessPhysics->opened() || !this->accessGraphics->opened())
        return nullptr;

    { // This is where the mapping happens.
        this->buffer->gear = this->nativeBufferPhysics->gear - 1;
    }

    return this->buffer;
}