#include "vrplotvelocity.h"

VRPlotVelocity::VRPlotVelocity() : VRPlotItem()
{

}

void VRPlotVelocity::pushData(double index, double data)
{
    // push data to graph
    itsCustomPlot->graph(0)->addData(index, data);

    // make index axis range scroll with the data (at a constant range size of 10):
    itsCustomPlot->xAxis->setRange(index, 30, Qt::AlignRight);
    itsCustomPlot->replot();
}

void VRPlotVelocity::setTheme(VRThemeData *themeData)
{
    QColor lineColor(themeData->getAccentColor());

    itsCustomPlot->xAxis->setBasePen(QPen(lineColor));
    itsCustomPlot->xAxis->setTickPen(QPen(lineColor));
    itsCustomPlot->xAxis->setSubTickPen(QPen(lineColor));
    itsCustomPlot->xAxis->setTickLabelColor(lineColor);
    itsCustomPlot->xAxis->setLabelColor(lineColor);
    itsCustomPlot->xAxis->grid()->setPen(QPen(lineColor, 0, Qt::DotLine));

    itsCustomPlot->yAxis->setBasePen(QPen(lineColor));
    itsCustomPlot->yAxis->setTickPen(QPen(lineColor));
    itsCustomPlot->yAxis->setSubTickPen(QPen(lineColor));
    itsCustomPlot->yAxis->setTickLabelColor(lineColor);
    itsCustomPlot->yAxis->setLabelColor(lineColor);
    itsCustomPlot->yAxis->grid()->setPen(QPen(lineColor, 0, Qt::DotLine));

    itsCustomPlot->setBackground(QBrush(QColor(themeData->getTabBackgroundColor())));

    itsCustomPlot->replot();
}

void VRPlotVelocity::setupPlot(VRThemeData* themeData)
{
    // add graph
    itsCustomPlot->addGraph();
    itsCustomPlot->graph(0)->setPen(QPen(QColor("#3aaefc"), qreal(2.0)));

    // set axis labels
    itsCustomPlot->xAxis->setLabel(tr("Time in s"));
    itsCustomPlot->yAxis->setLabel(tr("Speed in km/h"));

    // configure xAxis
    itsCustomPlot->xAxis->setRange(0, 30);

    // cofigure yAxis
    itsCustomPlot->yAxis->setRange(0, 350);

    // set theme (also does a replot-call)
    setTheme(themeData);

    // connect mouse interaction
    // itsCustomPlot ->setInteractions( QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables );
    // connect( itsCustomPlot, SIGNAL( plottableClick( QCPAbstractPlottable*, int,  QMouseEvent* ) ), this, SLOT( graphClicked( QCPAbstractPlottable* ) ) );

}

void VRPlotVelocity::changeLanguage()
{
    itsCustomPlot->xAxis->setLabel(tr("Time in s"));
    itsCustomPlot->yAxis->setLabel(tr("Speed in km/h"));
}
