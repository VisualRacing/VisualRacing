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
        this->updateTireSlip();
        Sleep(1000);
    }
}

void VRMetricsManager::abort()
{
    this->m_running = false;
}

void VRMetricsManager::updateTireSlip()
{
    float maxGrip = qMax(m_data->getTireGripFL(), m_data->getTireGripFR());
    maxGrip = qMax(maxGrip, m_data->getTireGripRL());
    maxGrip = qMax(maxGrip, m_data->getTireGripRR());
    m_metrics->setTireSlip(1-maxGrip);
}
