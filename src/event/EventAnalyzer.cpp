#include "EventAnalyzer.h"


EventAnalyzer::EventAnalyzer(GameClub& gameClub, ResultPrinter& resultPrinter) : gameClub(gameClub),  resultPrinter(resultPrinter) {}

void EventAnalyzer::AnalyzeTimeLine() {
    for(auto & it : gameClub.GetTimeLine()){
        const std::vector<Event>& events = it.second;
        for(const auto& event : events){
            AnalyzeEvent(event);
        }
    }
    EndTimeAnalyze();
}

void EventAnalyzer::AnalyzeEvent(Event event) {
    EventIdE id = event.GetId();
    if(id == EventIdE::CAME){
        gameClub.ClientCame(event.GetTime(), event.GetStrArg(0));
    }
    else if(id == EventIdE::SIT_AT_TABLE){
        gameClub.ClientSit(event.GetTime(), event.GetStrArg(0), event.GetIntArg(0));
    }
    else if(id == EventIdE::WAIT){
        gameClub.ClientWait(event.GetStrArg(0));
    }
    else if(id == EventIdE::LEAVE){
        gameClub.ClientLive(event.GetTime(), event.GetStrArg(0));
    }
}

void EventAnalyzer::EndTimeAnalyze() {
    gameClub.Close();
    resultPrinter.PrintGameClub(gameClub);
}

