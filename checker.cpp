#include <assert.h>
#include "HealthChecker.h"
#include "Language.h";
                                
std::string language = "German";

int main() {
    languageFileName(language);
    assert(!vitalsOk(99, 102, 70));
    assert(vitalsOk(98.1, 70, 98));
    cout << "Done\n";
}

