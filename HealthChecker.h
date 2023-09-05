#pragma once
#include <iostream>
#include "Language.h"
using namespace std;

void simulateBlinkingEffect();
int TemperaturelsOk(float& temperature);
int PulseRatelsOk(float& pulseRate);
int POxygenSaturationlsOk(float& spo2);
bool vitalsOk(float temperature, float pulseRate, float spo2);
bool isOutOfRange(float value, float lower, float upper=100);