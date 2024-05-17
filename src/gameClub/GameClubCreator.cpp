#include <sstream>
#include <iomanip>
#include <iostream>
#include "GameClubCreator.h"
#include "../exceptions/fileFormat/FileFormatException.h"


void GameClubCreator::InitCountTable(InputParser& parser, GameClubParamsT& params){
    std::vector<std::string> countTable = parser.GetWords();
    if(countTable.size() != 1){
        throw FileFormatException{"wrong format of count table, string:" + std::to_string(fileStrIndex)};
    }
    try{
        params.countTable = std::stoi(countTable[0]);
    }
    catch (const std::invalid_argument& e) {
        throw FileFormatException{"wrong format of count table, string:" + std::to_string(fileStrIndex)};
    }
    catch (const std::out_of_range& e) {
        throw FileFormatException{"wrong format of count table, string:" + std::to_string(fileStrIndex)};
    }
    fileStrIndex++;
}

std::tm GameClubCreator::ParseTime(const std::string& strTime){
    std::tm time{};
    std::istringstream iss(strTime);
    iss >> std::get_time(&time, "%H:%M");
    if(iss.fail()){
        throw FileFormatException{"wrong format of workTime, string: " + std::to_string(fileStrIndex)};
    }
    return time;
}

void GameClubCreator::InitWorkTime(InputParser& parser, GameClubParamsT& params){
    std::vector<std::string> workTime = parser.GetWords();
    if(workTime.size() != 2){
        throw FileFormatException{"wrong format of workTime, string: " + std::to_string(fileStrIndex)};
    }
    params.startTm = ParseTime(workTime[0]);
    params.endTm = ParseTime(workTime[1]);
    fileStrIndex++;
}

void GameClubCreator::InitPrice(InputParser& parser, GameClubParamsT& params){
    std::vector<std::string> price = parser.GetWords();
    if(price.size() != 1){
        throw FileFormatException{"wrong format of price table, string:" + std::to_string(fileStrIndex)};
    }
    try{
        params.price = std::stoi(price[0]);
    }
    catch (const std::invalid_argument& e) {
        throw FileFormatException{"wrong format of price table, string:" + std::to_string(fileStrIndex)};
    }
    catch (const std::out_of_range& e) {
        throw FileFormatException{"wrong format of price table, string:" + std::to_string(fileStrIndex)};
    }
    fileStrIndex++;
}

GameClubParamsT GameClubCreator::InitGameClubParams(InputParser& parser){
    GameClubParamsT params{};
    try{
        InitCountTable(parser, params);
        InitWorkTime(parser, params);
        InitPrice(parser, params);
    }
    catch(FileFormatException& err){
        throw err;
    }
    return params;
}

void GameClubCreator::InitEvents(InputParser &parser, GameClub &gameClub) {
    std::vector<std::string> parsedLine = parser.GetWords();
    std::tm oldTime;
    oldTime.tm_hour = 0;
    oldTime.tm_min = 0;
    while(!parsedLine.empty()){
        try{
            std::tm time = ParseTime(parsedLine[0]);
            if(oldTime.tm_hour > time.tm_hour){
                throw FileFormatException{"wrong format of event, string: " + std::to_string(fileStrIndex)};
            }
            else if (oldTime.tm_hour == time.tm_hour && oldTime.tm_min > time.tm_min){
                throw FileFormatException{"wrong format of event, string: " + std::to_string(fileStrIndex)};
            }
            Event event (parsedLine, gameClub.GetCountTable());
            gameClub.AddEvent(time, event);
            oldTime = time;
        }
        catch(FileFormatException& err){
            throw FileFormatException{"wrong format of event, string: " + std::to_string(fileStrIndex)};
        }
        parsedLine = parser.GetWords();
        fileStrIndex++;
    }
}

GameClub GameClubCreator::CreateGameClub(InputParser& parser){
    fileStrIndex = 1;
    try{
        GameClubParamsT params = InitGameClubParams(parser);
        GameClub gameClub(params);
        InitEvents(parser, gameClub);
        return gameClub;
    }
    catch(FileFormatException& err){
        throw err;
    }
}