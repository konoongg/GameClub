#include "ICanWaitNoLongerException.h"


const char *ICanWaitNoLongerException::what() const noexcept {
    return GameClubException::what();
}

ICanWaitNoLongerException::ICanWaitNoLongerException(std::string err) : GameClubException(err) {
}
