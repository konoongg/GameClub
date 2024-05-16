#pragma once

#include <map>
#include "event/Event.h"
#include "../gameClub/GameClub.h"
#include "../resultPrinter/ResultPrinter.h"

class EventAnalyzer {
    void AnalyzeEvent(Event event);
    void EndTimeAnalyze();
    void CreateNewEvent(std::tm time, std::string mes, EventIdE eventIdE);
    GameClub& gameClub;
    ResultPrinter& resultPrinter;
public:
    explicit EventAnalyzer(GameClub& gameClub, ResultPrinter& resultPrinter);
    void AnalyzeTimeLine();
};


