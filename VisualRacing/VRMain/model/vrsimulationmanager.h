#ifndef SIMULATIONMANAGER_H
#define SIMULATIONMANAGER_H

#include <iostream>
#include <QObject>

#include "vrdatainterface.h"
#include "vrdatainterfacer3e.h"
#include "vrdatainterfaceac.h"
#include "vrdatainterfacefactory.h"

#include "r3e.h"
#include "ac.h"
#include "vrdata.h"

#include "vrutilities.h"

class VRSimulationManager : public QObject
{
    Q_OBJECT
private:
    QSharedPointer<VRDataInterface> dataInterface;

    int timerId;
    bool running;

    void waitForSim();
    bool connectToSharedMemory();
    void free();
public:
    VRSimulationManager();
    ~VRSimulationManager();

    bool isRunning();

    QSharedPointer<VRDataInterface> getDataInterface();

public slots:
    bool start();

protected:
    void timerEvent(QTimerEvent* event);
};


#endif //SIMULATIONMANAGER_H
