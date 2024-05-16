#include <iostream>
#include "inputParser/InputParser.h"
#include "gameClub/GameClub.h"
#include "gameClub/GameClubCreator.h"
#include "event/EventAnalyzer.h"
#include "resultPrinter/ResultPrinter.h"
#include "exceptions/parsing/ParsingFileException.h"
#include "exceptions/fileFormat/FileFormatException.h"

int main(int argc, char* argv[]) {
    if(argc < 2){
        std::cout << "not enough arguments" << std:: endl;
        return 0;
    }
    try{
        InputParser parser(argv[1]);
        GameClubCreator gameClubCreator;
        ResultPrinter resultPrinter;
        GameClub gameClub = gameClubCreator.CreateGameClub(parser);
        EventAnalyzer eventAnalyzer(gameClub, resultPrinter);
        eventAnalyzer.AnalyzeTimeLine();
        return 0;
    }
    catch(ParsingFileException& err){
        std::cout << err.what() << std::endl;
        return 1;
    }
    catch(FileFormatException& err){
        std::cout << err.what() << std::endl;
        return 1;
    }
}
