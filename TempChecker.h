#pragma once
#include<iostream>

using namespace std;
namespace TempChecker
{

	bool lsTemperatureInRange(float temperature, char unit = 'F');
	float GetTemperarureInFarenhite(float, char);
	string GetTemperatureNotification(float temperature);
}
