#ifndef VRPLOTVELOCITY_H
#define VRPLOTVELOCITY_H

#include <QObject>
#include "vrplotitem.h"
#include "vrthemedata.h"

class VRPlotVelocity : public VRPlotItem
{
    Q_OBJECT
public:
    VRPlotVelocity();

    virtual void setupPlot( QCustomPlot* customPlot, VRThemeData* themeData);
    virtual void setTheme(VRThemeData *themeData);
    Q_INVOKABLE void pushData(double index, double data);

};

#endif // VRPLOTVELOCITY_H
