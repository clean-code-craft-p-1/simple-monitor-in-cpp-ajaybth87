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
    map<string, pair<float, float>> conditions = {
        {"HYPO_THERMIA", {0, 95}},
        {"NEAR_HYPO", {95, 96.53}},
        {"NORMAL", {96.54, 100.47}},
        {"NEAR_HYPER", {100.48, 102}},
        {"HYPER_THERMIA", {102, 200}}
    };
    for (auto it = conditions.begin(); it != conditions.end(); ++it) {
        auto& condition = it->first;
        auto& bounds = it->second;

        if (bounds.first <= temperature && temperature <= bounds.second) {
            return condition;
        }
    }
    return "";
}