#ifndef VRPLOTPEDALS_H
#define VRPLOTPEDALS_H

#include <QObject>
#include "vrplotitem.h"
#include "vrthemedata.h"

class VRPlotPedals : public VRPlotItem
{
    Q_OBJECT
public:
    VRPlotPedals();

    virtual void setupPlot(QCustomPlot* customPlot, VRThemeData* themData);
    virtual void setTheme(VRThemeData* themeData);

    Q_INVOKABLE void pushData(double clutch, double brake, double accel);

    QCPBars* clutchPedal;
    QCPBars* accelPedal;
    QCPBars* brakePedal;
};

#endif // VRPLOTPEDALS_H
