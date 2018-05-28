#include "vrmetricsmanager.h"

VRMetricsManager::VRMetricsManager(QSharedPointer<VRMetrics> metrics, QSharedPointer<VRData> data)
{
    this->m_metrics = metrics;
    this->m_data = data;
    this->m_running = true;
}

VRMetricsManager::~VRMetricsManager()
{

}

bool VRMetricsManager::isRunning()
{
    return this->m_running;
}

void VRMetricsManager::start()
{
    qDebug() << "Metrics Manager is started.";
    while(this->m_running){
        // update matrics
        this->updateAccelBehav();
        Sleep(1000);
    }
}

void VRMetricsManager::abort()
{
    this->m_running = false;
}

void VRMetricsManager::updateAccelBehav()
{
    float maxGrip = qMax(m_data->getTireGripFL(), m_data->getTireGripFR());
    maxGrip = qMax(maxGrip, m_data->getTireGripRL());
    maxGrip = qMax(maxGrip, m_data->getTireGripRR());

    // scale percentageRPM
    float percentageRPM = m_data->getRpm() / m_data->getMaxRpm();
    if (percentageRPM < 0.1f) {
        percentageRPM = 0;
        m_metrics->setAccelBehav(-1);
        // TODO: -1?
        return;
    } else if (percentageRPM > 0.9f) {
        percentageRPM = 1;
    } else {
        percentageRPM = 1.5625f * percentageRPM * percentageRPM - 0.3125f * percentageRPM + 0.015625f;
    }

    float accelBehav = percentageRPM + maxGrip + m_data->getThrottle();
    accelBehav /= 3;

    m_metrics->setAccelBehav(accelBehav);
}

