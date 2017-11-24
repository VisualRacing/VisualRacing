#include "vrdatainterfacer3e.h"

VRDataInterfaceR3E::VRDataInterfaceR3E() : VRDataInterface(vrconstants::r3eProcessName) {
    this->access = QSharedPointer<QSharedMemory>(new QSharedMemory());
    this->access->setNativeKey(vrconstants::r3eSharedMemoryName);
}

VRDataInterfaceR3E::~VRDataInterfaceR3E() {
    this->stop();
}

bool VRDataInterfaceR3E::start() {
    bool success = this->access->attach(QSharedMemory::AccessMode::ReadOnly);
    if (success)
        this->nativeBuffer = (r3e_shared*)this->access->data();

    return success;
}

void VRDataInterfaceR3E::stop() {
    this->access->detach();
}

bool VRDataInterfaceR3E::update() {
    if (!this->access->isAttached())
        return false;

    // TODO: Static information like playerName, carName and trackName do not need to be set every update.

    this->buffer->setGear((this->nativeBuffer->gear == -2 ? 0 : this->nativeBuffer->gear));
    this->buffer->setVelocity(qMax(this->nativeBuffer->car_speed * 3.6f, 0.0f)); // Conversion from m/s to km/h
    this->buffer->setRpm(qMax(this->nativeBuffer->engine_rps * (60 / (2 * M_PI)), 0.0)); // Conversion from rps to rpm
    this->buffer->setMaxRpm(qMax(this->nativeBuffer->max_engine_rps * (60 / (2 * M_PI)), 1.0)); // Conversion from rps to rpm

    return true;
}
