#include "vrdata.h"

VRData::VRData()
{
    this->startTime = VRUtilities::getCurrentTime();

    this->gear = 0;
    this->velocity = 0.0f;
    this->rpm = 0;
    this->maxRpm = 0;

    this->throttle = 0.0f;
    this->brake = 0.0f;
    this->clutch = 0.0f;

    this->completedLaps = 0;

    this->fuel = 0.0f;
    this->maxFuel = 0.0f;

    this->pitLimiter = false;
    this->isInPitlane = false;
}

double VRData::getTimeInSeconds()
{
    std::chrono::milliseconds now = VRUtilities::getCurrentTime();
    return (now.count() - startTime.count()) * 0.001;
}

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

float VRData::getThrottle() const
{
    return throttle;
}

void VRData::setThrottle(float value)
{
    if (throttle == value)
        return;

    throttle = value;
    emit throttleChanged();
}

float VRData::getBrake() const
{
    return brake;
}

void VRData::setBrake(float value)
{
    if (brake == value)
        return;

    brake = value;
    emit brakeChanged();
}

float VRData::getClutch() const
{
    return clutch;
}

void VRData::setClutch(float value)
{
    if (clutch == value)
        return;

    clutch = value;
    emit clutchChanged();
}

int VRData::getCompletedLaps() const
{
    return completedLaps;
}

void VRData::setCompletedLaps(int value)
{
    if (completedLaps == value)
        return;

    completedLaps = value;
    emit completedLapsChanged();
}

float VRData::getFuel() const
{
    return fuel;
}

void VRData::setFuel(float value)
{
    if (fuel == value)
        return;

    fuel = value;
    emit fuelChanged();
}

float VRData::getMaxFuel() const
{
    return maxFuel;
}

void VRData::setMaxFuel(float value)
{
    if (maxFuel == value)
        return;

    maxFuel = value;
    emit maxFuelChanged();
}

bool VRData::getPitLimiter() const
{
    return pitLimiter;
}

void VRData::setPitLimiter(bool value)
{
    if (pitLimiter == value)
        return;

    pitLimiter = value;
    emit pitLimiterChanged();
}

bool VRData::getIsInPitlane() const
{
    return isInPitlane;
}

void VRData::setIsInPitlane(bool value)
{
    if (isInPitlane == value)
        return;

    isInPitlane = value;
    emit isInPitlaneChanged();
}

float VRData::getBrakeBias() const
{
    return brakeBias;
}

void VRData::setBrakeBias(float value)
{
    if (brakeBias == value)
        return;

    brakeBias = value;
    emit brakeBiasChanged();
}
