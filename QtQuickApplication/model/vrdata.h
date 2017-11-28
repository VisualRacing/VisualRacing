#ifndef VRDATA_H
#define VRDATA_H

#include <QString>
#include <QObject>
#include "vrutilities.h"


class VRData : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int gear READ getGear WRITE setGear NOTIFY gearChanged)
    Q_PROPERTY(float velocity READ getVelocity WRITE setVelocity NOTIFY velocityChanged)
    Q_PROPERTY(int rpm READ getRpm WRITE setRpm NOTIFY rpmChanged)
    Q_PROPERTY(int maxRpm READ getMaxRpm WRITE setMaxRpm NOTIFY maxRpmChanged)

    Q_PROPERTY(float throttle READ getThrottle WRITE setThrottle NOTIFY throttleChanged)
    Q_PROPERTY(float brake READ getBrake WRITE setBrake NOTIFY brakeChanged)
    Q_PROPERTY(float clutch READ getClutch WRITE setClutch NOTIFY clutchChanged)

    Q_PROPERTY(int completedLaps READ getCompletedLaps WRITE setCompletedLaps NOTIFY completedLapsChanged)

    Q_PROPERTY(float fuel READ getFuel WRITE setFuel NOTIFY fuelChanged)
    Q_PROPERTY(float maxFuel READ getMaxFuel WRITE setMaxFuel NOTIFY maxFuelChanged)

    Q_PROPERTY(bool pitLimiter READ getPitLimiter WRITE setPitLimiter NOTIFY pitLimiterChanged)
    Q_PROPERTY(bool isInPitlane READ getIsInPitlane WRITE setIsInPitlane NOTIFY isInPitlaneChanged)

    Q_PROPERTY(float brakeBias READ getBrakeBias WRITE setBrakeBias NOTIFY brakeBiasChanged)

public:
    VRData();

    Q_INVOKABLE double getTimeInSeconds();

    int getGear() const;
    void setGear(int value);

    float getVelocity() const;
    void setVelocity(float value);

    int getRpm() const;
    void setRpm(int value);

    int getMaxRpm() const;
    void setMaxRpm(int value);

    float getThrottle() const;
    void setThrottle(float value);

    float getBrake() const;
    void setBrake(float value);

    float getClutch() const;
    void setClutch(float value);

    int getCompletedLaps() const;
    void setCompletedLaps(int value);

    float getFuel() const;
    void setFuel(float value);

    float getMaxFuel() const;
    void setMaxFuel(float value);

    bool getPitLimiter() const;
    void setPitLimiter(bool value);

    bool getIsInPitlane() const;
    void setIsInPitlane(bool value);

    float getBrakeBias() const;
    void setBrakeBias(float value);

signals:
    void gearChanged();
    void velocityChanged();
    void rpmChanged();
    void maxRpmChanged();

    void throttleChanged();
    void brakeChanged();
    void clutchChanged();

    void completedLapsChanged();

    void fuelChanged();
    void maxFuelChanged();

    void pitLimiterChanged();
    void isInPitlaneChanged();

    void brakeBiasChanged();

private:

    //
    // Application information
    //
    std::chrono::milliseconds startTime;

    //
    // Session information
    //

    //QString playerName;
    /* TODO:
    Getting the car name is a bit difficult for RRRE,
    I know that there is a huge JSON containing all the cars
    with their corresponding IDs somewhere. The simulation
    itself only gives us the IDs.
    */
    //QString carName;
    //QString trackName;

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

    //float tirePressure[4]; // TODO: Unit?
    //float tireWear[4];
    //float tireDirt[4];

    // Tire temperatures of three points across the tread of the tire (in Celcius)
    /*
     * Indexing of 2nd dimension:
     * 0: Inner
     * 1: Center
     * 2: Outer
     */
    //float tireTemperatures[4][3];

    // in Celcius
    //float brakeTemperatures[4];

    // Damage
    // TODO: AC and R3E work a bit different here, not sure what the best way to handle this is.

    // in l
    float fuel;
    float maxFuel;

    // How much the brakes are biased towards the front
    float brakeBias;

    // false = inactive, true = active
    bool pitLimiter;

    // true = in pitlane
    bool isInPitlane;

    // true = in pit
    //bool isInPit;

    //
    // Timing information
    //

    // in s
    //float currentLapTime;
    //float bestLapTime;
    //float previousLapTime;
    //float theoreticalBestLapTime;

    //int currentSector;
    //float currentLapSectorTimes[3];
    //float bestLapSectorTimes[3];
    //float previousLapSectorTimes[3];
    //float bestSectorTimes[3];

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
