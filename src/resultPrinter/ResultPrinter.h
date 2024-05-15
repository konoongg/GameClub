#pragma once


#include "../gameClub/GameClub.h"

class ResultPrinter {
    void PrintEventList(std::map<std::tm, std::vector<Event>, TmComparator>& timeLine);
    void PrintTableResult(std::vector<Table>& tables);
public:
    void PrintGameClub(GameClub& gameclub);
};


