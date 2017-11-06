//
// Created by stark on 21-Oct-17.
//

#include "SimulationManager.h"

SimulationManager::SimulationManager() {

}

SimulationManager::~SimulationManager() {
    delete this->dataInterface;
}

bool SimulationManager::start() {
    waitForSim();
    if (!connectToSharedMemory()) {
        free();
        return false;
    }
    run();
    free();
    return true;
}

void SimulationManager::waitForSim() {
    std::cout << "SimulationManager is waiting for a simulation to start ..." << std::endl;

    while(true) { // TODO: Timeout?
        if (Utilities::isProcessRunning(constants::r3eProcessName)) {
            this->dataInterface = new R3E_DataInterface();
            std::cout << " -> R3E running." << std::endl;
            return;
        } else if (Utilities::isProcessRunning(constants::acProcessName)) {
            this->dataInterface = new AC_DataInterface();
            std::cout << " -> AC running." << std::endl;
            return;
        }

        Sleep(UPDATE_INTERVAL * LOOK_FOR_RUNNING_SIM_INTERVAL_FACTOR);
    }
}

bool SimulationManager::connectToSharedMemory() {
    std::cout << "Simulation is running, trying to connect to shared memory ..." << std::endl;

    bool success = false;
    while(Utilities::isProcessRunning(this->dataInterface->getProcessName())) {
        success = this->dataInterface->start();
        if (success)
            break;

        Sleep(UPDATE_INTERVAL * CONNECT_TO_SHARED_MEMORY_INTERVAL_FACTOR);
    }
    if (success)
        std::cout << "DataInterface started, connected to shared memory!" << std::endl;
    else
        std::cout << "Could not connect to shared memory, simulation is not running anymore." << std::endl;

    return success;
}

void SimulationManager::run() {
    VRData* data;
    std::string processName = this->dataInterface->getProcessName();

    while(Utilities::isProcessRunning(processName)) { // TODO!
        Sleep(UPDATE_INTERVAL);
        data = this->dataInterface->getBuffer();
        if (!data)
            continue;

        // TODO: Push struct to UI.
        std::cout << data->gear << std::endl;
    }

    std::cout << "Simulation has been exited." << std::endl;
}

void SimulationManager::free() {
    this->dataInterface->stop();
    delete this->dataInterface;
    this->dataInterface = nullptr;
}