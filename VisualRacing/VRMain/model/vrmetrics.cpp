#include "vrmetrics.h"

VRMetrics::VRMetrics()
{
    this->upShiftBehaviour = 0;
}

VRMetrics::~VRMetrics()
{

}

float VRMetrics::getTireSlip() const
{
    return this->tireSlip;
}

void VRMetrics::setTireSlip(float value)
{
    this->tireSlip = value;
    emit tireSlipChanged();
}
