#pragma once

#include <string>
#include "../GameClubException.h"

class PlaceIsBusyException : public GameClubException{
    std::string err;
public:
    explicit PlaceIsBusyException(std::string err);
    const char* what() const noexcept override;
};


