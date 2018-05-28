#ifndef VRMETRICS_H
#define VRMETRICS_H

#include <QObject>

class VRMetrics : public QObject
{
    Q_OBJECT
    Q_PROPERTY(float tireSlip READ getTireSlip WRITE setTireSlip NOTIFY tireSlipChanged)

public:
    VRMetrics();
    ~VRMetrics();

    float getTireSlip() const;
    void setTireSlip(float value);

signals:
    void tireSlipChanged();

private:
    float upShiftBehaviour;

    float tireSlip;

};

#endif // VRMETRICS_H
