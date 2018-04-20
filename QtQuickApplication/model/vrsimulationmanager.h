#ifndef SIMULATIONMANAGER_H
#define SIMULATIONMANAGER_H

#include <iostream>
#include <QObject>
#include <QThread>

#include "vrdatainterface.h"
#include "vrdatainterfacer3e.h"
#include "vrdatainterfaceac.h"

#include "r3e.h"
#include "ac.h"
#include "vrdata.h"

#include "vrutilities.h"
#include "vrmessage.h"

class VRSimulationManager : public QObject
{
    Q_OBJECT
private:
    QSharedPointer<VRDataInterface> dataInterface;
    QSharedPointer<VRData> vrData;

    int timerId;
    bool running;

    bool connectToSharedMemory();
    void free();
public:
    VRSimulationManager(QSharedPointer<VRData> vrData);
    ~VRSimulationManager();

    bool isRunning();

    QSharedPointer<VRDataInterface> getDataInterface();

public slots:
    bool start();
    void waitForSim();

signals:
    void finished();
    void statusChanged(VRMessage* message);

protected:
    void timerEvent(QTimerEvent* event);
};


#endif //SIMULATIONMANAGER_H
