#ifndef VRPLOTITEM_H
#define VRPLOTITEM_H

#include <QtQuick>
#include "qcustomplot.h"
#include "vrthemedata.h"

class VRPlotItem : public QQuickPaintedItem
{
    Q_OBJECT

public:
    VRPlotItem( QQuickItem* parent = 0 );
    virtual ~VRPlotItem();

    void paint( QPainter* painter );

    // can be called from qml to init the plot
    Q_INVOKABLE virtual void initCustomPlot(VRThemeData* themeData);

protected:
    virtual void setupPlot( QCustomPlot* customPlot, VRThemeData* themeData) = 0;
    Q_INVOKABLE virtual void setTheme(VRThemeData* themeData) = 0;

    void routeMouseEvents( QMouseEvent* event );

    virtual void mousePressEvent( QMouseEvent* event );
    virtual void mouseReleaseEvent( QMouseEvent* event );
    virtual void mouseMoveEvent( QMouseEvent* event );
    virtual void mouseDoubleClickEvent( QMouseEvent* event );

protected:
    QCustomPlot* itsCustomPlot;

protected slots:
    void graphClicked( QCPAbstractPlottable* plottable );
    void onCustomReplot();
    void updateCustomPlotSize();

};

#endif // VRPLOTITEM_H
