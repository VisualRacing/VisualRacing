#include "vrdata.h"

int VRData::getGear() const
{
    return gear;
}

void VRData::setGear(int value)
{
    if (gear == value)
        return;

    gear = value;
    emit gearChanged();
}

float VRData::getVelocity() const
{
    return velocity;
}

void VRData::setVelocity(float value)
{
    if (velocity == value)
        return;

    velocity = value;
    emit velocityChanged();
}

int VRData::getRpm() const
{
    return rpm;
}

void VRData::setRpm(int value)
{
    if (rpm == value)
        return;

    rpm = value;
    emit rpmChanged();
}

int VRData::getMaxRpm() const
{
    return maxRpm;
}

void VRData::setMaxRpm(int value)
{
    if (maxRpm == value)
        return;

    maxRpm = value;
    emit maxRpmChanged();
}
