#include <iostream>
#include <sstream>
#include <iomanip>
#include <utility>
#include <regex>
#include "Event.h"
#include "../../exceptions/fileFormat/FileFormatException.h"

bool Event::IsValidName(const std::string& str) {
    std::regex pattern("[a-z0-9_\\-]+");
    return std::regex_match(str, pattern);
}

void Event::DefineEventArgs(std::vector<std::string> args){
    if(eventId == EventIdE::CAME){
        if(args.size() != 3){
            throw FileFormatException{"wrong format of event"};
        }
        if(!IsValidName(args[2])){
            throw FileFormatException{"wrong format of event"};
        }
        strArgs.push_back(args[2]);
    }
    else if(eventId == EventIdE::SIT_AT_TABLE){
        if(args.size() != 4){
            throw FileFormatException{"wrong format of event"};
        }
        if(!IsValidName(args[2])){
            throw FileFormatException{"wrong format of event"};
        }
        strArgs.push_back(args[2]);
        try{
            intArgs.push_back(std::stoi(args[3]));
        }
        catch (const std::invalid_argument& e) {
            throw FileFormatException{"wrong format of event"};
        }
        catch (const std::out_of_range& e) {
            throw FileFormatException{"wrong format of event"};
        }
        if(intArgs[0] < 0 ){
            throw FileFormatException{"wrong format of event"};
        }
    }
    else if(eventId == EventIdE::WAIT){
        if(args.size() != 3){
            throw FileFormatException{"wrong format of event"};
        }
        if(!IsValidName(args[2])){
            throw FileFormatException{"wrong format of event"};
        }
        strArgs.push_back(args[2]);
    }
    else if(eventId == EventIdE::LEAVE){
        if(args.size() != 3){
            throw FileFormatException{"wrong format of event"};
        }
        if(!IsValidName(args[2])){
            throw FileFormatException{"wrong format of event"};
        }
        strArgs.push_back(args[2]);
    }
    else if(eventId == EventIdE::LEAVE_AT_END){
        if(args.size() != 4){
            throw FileFormatException{"wrong format of event"};
        }
        if(!IsValidName(args[2])){
            throw FileFormatException{"wrong format of event"};
        }
        strArgs.push_back(args[2]);
        try{
            intArgs.push_back(std::stoi(args[3]));
        }
        catch (const std::invalid_argument& e) {
            throw FileFormatException{"wrong format of event"};
        }
        catch (const std::out_of_range& e) {
            throw FileFormatException{"wrong format of event"};
        }
        if(intArgs[0] < 0 ){
            throw FileFormatException{"wrong format of event"};
        }
    }
    else if(eventId == EventIdE::SIT_AT_EMPTY_TABLE){
        if(args.size() != 4){
            throw FileFormatException{"wrong format of event"};
        }
        if(!IsValidName(args[2])){
            throw FileFormatException{"wrong format of event"};
        }
        strArgs.push_back(args[2]);
        try{
            intArgs.push_back(std::stoi(args[3]));
        }
        catch (const std::invalid_argument& e) {
            throw FileFormatException{"wrong format of event"};
        }
        catch (const std::out_of_range& e) {
            throw FileFormatException{"wrong format of event"};
        }
        if(intArgs[0] < 0 ){
            throw FileFormatException{"wrong format of event"};
        }
    }
    else if(eventId == EventIdE::EXCEPTION){
        if(args.size() != 3){
            throw FileFormatException{"wrong format of event"};
        }
        strArgs.push_back(args[2]);
    }
}

void Event::DefineTime(const std::string& strTime){
    if(strTime.size() != 5){
        //throw FileFormatException{"wrong format of event"};
    }
    std::tm time{};
    std::istringstream iss(strTime);
    iss >> std::get_time(&time, "%H:%M");
    if(iss.fail()){
        throw FileFormatException{"wrong format of event"};
    }
    this->time = time;
}

Event::Event(std::vector<std::string> args) {
    try{
        DefineTime(args[0]);
        int id = std::stoi(args[1]);
        eventId = static_cast<EventIdE>(id);
        DefineEventArgs(args);
    }
    catch(FileFormatException& err){
        throw err;
    }
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

