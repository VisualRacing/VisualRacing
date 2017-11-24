#ifndef VRPLOTPEDALHISTORY_H
#define VRPLOTPEDALHISTORY_H

#include <QObject>
#include "vrplotitem.h"

class VRPlotPedalHistory : public VRPlotItem
{
    Q_OBJECT
public:
    VRPlotPedalHistory();

    virtual void setupPlot( QCustomPlot* customPlot );

    Q_INVOKABLE void pushData(double index, double clutch, double breaking, double throttle);

};

#endif // VRPLOTPEDALHISTORY_H
