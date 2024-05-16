#include "ClientUnknownException.h"

const char *ClientUnknownException::what() const noexcept {
    return GameClubException::what();
}

ClientUnknownException::ClientUnknownException(std::string err) :  GameClubException(err) {
}
