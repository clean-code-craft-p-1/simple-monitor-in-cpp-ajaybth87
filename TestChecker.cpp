#include "HealthChecker.h"
#include "TestChecker.h"
#include "TempChecker.h"

void TestVitalsMonitor::TestVitals() {
    assert(!HealthChecker::vitalsOk(99, 102, 70));
    assert(HealthChecker::vitalsOk(98.1, 70, 98));
    assert(!HealthChecker::vitalsOk(98.1, 70, 88));
}

void TestVitalsMonitor::TestBodyTemparature() {
    assert(TempChecker::lsTemperatureInRange(102));
    assert(TempChecker::lsTemperatureInRange(98.1));
    assert(!TempChecker::lsTemperatureInRange(94));
    assert(TempChecker::lsTemperatureInRange(36.7,'C'));
    assert(!TempChecker::lsTemperatureInRange(30, 'C'));
    assert(!TempChecker::lsTemperatureInRange(39, 'C'));
}

void TestVitalsMonitor::TestPulseRate() {
    assert(!HealthChecker::lsPulseRateInRange(102));
    assert(HealthChecker::lsPulseRateInRange(70));
}

void TestVitalsMonitor::TestOxygenSaturation() {
    assert(!HealthChecker::lsPOxygenSaturationInRange(70));
    assert(HealthChecker::lsPOxygenSaturationInRange(98));
}

void TestVitalsMonitor::TestDataRange() {
    // Within range
    const float lowerLimit = 50;
    const float upperLimit = 100;
    float testValue = 56;
    assert(!HealthChecker::isOutOfRange(testValue, lowerLimit, upperLimit));

    // upper limit
    testValue = 100;
    assert(!HealthChecker::isOutOfRange(testValue, lowerLimit, upperLimit));

    // lower limit
    testValue = 50;
    assert(!HealthChecker::isOutOfRange(testValue, lowerLimit, upperLimit));

    // Excceed range
    testValue = 102;
    assert(HealthChecker::isOutOfRange(testValue, lowerLimit, upperLimit));

    // Below range
    testValue = 44;
    assert(HealthChecker::isOutOfRange(testValue, lowerLimit, upperLimit));
}