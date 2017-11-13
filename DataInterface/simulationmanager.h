#ifndef SIMULATIONMANAGER_H
#define SIMULATIONMANAGER_H

#include "DataInterface/datainterface.h"
#include "DataInterface/r3e_datainterface.h"
#include "DataInterface/ac_datainterface.h"
#include "DataStructures/Input/r3e.h"
#include "DataStructures/Input/ac.h"

class SimulationManager {
private:
    DataInterface* dataInterface;

    void waitForSim();
    bool connectToSharedMemory();
    void run();
    void free();
public:
    SimulationManager();
    ~SimulationManager();

    bool start();
};


#endif //SIMULATIONMANAGER_H
