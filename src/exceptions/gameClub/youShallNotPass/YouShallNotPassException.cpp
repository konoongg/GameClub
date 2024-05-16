#include "YouShallNotPassException.h"

const char *YouShallNotPassException::what() const noexcept {
    return GameClubException::what();
}

YouShallNotPassException::YouShallNotPassException(std::string err) :  GameClubException(err) {
}
