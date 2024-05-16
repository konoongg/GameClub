#pragma once

#include <string>
#include "../GameClubException.h"

class ClientUnknownException : public GameClubException{
    std::string err;
public:
    explicit ClientUnknownException(std::string err);
    const char* what() const noexcept override;
};
