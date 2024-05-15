#pragma once

#include <map>
#include "event/Event.h"
#include "../gameClub/GameClub.h"
#include "../resultPrinter/ResultPrinter.h"

class EventAnalyzer {
    void AnalyzeEvent(Event event);
    void EndTimeAnalyze();
    GameClub& gameClub;
    ResultPrinter& resultPrinter;
public:
    explicit EventAnalyzer(GameClub& gameClub, ResultPrinter& resultPrinter);
    void AnalyzeTimeLine();
};


