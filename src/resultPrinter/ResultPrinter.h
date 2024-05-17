#pragma once


#include "../gameClub/GameClub.h"
#include "../timeFixer/TimeFixer.h"

class ResultPrinter {
    void PrintEventList(std::map<std::tm, std::vector<Event>, TmComparator>& timeLine);
    void PrintTableResult(std::vector<Table>& tables);
    TimeFixer timeFixer;
public:
    void PrintGameClub(GameClub& gameclub);
};


