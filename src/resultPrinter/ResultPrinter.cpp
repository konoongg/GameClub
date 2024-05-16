

#include <iostream>
#include <iomanip>
#include "ResultPrinter.h"

std::string ResultPrinter::ToFixedWidthString(int number) {
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << number;
    return oss.str();
}

void ResultPrinter::PrintGameClub(GameClub &gameClub) {
    std::cout << ToFixedWidthString(gameClub.GetStartTime().tm_hour) << ":" << ToFixedWidthString(gameClub.GetStartTime().tm_min) << std::endl;
    PrintEventList(gameClub.GetTimeLine());
    std::cout << ToFixedWidthString(gameClub.GetEndTime().tm_hour) << ":" << ToFixedWidthString(gameClub.GetEndTime().tm_min) << std::endl;
    PrintTableResult(gameClub.GetTable());
}

void ResultPrinter::PrintEventList(std::map<std::tm, std::vector<Event>, TmComparator> &timeLine) {
    for(const auto& pair : timeLine){
        const std::vector<Event>& events = pair.second;
        for(auto event : events){
            std::cout << ToFixedWidthString(event.GetTime().tm_hour) << ":" << ToFixedWidthString(event.GetTime().tm_min) << " " << static_cast<int>(event.GetId())<< " " << event.GetStrArg(0) << " " << std::endl;
        }
    }
}

void ResultPrinter::PrintTableResult(std::vector<Table> &tables) {
    for(int i = 0; i < tables.size(); ++i){
        int profit = tables[i].GetProfit();
        int hour = tables[i].GetWorkTime().tm_hour;
        int min = tables[i].GetWorkTime().tm_min;
        std::cout << i + 1<< " " << profit << " " << ToFixedWidthString(hour) << ":" << ToFixedWidthString(min) <<  std::endl;
    }

}


