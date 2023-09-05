#pragma once

#include <fstream>
#include <string>
#include <map>
#include <algorithm>

std::string localizedString(std::string key);
void loadLanguageFile(std::string filename);
void languageFileName(std::string);