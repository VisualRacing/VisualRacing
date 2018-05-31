#include "vrmetricsmanager.h"

VRMetricsManager::VRMetricsManager(QSharedPointer<VRMetrics> metrics, QSharedPointer<VRData> data)
{
    this->m_metrics = metrics;
    this->m_data = data;

    this->m_avgClutchDisTime = 0l;
    this->m_avgGearChangTime = 0l;

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
    // TODO: Is this really what we want? What about corners? Should we limit it to the rear?
    float maxGrip = qMax(m_data->getTireGripFL(), m_data->getTireGripFR());
    maxGrip = qMax(maxGrip, m_data->getTireGripRL());
    maxGrip = qMax(maxGrip, m_data->getTireGripRR());

}

void VRMetricsManager::updateClutchDisTime()
{
    long tmp_clutchDisTime = m_data->getClutchDisengagedTime();
    m_metrics->setClutchDisengagedTime(tmp_clutchDisTime);

    updateAvgClutchDisTime(tmp_clutchDisTime);
}

void VRMetricsManager::updateAvgClutchDisTime(long clutchDisTime)
{
    // Get difference between new value and old average
    if (m_metrics->getMinClutchDisTime() != -1)
        m_metrics->setDiffToAvgShiftTime(clutchDisTime - m_metrics->getAvgClutchDisTime());
    // Store min clutch dis time (has to happen after diff changes!)
    if (m_metrics->getMinClutchDisTime() == -1l || clutchDisTime < m_metrics->getMinClutchDisTime())
        m_metrics->setMinClutchDisTime(clutchDisTime);


    // Attention take a look on rounding Error with this Algorithm
    int len = m_clutchDisTimeHistory.length();
    long tmp_avgClutchDisTime = m_avgClutchDisTime * len;               // calc the old sum by mult with number of elements
    long oldestClutchDisTime = 0;

    m_clutchDisTimeHistory.enqueue(clutchDisTime);                      // add new value to history
    if (len > 1000) {
        oldestClutchDisTime = m_clutchDisTimeHistory.dequeue();         // remove the oldest value if queue to long
    } else {
        len += 1;                                                       // if not too long increment tmp length
    }

    tmp_avgClutchDisTime += (clutchDisTime -  oldestClutchDisTime);     // calc new sum by adding the diff between new and oldest value
    m_avgClutchDisTime = tmp_avgClutchDisTime / len;                    // calc new average by deviding through new length (amount of values)

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

