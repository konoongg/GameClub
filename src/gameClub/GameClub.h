#pragma once

#include <ctime>
#include <string>
#include <map>
#include <queue>
#include <set>
#include "../event/event/EventIdE.h"
#include "GameClubParamsT.h"
#include "../event/event/Event.h"
#include "../table/Table.h"
#include "../event/сomparators/TmComparator.h"
#include "../event/сomparators/ClientNameComparator.h"

class GameClub {
    std::tm startTm{};
    std::tm endTm{};
    int price;
    int countFreeTable;
    int countTable;
    std::map<std::tm, std::vector<Event>, TmComparator> timeLine;
    std::map<std::string, int> clientTable;
    std::vector<Table> tables;
    std::queue<std::string> clientsWait;
    std::set<std::string, ClientNameCompare> clients;

    bool CompareTm(std::tm tm1, std::tm tm2);
    bool ClientExist(const std::string& clientName);

public:
    explicit GameClub(GameClubParamsT params);
    void AddEvent(std::tm time , const Event& event);
    std::map<std::tm, std::vector<Event>, TmComparator>& GetTimeLine();
    std::vector<Table>& GetTable();
    void ClientCame(std::tm time, const std::string&  clientName);
    void ClientSit(std::tm time, const std::string& clientName, int tableId);
    void ClientLive(std::tm time, std::string clientName);
    void ClientWait(const std::string& clientName);
    void Close();
};

