#pragma once

#include <string>
#include "../GameClubException.h"

class NotOpenYetException : public GameClubException{
    std::string err;
public:
    explicit NotOpenYetException(std::string err);
    const char* what() const noexcept override;
};


