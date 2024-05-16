#include "PlaceIsBusyException.h"


const char *PlaceIsBusyException::what() const noexcept {
    return GameClubException::what();
}

PlaceIsBusyException::PlaceIsBusyException(std::string err) :  GameClubException(err){
}
