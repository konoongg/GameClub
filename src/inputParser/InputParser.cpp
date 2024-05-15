#include <string>
#include <iostream>
#include <sstream>
#include "InputParser.h"

InputParser::InputParser(const std::string& pathToFile) {
    file.open(pathToFile);
    if(!file.is_open()){
        std::cerr << "Failed to open file: " << pathToFile << std::endl;
    }
}

std::string InputParser::GetLine() {
    std::string line;
    if(!std::getline(file, line)){
        file.close();
        return std::string("");
    }
    return line;
}

std::vector<std::string> InputParser::GetWords(){
    std::string line = GetLine();
    if(line.empty()){
        std::vector<std::string> empty(0);
        return empty;
    }
    std::istringstream iss(line);
    std::vector<std::string> words;
    std::string word;
    while (iss >> word) {
        words.push_back(word);
    }
    return words;
}

