#include <iostream>
#include <sstream>
#include <iomanip>
#include <utility>
#include "Event.h"


void Event::DefineEventArgs(std::vector<std::string> args){
    if(eventId == EventIdE::CAME){
        strArgs.push_back(args[2]);
    }
    else if(eventId == EventIdE::SIT_AT_TABLE){
        strArgs.push_back(args[2]);
        intArgs.push_back(std::stoi(args[3]));
    }
    else if(eventId == EventIdE::WAIT){
        strArgs.push_back(args[2]);
    }
    else if(eventId == EventIdE::LEAVE){
        strArgs.push_back(args[2]);
    }
    else if(eventId == EventIdE::LEAVE_AT_END){
        strArgs.push_back(args[2]);
        intArgs.push_back(std::stoi(args[3]));
    }
    else if(eventId == EventIdE::SIT_AT_EMPTY_TABLE){
        strArgs.push_back(args[2]);
        intArgs.push_back(std::stoi(args[3]));
    }
    else if(eventId == EventIdE::EXCEPTION){
        strArgs.push_back(args[2]);
    }
}

void Event::DefineTime(const std::string& strTime){
    std::tm time{};
    std::istringstream iss(strTime);
    iss >> std::get_time(&time, "%H:%M");
    if(iss.fail()){
        std::cerr << "error parsing string " << std::endl;
    }
    this->time = time;
}

Event::Event(std::vector<std::string> args) {
    DefineTime(args[0]);
    int id = std::stoi(args[1]);
    eventId = static_cast<EventIdE>(id);
    DefineEventArgs(args);
}

EventIdE Event::GetId() {
    return eventId;
}

std::string Event::GetStrArg(int index) {
    return strArgs[index];
}

int Event::GetIntArg(int index) {
    return intArgs[index];
}

std::tm Event::GetTime() {
    return time;
}

Event::Event(std::tm tm, EventIdE id, std::string strArg) {
    time = tm;
    eventId = id;
    strArgs.push_back(strArg);
}
