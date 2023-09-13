
#include <assert.h>
#include "HealthChecker.h"
#include "Language.h"
#include "TestChecker.h"



std::string language = "German";


int main() {
     //languageFileName(language);
     languageFileName("English");
     TestVitalsMonitor::TestVitals();
     TestVitalsMonitor::TestBodyTemparature();
     TestVitalsMonitor::TestPulseRate();
     TestVitalsMonitor::TestOxygenSaturation();
     TestVitalsMonitor::TestDataRange();
    cout << "Done\n";
}
