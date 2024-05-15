#pragma once

#include <fstream>
#include <vector>

class InputParser {
    std::ifstream file;
    std::string GetLine();
public:
    explicit InputParser(const std::string& pathToFile);
    std::vector<std::string> GetWords();
};


