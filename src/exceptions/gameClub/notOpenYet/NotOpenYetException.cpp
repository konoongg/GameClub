#include "NotOpenYetException.h"


const char *NotOpenYetException::what() const noexcept {
    return GameClubException::what();
}

NotOpenYetException::NotOpenYetException(std::string err): GameClubException(err) {
}
