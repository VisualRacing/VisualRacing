#ifndef VRMETRICS_H
#define VRMETRICS_H

#include <QObject>

class VRMetrics : public QObject
{
    Q_OBJECT

    // Upshift
    Q_PROPERTY(long clutchDisengagedTime READ getClutchDisengagedTime WRITE setClutchDisengagedTime NOTIFY clutchDisengagedTimeChanged)
    Q_PROPERTY(long gearChangeTime READ getGearChangeTime WRITE setGearChangeTime NOTIFY gearChangeTimeChanged)
    Q_PROPERTY(long avgClutchDisTime READ getAvgClutchDisTime WRITE setAvgClutchDisTime NOTIFY avgClutchDisTimeChanged)
    Q_PROPERTY(long avgGearChangTime READ getAvgGearChangTime WRITE setAvgGearChangTime NOTIFY avgGearChangTimeChanged)
    Q_PROPERTY(long diffToAvgShiftTime READ getDiffToAvgShiftTime WRITE setDiffToAvgShiftTime NOTIFY diffToAvgShiftTimeChanged)
    Q_PROPERTY(long minClutchDisTime READ getMinClutchDisTime WRITE setMinClutchDisTime NOTIFY minClutchDisTimeChanged)

    // Acceleration
    Q_PROPERTY(ThrottleClassification throttleClassification READ getThrottleClassification WRITE setThrottleClassification NOTIFY throttleClassificationChanged)
    Q_PROPERTY(RpmClassification rpmClassification READ getRpmClassification WRITE setRpmClassification NOTIFY rpmClassificationChanged)
    Q_PROPERTY(GripClassification gripClassification READ getGripClassification WRITE setGripClassification NOTIFY gripClassificationChanged)

public:
    // Acceleration
    enum ThrottleClassification { MAX, MED2HIGH, LOW2MED };
    Q_ENUM(ThrottleClassification)
    enum RpmClassification { HIGH, LOW_MED };
    Q_ENUM(RpmClassification)
    enum GripClassification { FULL, LOOSING };
    Q_ENUM(GripClassification)

    VRMetrics();
    ~VRMetrics();

    // Upshift
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

    // Acceleration
    ThrottleClassification getThrottleClassification() const;
    void setThrottleClassification(const ThrottleClassification &value);

    RpmClassification getRpmClassification() const;
    void setRpmClassification(const RpmClassification &value);

    GripClassification getGripClassification() const;
    void setGripClassification(const GripClassification &value);

signals:
    // Upshift
    void clutchDisengagedTimeChanged();
    void gearChangeTimeChanged();
    void avgClutchDisTimeChanged();
    void avgGearChangTimeChanged();
    void diffToAvgShiftTimeChanged();
    void minClutchDisTimeChanged();

    // Acceleration
    void throttleClassificationChanged();
    void rpmClassificationChanged();
    void gripClassificationChanged();

private:
    // Upshift
    long clutchDisengagedTime;
    long gearChangeTime;
    long avgClutchDisTime;
    long avgGearChangTime;
    long diffToAvgShiftTime;
    long minClutchDisTime;

    // Acceleration
    ThrottleClassification throttleClassification;
    RpmClassification rpmClassification;
    GripClassification gripClassification;

};

Q_DECLARE_METATYPE(VRMetrics::ThrottleClassification)
Q_DECLARE_METATYPE(VRMetrics::RpmClassification)
Q_DECLARE_METATYPE(VRMetrics::GripClassification)

#endif // VRMETRICS_H
