#include "vrplotvelocity.h"

VRPlotVelocity::VRPlotVelocity() : VRPlotItem()
{

}

void VRPlotVelocity::pushData(double index, double data)
{
    // push data to graph
    itsCustomPlot->graph(0)->addData(index, data);

    // make index axis range scroll with the data (at a constant range size of 10):
    itsCustomPlot->xAxis->setRange(index, 10, Qt::AlignRight);
    itsCustomPlot->replot();
}

void VRPlotVelocity::setupPlot(QCustomPlot *customPlot)
{
    // add graph
    customPlot->addGraph();
    customPlot->graph(0)->setPen(QPen(QColor("#3399dd")));

    // set axis labels
    customPlot->xAxis->setLabel("time in min");
    customPlot->yAxis->setLabel("Speed in kmh");

    // configure xAxis
    QColor lineColor("#a7def9");
    customPlot->xAxis->setRange(0, 10);
    customPlot->xAxis->setBasePen(QPen(lineColor));
    customPlot->xAxis->setTickPen(QPen(lineColor));
    customPlot->xAxis->setSubTickPen(QPen(lineColor));
    customPlot->xAxis->setTickLabelColor("#a7def9");
    customPlot->xAxis->setLabelColor("#66c0ec");
    customPlot->xAxis->grid()->setPen(QPen(lineColor, 0, Qt::DotLine));

    // cofigure yAxis
    customPlot->yAxis->setRange(0, 350);
    customPlot->yAxis->setBasePen(QPen(lineColor));
    customPlot->yAxis->setTickPen(QPen(lineColor));
    customPlot->yAxis->setSubTickPen(QPen(lineColor));
    customPlot->yAxis->setTickLabelColor("#a7def9");
    customPlot->yAxis->setLabelColor("#a7def9");
    customPlot->yAxis->grid()->setPen(QPen(lineColor, 0, Qt::DotLine));

    // set bg-color
    customPlot->setBackground(QBrush(QColor("#3e4244")));

    // draw
    customPlot->replot();

    // connect mouse interaction
    // customPlot ->setInteractions( QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables );
    // connect( customPlot, SIGNAL( plottableClick( QCPAbstractPlottable*, int,  QMouseEvent* ) ), this, SLOT( graphClicked( QCPAbstractPlottable* ) ) );

}
