#include "vrsimulationmanager.h"
#include <QDebug>

VRSimulationManager::VRSimulationManager(QSharedPointer<VRData> vrData) {
    this->running = false;
    this->vrData = vrData;
}

VRSimulationManager::~VRSimulationManager() {

}

bool VRSimulationManager::start() {
    waitForSim();
    if (!connectToSharedMemory()) {
        this->dataInterface.clear();
        emit finished();
        emit statusChanged(new VRMessage(QString("Connection failed."), QColor(211, 38, 67)));
        return false;
    }

    // Start Timer with 10 ms interval
    this->timerId = startTimer(10);
    this->running = true;

    emit statusChanged(new VRMessage(QString("Interface connected successfully."), QColor(38, 211, 67)));

    // this->dataInterface.clear();
    return true;
}

bool VRSimulationManager::isRunning() {
    return this->running;
}

QSharedPointer<VRDataInterface> VRSimulationManager::getDataInterface()
{
    return this->dataInterface;
}

void VRSimulationManager::waitForSim() {
    std::cout << "SimulationManager is waiting for a simulation to start ..." << std::endl;

    int printCounter = 0;

    // I think we have to stop this loop if the application is about to quit
    // this problem should cause the existing close error
    while(true) { // TODO: Timeout?
        if (VRUtilities::isProcessRunning(vrconstants::r3eProcessName)) { // TODO: Optimize duplicate call for different simulations?
            this->dataInterface = QSharedPointer<VRDataInterface>(new VRDataInterfaceR3E(this->vrData));
            std::cout << " -> R3E running." << std::endl;
            return;
        } else if (VRUtilities::isProcessRunning(vrconstants::acProcessName)) {
            this->dataInterface = QSharedPointer<VRDataInterface>(new VRDataInterfaceAC(this->vrData));
            std::cout << " -> AC running." << std::endl;
            return;
        }

        Sleep(vrconstants::lookForRunningSimInterval);

        emit statusChanged(new VRMessage(QString("Searching for connection " + QString::number(printCounter)), QColor(211, 38, 67)));
        ++printCounter;
    }
}

bool VRSimulationManager::connectToSharedMemory() {
    std::cout << "Simulation is running, trying to connect to shared memory ..." << std::endl;
    emit statusChanged(new VRMessage(QString("Simulation is running, trying to connect..."), QColor(38, 211, 67)));

    bool success = false;
    while(VRUtilities::isProcessRunning(this->dataInterface->getProcessName())) { // TODO: TIMEOUT
        success = this->dataInterface->start();
        if (success)
            break;

        Sleep(vrconstants::connectToSharedMemoryInterval);
    }
    if (success)
    {
        std::cout << "DataInterface started, connected to shared memory!" << std::endl;
        emit statusChanged(new VRMessage(QString("DataInterface started, connected to application"), QColor(38, 211, 67)));
    }
    else
    {
        std::cout << "Could not connect to shared memory, simulation is not running anymore." << std::endl;
        emit statusChanged(new VRMessage(QString("Could not connect to application, simulation is not running anymore."), QColor(211, 38, 67)));
    }

    return success;
}

void VRSimulationManager::timerEvent(QTimerEvent* event)
{
    bool success = true;

    if (VRUtilities::isProcessRunning(this->dataInterface->getProcessName()))
    {
        success = this->dataInterface->update();
    }
    else
    {
        success = false;
    }

    if (!success)
    {
        std::cout << "Could not update, simulation might not be running or shared memory is not attached." << std::endl;
        emit statusChanged(new VRMessage(QString("Could not update, simulation might not be running."), QColor(211, 38, 67)));

        // Stop timer.
        killTimer(this->timerId);
        this->running = false;
        this->dataInterface.clear();
    }
}
