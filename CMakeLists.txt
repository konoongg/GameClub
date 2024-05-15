cmake_minimum_required(VERSION 3.27)
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
        src/event/сomparators/TmComparator.h
        src/event/EventAnalyzer.h
        src/event/EventAnalyzer.cpp
        src/resultPrinter/ResultPrinter.h
        src/resultPrinter/ResultPrinter.cpp
        src/event/сomparators/ClientNameComparator.h)
