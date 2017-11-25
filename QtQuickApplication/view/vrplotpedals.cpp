#include "vrplotpedals.h"

VRPlotPedals::VRPlotPedals() : VRPlotItem()
{

}

void VRPlotPedals::pushData(int clutch, int brake, int accel)
{
    QVector<double> ticks_vect_clutch;
    QVector<double> ticks_vect_brak;
    QVector<double> ticks_vect_acc;
    ticks_vect_clutch << 1;
    ticks_vect_brak << 2;
    ticks_vect_acc << 3;

    QVector<double> clutch_data, brake_data, accel_data;
    clutch_data << clutch;
    brake_data << brake;
    accel_data << accel;

    clutchPedal->setData(ticks_vect_clutch, clutch_data);
    brakePedal->setData(ticks_vect_brak, brake_data);
    accelPedal->setData(ticks_vect_acc, accel_data);

    itsCustomPlot->replot();
}

void VRPlotPedals::setupPlot(QCustomPlot *customPlot)
{
    // set dark background gradient:
    customPlot->setBackground(QBrush(QColor("#3e4244")));

    // init QCPBars
    clutchPedal = new QCPBars(customPlot->xAxis, customPlot->yAxis);
    accelPedal = new QCPBars(customPlot->xAxis, customPlot->yAxis);
    brakePedal = new QCPBars(customPlot->xAxis, customPlot->yAxis);

    // set Names and Colors
    clutchPedal->setName("Clutch Pedal");
    clutchPedal->setPen(QPen(QColor(57, 78, 173).lighter(170)));
    clutchPedal->setBrush(QColor(57, 78, 173));

    brakePedal->setName("Brake Pedal");
    brakePedal->setPen(QPen(QColor(173, 57, 84).lighter(170)));
    brakePedal->setBrush(QColor(173, 57, 84));

    accelPedal->setName("Acceleration Pedal");
    accelPedal->setPen(QPen(QColor(61, 173, 57).lighter(170)));
    accelPedal->setBrush(QColor(61, 173, 57));

    // prepare x axis with names
    QVector<double> ticks_vect;
    QVector<QString> labels_vect;
    ticks_vect << 1 << 2 << 3;
    labels_vect << "Clutch" << "Brake" << "Throttle";

    QColor lineColor("#a7def9");

    // prepare x axis:
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks_vect, labels_vect);
    customPlot->xAxis->setTicker(textTicker);
    //customPlot->xAxis->setTickLabelRotation(60);
    customPlot->xAxis->setSubTicks(false);
    customPlot->xAxis->setTickLength(0, 4);
    customPlot->xAxis->setRange(0, 4);
    customPlot->xAxis->setBasePen(QPen(lineColor));
    customPlot->xAxis->setTickPen(QPen(lineColor));
    customPlot->xAxis->grid()->setVisible(true);
    customPlot->xAxis->grid()->setPen(QPen(lineColor, 0, Qt::DotLine));
    customPlot->xAxis->setTickLabelColor(lineColor);
    customPlot->xAxis->setLabelColor(lineColor);

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

    // connect mouse interaction
    //customPlot ->setInteractions( QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables );
    customPlot ->setInteractions( QCP::iSelectPlottables );
    connect( customPlot, SIGNAL( plottableClick( QCPAbstractPlottable*, int,  QMouseEvent* ) ), this, SLOT( graphClicked( QCPAbstractPlottable* ) ) );
}

