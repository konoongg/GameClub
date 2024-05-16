#include "EventAnalyzer.h"
#include "../exceptions/gameClub/notOpenYet/NotOpenYetException.h"
#include "../exceptions/gameClub/youShallNotPass/YouShallNotPassException.h"
#include "../exceptions/gameClub/soBigQueue/SoBigQueueException.h"


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
        try{
            gameClub.ClientCame(event.GetTime(), event.GetStrArg(0));
        }
        catch(GameClubException& err){
            CreateNewEvent(event.GetTime(), err.what(), EventIdE::EXCEPTION);
        }
    }
    else if(id == EventIdE::SIT_AT_TABLE){
        try{
            gameClub.ClientSit(event.GetTime(), event.GetStrArg(0), event.GetIntArg(0));
        }
        catch(GameClubException& err){
            CreateNewEvent(event.GetTime(), err.what(), EventIdE::EXCEPTION);
        }
    }
    else if(id == EventIdE::WAIT){
        try{
            gameClub.ClientWait(event.GetStrArg(0));
        }
        catch(SoBigQueueException& err){
            gameClub.ClientLive(event.GetTime(), event.GetStrArg(0));
            CreateNewEvent(event.GetTime(), err.what(), EventIdE::LEAVE_AT_END);
        }
        catch(GameClubException& err){
            CreateNewEvent(event.GetTime(), err.what(), EventIdE::EXCEPTION);
        }
    }
    else if(id == EventIdE::LEAVE){
        gameClub.ClientLive(event.GetTime(), event.GetStrArg(0));
    }
}

void EventAnalyzer::EndTimeAnalyze() {
    gameClub.Close();
    resultPrinter.PrintGameClub(gameClub);
}

void EventAnalyzer::CreateNewEvent(std::tm time, std::string mes, EventIdE eventIdE) {
    std::vector<std::string> args;
    args.push_back(std::to_string(time.tm_hour) + ":" + std::to_string(time.tm_min));
    args.push_back(std::to_string(static_cast<int>(eventIdE)));
    args.push_back(mes);
    Event newEvent(args);
    gameClub.AddEvent(time, newEvent);
}

