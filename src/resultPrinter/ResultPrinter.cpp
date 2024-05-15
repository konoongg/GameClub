

#include <iostream>
#include "ResultPrinter.h"

void ResultPrinter::PrintGameClub(GameClub &gameClub) {
    PrintEventList(gameClub.GetTimeLine());
    PrintTableResult(gameClub.GetTable());
}

void ResultPrinter::PrintEventList(std::map<std::tm, std::vector<Event>, TmComparator> &timeLine) {
    for(const auto& pair : timeLine){
        const std::vector<Event>& events = pair.second;
        for(auto event : events){
            std::cout << event.GetTime().tm_hour << ":" << event.GetTime().tm_min << " " << static_cast<int>(event.GetId())<< " " << event.GetStrArg(0) << " " << std::endl;
        }
    }
}

void ResultPrinter::PrintTableResult(std::vector<Table> &tables) {
    for(int i = 0; i < tables.size(); ++i){
        int profit = tables[i].GetProfit();
        int hour = tables[i].GetWorkTime().tm_hour;
        int min = tables[i].GetWorkTime().tm_min;
        std::cout << i << " " << profit << " " << hour << ":" <<min <<  std::endl;
    }

}


