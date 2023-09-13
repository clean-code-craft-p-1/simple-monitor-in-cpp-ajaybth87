#include "TempChecker.h"
#include "HealthChecker.h"

bool TempChecker::lsTemperatureInRange(float temperatureInFarenhite, char unit)
{
    temperatureInFarenhite = GetTemperarureInFarenhite(temperatureInFarenhite, unit);
    if (HealthChecker::isOutOfRange(temperatureInFarenhite, 95, 102))
    {
        cout << localizedString("STRING_TEMPERATURE_CRITICAL") << "!\n";
        HealthChecker::simulateBlinkingEffect();
        return false;
    }
    cout << localizedString(GetTemperatureNotification(temperatureInFarenhite)) << "!\n";
    return true;
}


float TempChecker::GetTemperarureInFarenhite(float temperature, char unit)
{
    if (unit == 'C' || unit == 'c')
    {
        return  (temperature * 9 / 5) + 32;
    }
    else
    {
        return temperature;
    }
}

string TempChecker::GetTemperatureNotification(float temperature) {
    string condition = "";
    if (temperature <= 95) {
        condition = "HYPO_THERMIA";
    } else if (temperature <= 96.53) {
        condition = "NEAR_HYPO";
    } else if (temperature <= 100.47) {
        condition = "NORMAL";
    } else if (temperature <= 102) {
        condition = "NEAR_HYPER";
    } else if (temperature <= 200) {
        condition = "HYPER_THERMIA";
    }
    return condition;
}