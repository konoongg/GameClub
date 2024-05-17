

#include <iostream>
#include <iomanip>
#include "ResultPrinter.h"

void ResultPrinter::PrintGameClub(GameClub &gameClub) {
    std::cout << timeFixer.ToFixedWidthString(gameClub.GetStartTime().tm_hour) << ":" << timeFixer.ToFixedWidthString(gameClub.GetStartTime().tm_min) << std::endl;
    PrintEventList(gameClub.GetTimeLine());
    std::cout << timeFixer.ToFixedWidthString(gameClub.GetEndTime().tm_hour) << ":" << timeFixer.ToFixedWidthString(gameClub.GetEndTime().tm_min) << std::endl;
    PrintTableResult(gameClub.GetTable());
}

void ResultPrinter::PrintEventList(std::map<std::tm, std::vector<Event>, TmComparator> &timeLine) {
    for(const auto& pair : timeLine){
        const std::vector<Event>& events = pair.second;
        for(auto event : events){
            std::cout << timeFixer.ToFixedWidthString(event.GetTime().tm_hour) << ":" << timeFixer.ToFixedWidthString(event.GetTime().tm_min) << " " << static_cast<int>(event.GetId())<< " " << event.GetStrArg(0) << " " << std::endl;
        }
    }
}

void ResultPrinter::PrintTableResult(std::vector<Table> &tables) {
    for(int i = 0; i < tables.size(); ++i){
        int profit = tables[i].GetProfit();
        int hour = tables[i].GetWorkTime().tm_hour;
        int min = tables[i].GetWorkTime().tm_min;
        std::cout << i + 1<< " " << profit << " " << timeFixer.ToFixedWidthString(hour) << ":" << timeFixer.ToFixedWidthString(min) <<  std::endl;
    }
}


