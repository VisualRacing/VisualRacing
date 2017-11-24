#ifndef VRPLOTRPM_H
#define VRPLOTRPM_H

#include <QObject>
#include "vrplotitem.h"

class VRPlotRPM : public VRPlotItem
{
    Q_OBJECT
public:
    VRPlotRPM();

    virtual void setupPlot( QCustomPlot* customPlot );
    Q_INVOKABLE void setItsMaxRpm(int maxRpm);
    Q_INVOKABLE void pushData(double index, double data, int gear);

private:
    int itsMaxRpm = 8000;
    double itsGearMultiplier;

    int itsLastGear = 0;
    double itsLastGearDouble = 0;

};

#endif // VRPLOTRPM_H
