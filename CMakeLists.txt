cmake_minimum_required(VERSION 3.22)
project(GameClub)

set(CMAKE_CXX_STANDARD 17)

add_executable(GameClub src/main.cpp
        src/inputParser/InputParser.h
        src/inputParser/InputParser.cpp
        src/gameClub/GameClub.h
        src/gameClub/GameClub.cpp
        src/event/event/Event.h
        src/event/event/Event.cpp
        src/table/Table.h
        src/table/Table.cpp
        src/gameClub/GameClubCreator.h
        src/gameClub/GameClubCreator.cpp
        src/event/event/EventIdE.h
        src/gameClub/GameClubParamsT.h
        src/сomparators/TmComparator.h
        src/event/EventAnalyzer.h
        src/event/EventAnalyzer.cpp
        src/resultPrinter/ResultPrinter.h
        src/resultPrinter/ResultPrinter.cpp
        src/сomparators/ClientNameComparator.h
        "src/exceptions/gameClub/youShallNotPass/YouShallNotPassException.h"
        "src/exceptions/gameClub/youShallNotPass/YouShallNotPassException.cpp"
        "src/exceptions/gameClub/notOpenYet/NotOpenYetException.h"
        "src/exceptions/gameClub/notOpenYet/NotOpenYetException.cpp"
        "src/exceptions/gameClub/placeIsBusy/PlaceIsBusyException.h"
        "src/exceptions/gameClub/placeIsBusy/PlaceIsBusyException.cpp"
        "src/exceptions/gameClub/сlientUnknown/ClientUnknownException.h"
        "src/exceptions/gameClub/сlientUnknown/ClientUnknownException.cpp"
        "src/exceptions/gameClub/GameClubException.cpp"
        "src/exceptions/gameClub/soBigQueue/SoBigQueueException.cpp"
        "src/exceptions/gameClub/iCanWaitNoLonger/ICanWaitNoLongerException.h"
        "src/exceptions/gameClub/iCanWaitNoLonger/ICanWaitNoLongerException.cpp"
        src/exceptions/parsing/ParsingFileException.h
        src/exceptions/parsing/ParsingFileException.cpp
        src/exceptions/fileFormat/FileFormatException.cpp
        src/timeFixer/TimeFixer.h
        src/timeFixer/TimeFixer.cpp
)
