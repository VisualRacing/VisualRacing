#include "vrplotlaptimebar.h"
#include <QDebug>

VRPlotLapTimeBar::VRPlotLapTimeBar() : VRPlotItem()
{

}

void VRPlotLapTimeBar::pushData(double lap_time, double sector1, double sector2, double sector3, double best)
{

    // add lap_time
    sum_vect.append(lap_time);

    // update counter and labels
    ++counter;
    ticks.append(counter);
    QString str_counter = QString::number(counter);
    labels.prepend("lap " + str_counter);

    // set the ticker labels
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->setTicks(ticks, labels);
    itsCustomPlot->xAxis->setTicker(textTicker);

    // push data into the vector
    sectorOne_data.prepend(sector1);
    sectorTwo_data.prepend(sector2);
    sectorThree_data.prepend(sector3);

    // limit the showen data to 10 bars
    if(ticks.size() > 10){
        sum_vect.pop_front();
        ticks.pop_back();
        labels.pop_back();
        sectorOne_data.pop_back();
        sectorTwo_data.pop_back();
        sectorThree_data.pop_back();
    }

    // set the new data
    sectorOne->setData(ticks, sectorOne_data);
    sectorTwo->setData(ticks, sectorTwo_data);
    sectorThree->setData(ticks, sectorThree_data);

    // stack the bars
    sectorThree->moveAbove(sectorTwo);
    sectorTwo->moveAbove(sectorOne);

    QVector<double> x, y;
    x << 0 << 12;
    y << best << best;
    itsCustomPlot->graph(0)->setData(x, y);

    itsCustomPlot->yAxis->setRange(0, *std::max_element(sum_vect.constBegin(), sum_vect.constEnd()));
    itsCustomPlot->replot();

}

void VRPlotLapTimeBar::setupPlot(QCustomPlot *customPlot)
{
    // init QCPBars
    sectorOne = new QCPBars(customPlot->xAxis, customPlot->yAxis);
    sectorTwo = new QCPBars(customPlot->xAxis, customPlot->yAxis);
    sectorThree = new QCPBars(customPlot->xAxis, customPlot->yAxis);

    // stack the bars
    sectorThree->moveAbove(sectorTwo);
    sectorTwo->moveAbove(sectorOne);

    // style
    sectorOne->setName("Sector 1");
    sectorOne->setPen(QPen(QColor(82, 85, 181)));
    sectorOne->setBrush(QColor(82, 85, 181));
    sectorOne->setWidth(0.4);
    sectorTwo->setName("Sector 2");
    sectorTwo->setPen(QPen(QColor(98, 109, 255)));
    sectorTwo->setBrush(QColor(98, 109, 255));
    sectorTwo->setWidth(0.4);
    sectorThree->setName("Sector 3");
    sectorThree->setPen(QPen(QColor(160, 167, 255)));
    sectorThree->setBrush(QColor(160, 167, 255));
    sectorThree->setWidth(0.4);

    // add graph
    customPlot->addGraph();
    customPlot->graph(0)->setPen(QPen(QColor("#ffa500"), qreal(2.0)));

    // set bg-color
    customPlot->setBackground(QBrush(QColor("#3e4244")));

    QColor lineColor("#a7def9");
    // prepare x axis:
    customPlot->xAxis->setSubTicks(false);
    customPlot->xAxis->setTickLength(0, 11);
    customPlot->xAxis->setRange(0, 11);
    customPlot->xAxis->setBasePen(QPen(lineColor));
    customPlot->xAxis->setTickPen(QPen(lineColor));
    customPlot->xAxis->grid()->setVisible(true);
    customPlot->xAxis->grid()->setPen(QPen(lineColor, 0, Qt::DotLine));
    customPlot->xAxis->setTickLabelColor(lineColor);
    customPlot->xAxis->setLabelColor(lineColor);

    // prepare y axis:
    customPlot->yAxis->setRange(0, 0);
    customPlot->yAxis->setPadding(2); // a bit more space to the left border
    customPlot->yAxis->setLabel("Time in s");
    customPlot->yAxis->setBasePen(QPen(lineColor));
    customPlot->yAxis->setTickPen(QPen(lineColor));
    customPlot->yAxis->setSubTickPen(QPen(lineColor));
    customPlot->yAxis->setTickLabelColor(lineColor);
    customPlot->yAxis->setLabelColor(lineColor);
    customPlot->yAxis->grid()->setPen(QPen(lineColor, 0, Qt::DotLine));

}
