#ifndef VRDATA_H
#define VRDATA_H

#include <string>

class VRData
{
public: // TODO!!!

    //
    // Session information
    //

    std::string playerName;
    /* TODO:
    Getting the car name is a bit difficult for RRRE,
    I know that there is a huge JSON containing all the cars
    with their corresponding IDs somewhere. The simulation
    itself only gives us the IDs.
    */
    std::string carName;
    std::string trackName;

    int completedLaps;

    //
    // Car information
    //

    // -1 = reverse (R), 0 = neutral (N)
    int gear;

    // in km/h
    float velocity;

    int rpm;
    int maxRpm;

    // Pedal positions
    // from 0 to 1
    float throttle;
    float brake;
    float clutch;

    // Tire Info
    /* Indexing:
     * 0: Front Left
     * 1: Front Right
     * 2: Rear Right
     * 3: Rear Left
    */

    float tirePressure[4]; // TODO: Unit?
    float tireWear[4];
    float tireDirt[4];

    // Tire temperatures of three points across the tread of the tire (in Celcius)
    /*
     * Indexing of 2nd dimension:
     * 0: Inner
     * 1: Center
     * 2: Outer
     */
    float tireTemperatures[4][3];

    // in Celcius
    float brakeTemperatures[4];

    // Damage
    // TODO: AC and R3E work a bit different here, not sure what the best way to handle this is.

    // in l
    float fuel;
    float maxFuel;

    // How much the brakes are biased towards the front (TODO: or back, idk yet)
    float brakeBias;

    // 0 = inactive, 1 = active
    int pitLimiter;

    int isInPit;

    //
    // Timing information
    //

    // in s
    float currentLapTime;
    float bestLapTime;
    float previousLapTime;
    float theoreticalBestLapTime;

    int currentSector;
    float currentLapSectorTimes[3];
    float bestLapSectorTimes[3];
    float previousLapSectorTimes[3];
    float bestSectorTimes[3];

    /* TODO:
    Things that will be added later:
        - Session type
        - Flag information
        - DRS and P2P information
        - Engine fluid temperatures etc.
        - Race info (I hope AC provides enough info, not sure atm.)
        - ...
    */
};

#endif //VRDATA_H
