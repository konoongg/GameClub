#include <algorithm>
#include "GameClub.h"
#include "../exceptions/gameClub/youShallNotPass/YouShallNotPassException.h"
#include "../exceptions/gameClub/notOpenYet/NotOpenYetException.h"
#include "../exceptions/gameClub/placeIsBusy/PlaceIsBusyException.h"
#include "../exceptions/gameClub/сlientUnknown/ClientUnknownException.h"
#include "../exceptions/gameClub/soBigQueue/SoBigQueueException.h"
#include "../exceptions/gameClub/iCanWaitNoLonger/ICanWaitNoLongerException.h"

GameClub::GameClub(GameClubParamsT params) {
    price = params.price;
    startTm = params.startTm;
    endTm = params.endTm;
    countTable = params.countTable;
    countFreeTable = params.countTable;
    for(int i = 0; i < params.countTable; ++i){
        Table table;
        tables.push_back(table);
    }
}

void GameClub::AddEvent(std::tm time, const Event& event) {
    auto it = timeLine.find(time);
    if(it != timeLine.end()){
        (it->second).push_back(event);
    }
    else{
        std::vector<Event> events;
        events.push_back(event);
        timeLine[time] = events;
    }
}

std::map<std::tm, std::vector<Event>, TmComparator>& GameClub::GetTimeLine() {
    return timeLine;
}

bool GameClub::CompareTm(std::tm tm1, std::tm tm2) {
    if(tm1.tm_hour > tm2.tm_hour){
        return true;
    }
    else if (tm1.tm_hour ==  tm2.tm_hour && tm1.tm_min >=  tm2.tm_min ){
        return true;
    }
    return false;
}


void GameClub::ClientCame(std::tm time, const std::string& clientName) {
    if(ClientExist(clientName)){
        throw YouShallNotPassException {"YouShallNotPass"};
    }
    else if(CompareTm(time, startTm) && CompareTm(endTm, startTm)){
        clients.insert(clientName);
    }
    else{
        throw NotOpenYetException{"NotOpenYet"};
    }
}

bool GameClub::ClientExist(const std::string&  clientName){
    auto it = std::find(clients.begin(), clients.end(), clientName);
    if (it != clients.end()) {
        return true;
    }
    return false;
}

void GameClub::ClientSit(std::tm time, const std::string& clientName, int tableId) {
    if(tables[tableId - 1].IsEmpty()){
        if(!ClientExist(clientName)){
            throw ClientUnknownException{"ClientUnknown"};
        }
        else {
            auto it = clientTable.find(clientName);
            if(it != clientTable.end()){
                tables[clientTable[clientName]].EndWork(time, price);
                tables[clientTable[clientName]].Cleared();
            }
            else{
                countFreeTable--;
                tables[clientTable[clientName]].Occupied();
            }
            clientTable[clientName] = tableId - 1;
            tables[tableId - 1].StartWork(time);
            tables[tableId - 1].Occupied();
        }
    }
    else{
        throw PlaceIsBusyException{"PlaceIsBusy"};
    };
}

void GameClub::ClientWait(const std::string& clientName) {
    if(!ClientExist(clientName)){
        throw ClientUnknownException{"ClientUnknown"};
    }
    if(countFreeTable > 0){
        throw ICanWaitNoLongerException{"ICanWaitNoLonger"};
    }
    else if(clientsWait.size() >= countTable){
        throw SoBigQueueException{"SoBigQueue"};
    }
    else{
        clientsWait.push(clientName);
    }
}

void GameClub::ClientLive(std::tm time, std::string clientName) {
    if(!ClientExist(clientName)){
        throw ClientUnknownException{"ClientUnknown"};
    }
    auto it = clientTable.find(clientName);
    if(it != clientTable.end()){
        int tableId = clientTable[clientName];
        tables[tableId].EndWork(time, price);
        clientTable.erase(clientName);
        clients.erase(clientName);
        if(clientsWait.empty()){
            countFreeTable++;
            tables[tableId].Cleared();
        }
        else{
            tables[tableId].StartWork(time);
            std::string newClientName = clientsWait.front();
            clientsWait.pop();
            clientTable[newClientName] = tableId;
            std::vector<std::string> args;
            args.push_back(std::to_string(time.tm_hour) + ":" + std::to_string(time.tm_min));
            args.push_back(std::to_string(static_cast<int>(EventIdE::SIT_AT_EMPTY_TABLE)));
            args.push_back(newClientName);
            args.push_back(std::to_string(tableId));
            Event newEvent(args);
            AddEvent(time, newEvent);
        }
    }
}

void GameClub::Close() {
    for(auto& table : tables){
        if(!table.IsEmpty()){
            table.EndWork(endTm, price);
            table.Cleared();
        }
    }
    for(const auto& client : clients){
        std::vector<std::string> args;
        args.push_back(std::to_string(endTm.tm_hour) + ":" + std::to_string(endTm.tm_min));
        args.push_back(std::to_string(static_cast<int>(EventIdE::EXCEPTION)));
        args.push_back(client);
        Event endEvent(args);
        timeLine[endTm].push_back(endEvent);
    }
}

std::vector<Table> &GameClub::GetTable() {
    return tables;
}

std::tm GameClub::GetStartTime() {
    return startTm;
}

std::tm GameClub::GetEndTime() {
    return endTm;
}
