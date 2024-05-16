#pragma once

#include <string>
#include "../GameClubException.h"

class YouShallNotPassException : public GameClubException{
    std::string err;
public:
    explicit YouShallNotPassException(std::string err);
    const char* what() const noexcept override;
};


