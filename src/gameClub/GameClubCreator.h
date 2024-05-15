#pragma once


#include "GameClub.h"
#include "../inputParser/InputParser.h"
#include "GameClubParamsT.h"

class GameClubCreator {
    GameClubParamsT InitGameClubParams(InputParser& parser);
    void InitCountTable(InputParser& parser, GameClubParamsT& params);
    void InitWorkTime(InputParser& parser, GameClubParamsT& params);
    void InitPrice(InputParser& parser, GameClubParamsT& params);
    std::tm ParseTime(const std::string& strTime);
    void InitEvents(InputParser& parser, GameClub& gameClub);
public:
    GameClub CreateGameClub(InputParser& parser);
};

