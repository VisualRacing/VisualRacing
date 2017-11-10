#ifndef VRPLOTVELOCITY_H
#define VRPLOTVELOCITY_H

#include <QObject>
#include "vrplotitem.h"

class VRPlotVelocity : public VRPlotItem
{
    Q_OBJECT
public:
    VRPlotVelocity();

    virtual void setupPlot( QCustomPlot* customPlot );

    Q_INVOKABLE void pushData(double index, double data, double data2);

};

#endif // VRPLOTVELOCITY_H
