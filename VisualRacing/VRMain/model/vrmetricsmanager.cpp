#include "vrmetricsmanager.h"

VRMetricsManager::VRMetricsManager(QSharedPointer<VRMetrics> metrics, QSharedPointer<VRData> data)
{
    this->m_metrics = metrics;
    this->m_data = data;

    this->m_avgAccelBehav = 0;
    this->m_avgClutchDisTime = 0;
    this->m_avgGearChangTime = 0;

    QObject::connect(m_data.data(), SIGNAL(clutchDisengagedTimeChanged()),
                     this, SLOT(updateClutchDisTime()));
    QObject::connect(m_data.data(), SIGNAL(gearChangeTimeChanged()),
                     this, SLOT(updateGearChangTime()));
    QObject::connect(m_data.data(), SIGNAL(accelBehavChanged()),
                     this, SLOT(updateAccelBehav()));
}

VRMetricsManager::~VRMetricsManager()
{

}

void VRMetricsManager::updateAccelBehav()
{
    float maxGrip = qMax(m_data->getTireGripFL(), m_data->getTireGripFR());
    maxGrip = qMax(maxGrip, m_data->getTireGripRL());
    maxGrip = qMax(maxGrip, m_data->getTireGripRR());

    // scale percentageRPM
    float percentageRPM = m_data->getRpm() / (m_data->getMaxRpm() + 0.00001f);	// TODO: Division by Zero
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

    updateAvgAccelBehav(accelBehav);
}

void VRMetricsManager::updateAvgAccelBehav(float accelBehav)
{
    // Attention take a look on rounding Error with this Algorithm
    int len = m_accelBehavHistory.length();
    float tmp_avgAccelBehav = m_avgAccelBehav * len; 		// calc the old sum by mult with number of elements
    float oldestAccelBehav = 0;

    m_accelBehavHistory.enqueue(accelBehav);				// add new value to history
    if (len > 1000) {
        oldestAccelBehav = m_accelBehavHistory.dequeue();	// remove the oldest value if queue to long
    } else {
        len += 1;											// if not to long increment tmp length
    }

    tmp_avgAccelBehav += (accelBehav - oldestAccelBehav);	// calc new sum by adding the diff between new and oldest value
    m_avgAccelBehav = tmp_avgAccelBehav / len;				// calc new average by deviding through new length (amount of values)

    m_metrics->setAvgAccelBehav(m_avgAccelBehav);
}

void VRMetricsManager::updateClutchDisTime()
{
    long tmp_clutchDisTime = m_data->getClutchDisengagedTime();
    m_metrics->setClutchDisengagedTime(tmp_clutchDisTime);

    updateAvgClutchDisTime(tmp_clutchDisTime);
}

void VRMetricsManager::updateAvgClutchDisTime(long clutchDisTime)
{
    // Attention take a look on rounding Error with this Algorithm
    int len = m_clutchDisTimeHistory.length();
    long tmp_avgClutchDisTime = m_avgClutchDisTime * len;
    long oldestClutchDisTime = 0;

    m_clutchDisTimeHistory.enqueue(clutchDisTime);
    if (len > 1000) {
        oldestClutchDisTime = m_clutchDisTimeHistory.dequeue();
    } else {
        len += 1;
    }

    tmp_avgClutchDisTime += (clutchDisTime -  oldestClutchDisTime);
    m_avgClutchDisTime = tmp_avgClutchDisTime / len;

    m_metrics->setAvgClutchDisTime(m_avgClutchDisTime);
}

void VRMetricsManager::updateGearChangTime()
{
    long tmp_gearChangTime = m_data->getGearChangeTime();
    m_metrics->setGearChangeTime(tmp_gearChangTime);

    updateAvgGearChangTime(tmp_gearChangTime);
}

void VRMetricsManager::updateAvgGearChangTime(long gearChangTime)
{
    // Attention take a look on rounding Error with this Algorithm
    int len = m_gearChangTimeHistory.length();
    long tmp_avgGearChangTime = m_avgGearChangTime * len;
    long oldestGearChangTime = 0;

    m_gearChangTimeHistory.enqueue(gearChangTime);
    if (len > 1000) {
        oldestGearChangTime = m_gearChangTimeHistory.dequeue();
    } else {
        len += 1;
    }

    tmp_avgGearChangTime += (gearChangTime - oldestGearChangTime);
    m_avgGearChangTime = tmp_avgGearChangTime / len;

    m_metrics->setAvgGearChangTime(m_avgGearChangTime);
}

