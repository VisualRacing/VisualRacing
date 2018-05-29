#ifndef VRMETRICS_H
#define VRMETRICS_H

#include <QObject>

class VRMetrics : public QObject
{
    Q_OBJECT
    Q_PROPERTY(float accelBehav READ getAccelBehav WRITE setAccelBehav NOTIFY accelBehavChanged)
    Q_PROPERTY(float avgAccelBehav READ getAvgAccelBehav WRITE setAvgAccelBehav NOTIFY avgAccelBehavChanged)

public:
    VRMetrics();
    ~VRMetrics();

    float getAccelBehav() const;
    void setAccelBehav(float value);

    float getAvgAccelBehav() const;
    void setAvgAccelBehav(float value);

    long getClutchDisengagedTime() const;
    void setClutchDisengagedTime(long value);

    long getGearChangeTime() const;
    void setGearChangeTime(long value);

    long getAvgClutchDisTime() const;
    void setAvgClutchDisTime(long value);

    long getAvgGearChangTime() const;
    void setAvgGearChangTime(long value);

signals:
    void accelBehavChanged();
    void avgAccelBehavChanged();
    void clutchDisengagedTimeChanged();
    void gearChangeTimeChanged();
    void avgClutchDisTimeChanged();
    void avgGearChangTimeChanged();

private:

    float accelBehav;
    float avgAccelBehav;
    long clutchDisengagedTime;
    long gearChangeTime;
    long avgClutchDisTime;
    long avgGearChangTime;
};

#endif // VRMETRICS_H
