#pragma once


#include <vector>
#include <string>
#include <ctime>
#include "EventIdE.h"

class Event {
    EventIdE eventId;
    std::vector<int>  intArgs;
    std::vector<std::string>  strArgs;
    void DefineEventArgs(std::vector<std::string> args);
    void DefineTime(const std::string& strTime);
    bool IsValidName(const std::string& str);
    std::tm time;
public:
    explicit Event(std::vector<std::string> args);
    EventIdE GetId();
    std::string GetStrArg(int index);
    int GetIntArg(int index);
    std::tm GetTime();
};

