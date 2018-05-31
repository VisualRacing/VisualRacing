#include "vrmetrics.h"

VRMetrics::VRMetrics()
{
    this->clutchDisengagedTime = 0l;
    this->avgClutchDisTime = 0l;
    this->gearChangeTime = 0l;
    this->avgGearChangTime = 0l;
    this->diffToAvgShiftTime = 0l;
    this->minClutchDisTime = -1l;
}

VRMetrics::~VRMetrics()
{

}

long VRMetrics::getClutchDisengagedTime() const
{
    return clutchDisengagedTime;
}

void VRMetrics::setClutchDisengagedTime(long value)
{
    clutchDisengagedTime = value;
    emit clutchDisengagedTimeChanged();
}

long VRMetrics::getGearChangeTime() const
{
    return gearChangeTime;
}

void VRMetrics::setGearChangeTime(long value)
{
    gearChangeTime = value;
    emit gearChangeTimeChanged();
}

long VRMetrics::getAvgClutchDisTime() const
{
    return avgClutchDisTime;
}

void VRMetrics::setAvgClutchDisTime(long value)
{
    avgClutchDisTime = value;
    emit avgClutchDisTimeChanged();
}

long VRMetrics::getAvgGearChangTime() const
{
    return avgGearChangTime;
}

void VRMetrics::setAvgGearChangTime(long value)
{
    avgGearChangTime = value;
    emit avgGearChangTimeChanged();
}

long VRMetrics::getDiffToAvgShiftTime() const
{
    return diffToAvgShiftTime;
}

void VRMetrics::setDiffToAvgShiftTime(long value)
{
    diffToAvgShiftTime = value;
    emit diffToAvgShiftTimeChanged();
}

long VRMetrics::getMinClutchDisTime() const
{
    return minClutchDisTime;
}

void VRMetrics::setMinClutchDisTime(long value)
{
    minClutchDisTime = value;
    emit minClutchDisTimeChanged();
}
