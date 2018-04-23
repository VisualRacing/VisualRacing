#ifndef VRPLOTPEDALHISTORY_H
#define VRPLOTPEDALHISTORY_H

#include <QObject>
#include "vrplotitem.h"
#include "vrthemedata.h"

class VRPlotPedalHistory : public VRPlotItem
{
    Q_OBJECT
public:
    VRPlotPedalHistory();

    virtual void setupPlot(QCustomPlot* customPlot, VRThemeData* themeData);
    virtual void setTheme(VRThemeData* themeData);

    Q_INVOKABLE void pushData(double index, double clutch, double breaking, double throttle);

public slots:
    void changeLanguage();

};

#endif // VRPLOTPEDALHISTORY_H
