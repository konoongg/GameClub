#include "EventAnalyzer.h"
#include "../exceptions/gameClub/notOpenYet/NotOpenYetException.h"
#include "../exceptions/gameClub/youShallNotPass/YouShallNotPassException.h"
#include "../exceptions/gameClub/soBigQueue/SoBigQueueException.h"
#include "../exceptions/fileFormat/FileFormatException.h"


EventAnalyzer::EventAnalyzer(GameClub& gameClub, ResultPrinter& resultPrinter) : gameClub(gameClub),  resultPrinter(resultPrinter) {}

void EventAnalyzer::AnalyzeTimeLine() {
    for(auto & it : gameClub.GetTimeLine()){
        const std::vector<Event>& events = it.second;
        for(const auto& event : events){
            try{
                AnalyzeEvent(event);
            }
            catch(FileFormatException& err){
                throw err;
            }
        }
    }
    try{
        EndTimeAnalyze();
    }
    catch(FileFormatException& err){
        throw err;
    }
}

void EventAnalyzer::AnalyzeEvent(Event event) {
    EventIdE id = event.GetId();
    if(id == EventIdE::CAME){
        try{
            gameClub.ClientCame(event.GetTime(), event.GetStrArg(0));
        }
        catch(GameClubException& err){
            try{
                CreateNewEvent(event.GetTime(), err.what(), EventIdE::EXCEPTION);
            }
            catch(FileFormatException& err){
                throw err;
            }
        }
    }
    else if(id == EventIdE::SIT_AT_TABLE){
        try{
            gameClub.ClientSit(event.GetTime(), event.GetStrArg(0), event.GetIntArg(0));
        }
        catch(GameClubException& err){
            try{
                CreateNewEvent(event.GetTime(), err.what(), EventIdE::EXCEPTION);
            }
            catch(FileFormatException& err){
                throw err;
            }
        }
    }
    else if(id == EventIdE::WAIT){
        try{
            gameClub.ClientWait(event.GetStrArg(0));
        }
        catch(SoBigQueueException& err){
            gameClub.ClientLive(event.GetTime(), event.GetStrArg(0));
            try{
                CreateNewEvent(event.GetTime(), err.what(), EventIdE::LEAVE_AT_END);
            }
            catch(FileFormatException& err){
                throw err;
            }
        }
        catch(GameClubException& err){
            try{
                CreateNewEvent(event.GetTime(), err.what(), EventIdE::EXCEPTION);
            }
            catch(FileFormatException& err){
                throw err;
            }
        }
    }
    else if(id == EventIdE::LEAVE){
        gameClub.ClientLive(event.GetTime(), event.GetStrArg(0));
    }
}

void EventAnalyzer::EndTimeAnalyze() {
    try{
        gameClub.Close();
    }
    catch(FileFormatException& err){
        throw err;
    }
    resultPrinter.PrintGameClub(gameClub);
}

void EventAnalyzer::CreateNewEvent(std::tm time, std::string mes, EventIdE eventIdE) {
    std::vector<std::string> args;
    args.push_back(timeFixer.ToFixedWidthString(time.tm_hour) + ":" + timeFixer.ToFixedWidthString(time.tm_min));
    args.push_back(std::to_string(static_cast<int>(eventIdE)));
    args.push_back(mes);
    try{
        Event newEvent(args);
        gameClub.AddEvent(time, newEvent);
    }
    catch(FileFormatException& err){
        throw err;
    }
}

