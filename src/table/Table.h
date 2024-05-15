#pragma once


#include <ctime>

class Table {
    int workTime;
    int profit;
    std::tm startTime;
    bool empty;
public:
    Table();
    void StartWork(std::tm startTime);
    void EndWork(std::tm endTime, int price);
    int GetProfit() const;
    std::tm GetWorkTime();
    bool IsEmpty() const;
    void Occupied();
    void Cleared();
};

