#include "main.h"
#include "SimulationManager/SimulationManager.h"

int main() {
    SimulationManager sm;
    while(sm.start());

    return 0;
}