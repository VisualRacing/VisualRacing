#ifndef VRMETRICSMANAGER_H
#define VRMETRICSMANAGER_H

#include <QObject>
#include <QSharedPointer>
#include <QDebug>
#include <QQueue>

#include "vrmetrics.h"
#include "vrdata.h"

class VRMetricsManager : public QObject
{
    Q_OBJECT

private:
    QSharedPointer<VRMetrics> m_metrics;
    QSharedPointer<VRData> m_data;

    bool m_running;

    float m_avgAccelBehav;
    QQueue<float> m_accelBehavHistory;

    void updateAccelBehav();
    void updateAvgAccelBehav(float accelBehav);

    void updateClutchDisTime();
    void updateAvgClutchDisTime(long clutchDisTime);

    void updateGearChangTime();
    void updateAvgGearChangTime(long gearChangTime);

public:
    VRMetricsManager(QSharedPointer<VRMetrics> metrics, QSharedPointer<VRData> data);
    ~VRMetricsManager();

    bool isRunning();

signals:

public slots:
   void start();
   void abort();

};

#endif // VRMETRICSMANAGER_H
