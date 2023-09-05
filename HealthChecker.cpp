#include <thread>
#include <unistd.h>
#include "HealthChecker.h"
                                                 
void simulateBlinkingEffect()
{
    for (int i = 0; i < 6; i++)
    {
        cout << "\r* " << flush;
        this_thread::sleep_for(std::chrono::seconds(1));
        cout << "\r *" << flush;
        this_thread::sleep_for(std::chrono::seconds(1));
    }
}

bool isOutOfRange(float value, float lower, float upper) {
    return value < lower || value > upper;
}

int TemperaturelsOk(float& temperature)
{
    if (isOutOfRange(temperature,95, 102))
    {
        cout << localizedString("STRING_TEMPERATURE_CRITICAL") << "!\n";
        simulateBlinkingEffect();
        return 0;
    }
    return 1;
}

int PulseRatelsOk(float& pulseRate)
{
    if (isOutOfRange(pulseRate, 60, 100))
    {
        cout << localizedString("STRING_ALERT_PULSE") << "!\n";
        simulateBlinkingEffect();
        return 0;
    }
    return 1;
}

int POxygenSaturationlsOk(float& spo2)
{
    if (isOutOfRange(spo2, 90))
    {
        cout << localizedString("STRING_ALERT_SO2") << "!\n";
        simulateBlinkingEffect();
        return 0;
    }
    return 1;
}


bool vitalsOk(float temperature, float pulseRate, float spo2) {
    bool result = (TemperaturelsOk(temperature) && PulseRatelsOk(pulseRate) && POxygenSaturationlsOk(spo2));
    return result;
}