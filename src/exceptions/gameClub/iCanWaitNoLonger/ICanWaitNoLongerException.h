#pragma once

#include <string>
#include "../GameClubException.h"

class ICanWaitNoLongerException : public GameClubException{
    std::string err;
public:
    explicit ICanWaitNoLongerException(std::string err);
    const char* what() const noexcept override;
};


