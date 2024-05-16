#include "SoBigQueueException.h"


const char *SoBigQueueException::what() const noexcept {
    return GameClubException::what();
}

SoBigQueueException::SoBigQueueException(std::string err) :  GameClubException(err) {
}
