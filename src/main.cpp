#include <iostream>
#include "inputParser/InputParser.h"
#include "gameClub/GameClub.h"
#include "gameClub/GameClubCreator.h"
#include "event/EventAnalyzer.h"
#include "resultPrinter/ResultPrinter.h"

int main(int argc, char* argv[]) {
    if(argc < 2){
        std::cout << "not enough arguments" << std:: endl;
        return 0;
    }
    InputParser parser(argv[1]);
    GameClubCreator gameClubCreator;
    ResultPrinter resultPrinter;
    GameClub gameClub = gameClubCreator.CreateGameClub(parser);
    EventAnalyzer eventAnalyzer(gameClub, resultPrinter);
    eventAnalyzer.AnalyzeTimeLine();
    return 0;
}
