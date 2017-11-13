//
// Created by stark on 21-Oct-17.
//

#include "ac_datainterface.h"

AC_DataInterface::AC_DataInterface() : DataInterface(constants::acProcessName) {
    this->accessStatic = new QSharedMemory();
    this->accessStatic->setNativeKey(constants::acSharedMemoryNameStatic);

    this->accessPhysics = new QSharedMemory();
    this->accessPhysics->setNativeKey(constants::acSharedMemoryNamePhysics);

    this->accessGraphics = new QSharedMemory();
    this->accessGraphics->setNativeKey(constants::acSharedMemoryNameGraphcics);
}

AC_DataInterface::~AC_DataInterface() {
    this->stop();
    delete this->accessStatic;
    delete this->accessPhysics;
    delete this->accessGraphics;
}

bool AC_DataInterface::start() {
    // TODO: Print more detailed error descriptions.
    if (this->accessStatic->attach(QSharedMemory::AccessMode::ReadOnly))
        this->nativeBufferStatic = (SPageFileStatic*)this->accessStatic->data();
    else {
        return false;
    }

    if (this->accessPhysics->attach(QSharedMemory::AccessMode::ReadOnly))
        this->nativeBufferPhysics = (SPageFilePhysics*)this->accessPhysics->data();
    else {
        this->accessStatic->detach();
        return false;
    }

    if(this->accessGraphics->attach(QSharedMemory::AccessMode::ReadOnly))
        this->nativeBufferGraphics = (SPageFileGraphics*)this->accessGraphics->data();
    else {
        this->accessStatic->detach();
        this->accessPhysics->detach();
        return false;
    }

    return true;
}

void AC_DataInterface::stop() {
    this->accessStatic->detach();
    this->accessPhysics->detach();
    this->accessGraphics->detach();
}

VRData* AC_DataInterface::getBuffer() {
    if(!this->accessStatic->isAttached() || !this->accessPhysics->isAttached() || !this->accessGraphics->isAttached())
        return nullptr;

    { // This is where the mapping happens.
        // TODO: Static information like playerName, carName and trackName do not need to be set every update.

        this->buffer->completedLaps = this->nativeBufferGraphics->completedLaps;

        this->buffer->gear = this->nativeBufferPhysics->gear - 1; // TODO: Is -1 what we want?
        this->buffer->velocity = this->nativeBufferPhysics->speedKmh;

        this->buffer->rpm = this->nativeBufferPhysics->rpms;
        this->buffer->maxRpm = this->nativeBufferStatic->maxRpm;

        this->buffer->throttle = this->nativeBufferPhysics->gas;
        this->buffer->brake = this->nativeBufferPhysics->brake;
        this->buffer->clutch = this->nativeBufferPhysics->clutch;
    }

    return this->buffer;
}
