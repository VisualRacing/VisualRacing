#ifndef VRMETRICS_H
#define VRMETRICS_H

#include <QObject>

class VRMetrics : public QObject
{
    Q_OBJECT
    Q_PROPERTY(float accelBehav READ getAccelBehav WRITE setAccelBehav NOTIFY accelBehavChanged)
    Q_PROPERTY(float avgAccelBehav READ avgAccelBehav WRITE setAvgAccelBehav NOTIFY avgAccelBehavChanged)

public:
    VRMetrics();
    ~VRMetrics();

    float getAccelBehav() const;
    void setAccelBehav(float value);

    float getAvgAccelBehav() const;
    void setAvgAccelBehav(float value);

signals:
    void accelBehavChanged();
    void avgAccelBehavChanged();

private:

    float accelBehav;
    float avgAccelBehav;

};

#endif // VRMETRICS_H
