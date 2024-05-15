#include <cmath>
#include "Table.h"

Table::Table() {
    workTime = 0;
    profit = 0;
    empty = true;
}

void Table::StartWork(std::tm startTime) {
    this->startTime = startTime;
}

void Table::EndWork(std::tm endTime, int price) {
    int sTimeM = startTime.tm_hour * 60 + startTime.tm_min;
    int eTimeM = endTime.tm_hour * 60 + endTime.tm_min;
    double difTime = eTimeM - sTimeM;
    profit += std::ceil(difTime/ 60) * price;
    workTime += static_cast<int>(difTime);
}

int Table::GetProfit() const {
    return profit;
}


std::tm Table::GetWorkTime(){
    std::tm time;
    time.tm_hour = workTime / 60;
    time.tm_min = workTime % 60;
    return time;
}

bool Table::IsEmpty() const {
    return empty;
}

void Table::Cleared() {
    empty = true;
}

void Table::Occupied() {
    empty = false;
}
