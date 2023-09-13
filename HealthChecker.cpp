#include <thread>
#include <unistd.h>
#include "HealthChecker.h"   
#include "TempChecker.h"
void HealthChecker::simulateBlinkingEffect()
{
    for (int i = 0; i < 6; i++)
    {
        cout << "\r* " << flush;
        this_thread::sleep_for(std::chrono::seconds(1));
        cout << "\r *" << flush;
        this_thread::sleep_for(std::chrono::seconds(1));
    }
}

bool HealthChecker::isOutOfRange(float value, float lower, float upper) {
    return value < lower || value > upper;
}


bool HealthChecker::lsPulseRateInRange(float pulseRate)
{
    if (isOutOfRange(pulseRate, 60, 100))
    {
        cout << localizedString("STRING_ALERT_PULSE") << "!\n";
        simulateBlinkingEffect();
        return false;
    }
    return true;
}

bool HealthChecker::lsPOxygenSaturationInRange(float spo2)
{
    if (isOutOfRange(spo2, 90))
    {
        cout << localizedString("STRING_ALERT_SO2") << "!\n";
        simulateBlinkingEffect();
        return false;
    }
    return true;
}

bool HealthChecker::vitalsOk(float temperature, float pulseRate, float spo2, char TempUnit) {
    /* Specify temperature unit as 'C' for Celcius or 'F' for Farenhite. Default is Farenhite */
    bool result = (TempChecker::lsTemperatureInRange(temperature, TempUnit) && HealthChecker::lsPulseRateInRange(pulseRate) && HealthChecker::lsPOxygenSaturationInRange(spo2));
    return result;
}