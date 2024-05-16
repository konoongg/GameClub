#include "GameClubException.h"

const char *GameClubException::what() const noexcept {
    return err.data();
}

GameClubException::GameClubException(std::string err) {
    this->err = std::move(err);
}
