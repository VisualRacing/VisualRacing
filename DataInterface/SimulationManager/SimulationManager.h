//
// Created by stark on 21-Oct-17.
//

#ifndef VR_SIMULATIONMANAGER_H
#define VR_SIMULATIONMANAGER_H

#include "../main.h"
#include "../DataInterface/DataInterface.h"
#include "../DataInterface/R3E_DataInterface.h"
#include "../DataInterface/AC_DataInterface.h"
#include "../DataStructures/Input/r3e.h"
#include "../DataStructures/Input/ac.h"

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


#endif //VR_SIMULATIONMANAGER_H
