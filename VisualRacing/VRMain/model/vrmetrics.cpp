#include "vrmetrics.h"

VRMetrics::VRMetrics()
{
    this->accelBehav = 0;
    this->avgAccelBehav = 0;
}

VRMetrics::~VRMetrics()
{

}

float VRMetrics::getAccelBehav() const
{
    return this->accelBehav;
}

void VRMetrics::setAccelBehav(float value)
{
    this->accelBehav = value;
    emit this->accelBehavChanged();
}

float VRMetrics::getAvgAccelBehav() const
{
    return this->avgAccelBehav;
}

void VRMetrics::setAvgAccelBehav(float value)
{
    this->avgAccelBehav = value;
    emit this->avgAccelBehavChanged();
}
