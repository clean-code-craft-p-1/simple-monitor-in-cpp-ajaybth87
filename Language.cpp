#include "Language.h";

std::map<std::string, std::string> langfile;

void loadLanguageFile(std::string filename) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        auto delimiter = line.find("=");
        if (delimiter != std::string::npos) {
            auto key = line.substr(0, delimiter);
            auto value = line.substr(delimiter + 1);
            langfile[key] = value;
        }
    }
}

std::string localizedString(std::string key) {
    return langfile[key];
}

void languageFileName(std::string filename)
{
    std::transform(filename.begin(), filename.end(), filename.begin(), [](unsigned char c) 
        { 
            return std::tolower(c); 
        });

    filename += ".txt";

    loadLanguageFile(filename);
}