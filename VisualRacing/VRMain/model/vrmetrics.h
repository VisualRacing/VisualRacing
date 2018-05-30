#ifndef VRMETRICS_H
#define VRMETRICS_H

#include <QObject>

class VRMetrics : public QObject
{
    Q_OBJECT
    Q_PROPERTY(float accelBehav READ getAccelBehav WRITE setAccelBehav NOTIFY accelBehavChanged)
    Q_PROPERTY(float avgAccelBehav READ getAvgAccelBehav WRITE setAvgAccelBehav NOTIFY avgAccelBehavChanged)
    Q_PROPERTY(long clutchDisengagedTime READ getClutchDisengagedTime WRITE setClutchDisengagedTime NOTIFY clutchDisengagedTimeChanged)
    Q_PROPERTY(long gearChangeTime READ getGearChangeTime WRITE setGearChangeTime NOTIFY gearChangeTimeChanged)
    Q_PROPERTY(long avgClutchDisTime READ getAvgClutchDisTime WRITE setAvgClutchDisTime NOTIFY avgClutchDisTimeChanged)
    Q_PROPERTY(long avgGearChangTime READ getAvgGearChangTime WRITE setAvgGearChangTime NOTIFY avgGearChangTimeChanged)
    Q_PROPERTY(long diffToAvgShiftTime READ getDiffToAvgShiftTime WRITE setDiffToAvgShiftTime NOTIFY diffToAvgShiftTimeChanged)
    Q_PROPERTY(long minClutchDisTime READ getMinClutchDisTime WRITE setMinClutchDisTime NOTIFY minClutchDisTimeChanged)

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

    long getDiffToAvgShiftTime() const;
    void setDiffToAvgShiftTime(long value);

    long getMinClutchDisTime() const;
    void setMinClutchDisTime(long value);

signals:
    void accelBehavChanged();
    void avgAccelBehavChanged();
    void clutchDisengagedTimeChanged();
    void gearChangeTimeChanged();
    void avgClutchDisTimeChanged();
    void avgGearChangTimeChanged();
    void diffToAvgShiftTimeChanged();
    void minClutchDisTimeChanged();

private:

    float accelBehav;
    float avgAccelBehav;
    long clutchDisengagedTime;
    long gearChangeTime;
    long avgClutchDisTime;
    long avgGearChangTime;
    long diffToAvgShiftTime;
    long minClutchDisTime;
};

#endif // VRMETRICS_H
