#pragma once
#include <iostream>
#include "Language.h"
#include <assert.h>
using namespace std;
namespace HealthChecker
{
	void simulateBlinkingEffect();
	bool lsPulseRateInRange(float pulseRate);
	bool lsPOxygenSaturationInRange(float spo2);
	bool vitalsOk(float temperature, float pulseRate, float spo2, char TempUnit = 'F');
	bool isOutOfRange(float value, float lower, float upper = 100);
}


