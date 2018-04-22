#include "vrplotpedalhistory.h"

VRPlotPedalHistory::VRPlotPedalHistory()
{

}

void VRPlotPedalHistory::pushData(double index, double clutch, double brake, double throttle)
{
    // push data to graph
    itsCustomPlot->graph(0)->addData(index, clutch);
    itsCustomPlot->graph(1)->addData(index, brake);
    itsCustomPlot->graph(2)->addData(index, throttle);

    // make index axis range scroll with the data (at a constant range size of 10):
    itsCustomPlot->xAxis->setRange(index, 5, Qt::AlignRight);
    itsCustomPlot->replot();
}

void VRPlotPedalHistory::setTheme(VRThemeData *themeData)
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
    itsCustomPlot->yAxis->grid()->setPen(QPen(lineColor, 0, Qt::SolidLine));
    itsCustomPlot->yAxis->grid()->setSubGridPen(QPen(lineColor, 0, Qt::DotLine));

    itsCustomPlot->setBackground(QBrush(QColor(themeData->getTabBackgroundColor())));

    itsCustomPlot->replot();
}

void VRPlotPedalHistory::setupPlot(QCustomPlot *customPlot, VRThemeData* themeData)
{
    // add graph
    customPlot->addGraph();
    customPlot->graph(0)->setPen(QPen(QColor(57, 78, 173), qreal(2.0)));
    customPlot->addGraph();
    customPlot->graph(1)->setPen(QPen(QColor(173, 57, 84), qreal(2.0)));
    customPlot->addGraph();
    customPlot->graph(2)->setPen(QPen(QColor(61, 173, 57), qreal(2.0)));

    // configure xAxis
    customPlot->xAxis->setLabel(tr("Time in s"));
    customPlot->xAxis->setRange(0, 5);

    // prepare y axis:
    customPlot->yAxis->setRange(0, 1);
    customPlot->yAxis->setPadding(5); // a bit more space to the left border
    customPlot->yAxis->setLabel(tr("Mechanical deflection"));
    customPlot->yAxis->grid()->setSubGridVisible(true);

    // set theme (also does a replot-call)
    setTheme(themeData);
}
