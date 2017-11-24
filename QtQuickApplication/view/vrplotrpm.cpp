#include "vrplotrpm.h"

VRPlotRPM::VRPlotRPM()
{

}

void VRPlotRPM::pushData(double index, double data, int gear)
{
    // push data to graph
    itsCustomPlot->graph(0)->addData(index, data);

    if(gear != itsLastGear){
        itsLastGear = gear;
        itsLastGearDouble = (gear * itsGearMultiplier) + (2 * itsGearMultiplier);
    }
    itsCustomPlot->graph(1)->addData(index, itsLastGearDouble);

    // make index axis range scroll with the data (at a constant range size of 10):
    itsCustomPlot->xAxis->setRange(index, index, Qt::AlignRight);
    itsCustomPlot->replot();
}

void VRPlotRPM::setItsMaxRpm(int maxRpm)
{
    this->itsMaxRpm = maxRpm;
    this->itsGearMultiplier = itsMaxRpm / 9;           // 8 gears
    this->itsLastGearDouble = itsGearMultiplier;
    itsCustomPlot->yAxis->setRange(0, itsMaxRpm);
    itsCustomPlot->replot();
}

void VRPlotRPM::setupPlot(QCustomPlot *customPlot)
{
    // add graph
    customPlot->addGraph();
    customPlot->graph(0)->setPen(QPen(QColor("#ffa500")));
    customPlot->addGraph();
    customPlot->graph(1)->setPen(QPen(QColor("#10ff10")));

    // set axis labels
    customPlot->xAxis->setLabel("time in min");
    customPlot->yAxis->setLabel("RPM / gear");

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
    customPlot->yAxis->setRange(0, itsMaxRpm);
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
}
