#include <sstream>
#include <iomanip>
#include <iostream>
#include "GameClubCreator.h"


void GameClubCreator::InitCountTable(InputParser& parser, GameClubParamsT& params){
    std::vector<std::string> countTable = parser.GetWords();
    params.countTable = std::stoi(countTable[0]);
}

std::tm GameClubCreator::ParseTime(const std::string& strTime){
    std::tm time{};
    std::istringstream iss(strTime);
    iss >> std::get_time(&time, "%H:%M");
    if(iss.fail()){
        std::cerr << "error parsing string " << std::endl;
    }
    return time;
}

void GameClubCreator::InitWorkTime(InputParser& parser, GameClubParamsT& params){
    std::vector<std::string> workTime = parser.GetWords();
    params.startTm = ParseTime(workTime[0]);
    params.endTm = ParseTime(workTime[1]);
}

void GameClubCreator::InitPrice(InputParser& parser, GameClubParamsT& params){
    std::vector<std::string> price = parser.GetWords();
    params.price = std::stoi(price[0]);
}

GameClubParamsT GameClubCreator::InitGameClubParams(InputParser& parser){
    GameClubParamsT params{};
    InitCountTable(parser, params);
    InitWorkTime(parser, params);
    InitPrice(parser, params);
    return params;
}

void GameClubCreator::InitEvents(InputParser &parser, GameClub &gameClub) {
    std::vector<std::string> parsedLine = parser.GetWords();
    while(!parsedLine.empty()){
        std::tm time = ParseTime(parsedLine[0]);
        Event event (parsedLine);
        gameClub.AddEvent(time, event);
        parsedLine = parser.GetWords();
    }
}

GameClub GameClubCreator::CreateGameClub(InputParser& parser){
    GameClubParamsT params = InitGameClubParams(parser);
    GameClub gameClub(params);
    InitEvents(parser, gameClub);
    return gameClub;
}