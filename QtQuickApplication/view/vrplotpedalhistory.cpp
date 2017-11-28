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

void VRPlotPedalHistory::setupPlot(QCustomPlot *customPlot)
{
    // add graph
    customPlot->addGraph();
    customPlot->graph(0)->setPen(QPen(QColor(57, 78, 173), qreal(2.0)));
    customPlot->addGraph();
    customPlot->graph(1)->setPen(QPen(QColor(173, 57, 84), qreal(2.0)));
    customPlot->addGraph();
    customPlot->graph(2)->setPen(QPen(QColor(61, 173, 57), qreal(2.0)));

    // configure xAxis
    QColor lineColor("#a7def9");
    customPlot->xAxis->setLabel("Time in s");
    customPlot->xAxis->setRange(0, 5);
    customPlot->xAxis->setBasePen(QPen(lineColor));
    customPlot->xAxis->setTickPen(QPen(lineColor));
    customPlot->xAxis->setSubTickPen(QPen(lineColor));
    customPlot->xAxis->setTickLabelColor("#a7def9");
    customPlot->xAxis->setLabelColor("#66c0ec");
    customPlot->xAxis->grid()->setPen(QPen(lineColor, 0, Qt::DotLine));

    // prepare y axis:
    customPlot->yAxis->setRange(0, 1);
    customPlot->yAxis->setPadding(5); // a bit more space to the left border
    customPlot->yAxis->setLabel("mechanical deflection");
    customPlot->yAxis->setBasePen(QPen(lineColor));
    customPlot->yAxis->setTickPen(QPen(lineColor));
    customPlot->yAxis->setSubTickPen(QPen(lineColor));
    customPlot->yAxis->grid()->setSubGridVisible(true);
    customPlot->yAxis->setTickLabelColor(lineColor);
    customPlot->yAxis->setLabelColor(lineColor);
    customPlot->yAxis->grid()->setPen(QPen(lineColor, 0, Qt::SolidLine));
    customPlot->yAxis->grid()->setSubGridPen(QPen(lineColor, 0, Qt::DotLine));

    // set bg-color
    customPlot->setBackground(QBrush(QColor("#3e4244")));

    // draw
    customPlot->replot();
}
