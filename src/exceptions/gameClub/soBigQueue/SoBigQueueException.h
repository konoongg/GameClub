#pragma once

#include <string>
#include "../GameClubException.h"

class  SoBigQueueException : public GameClubException{
    std::string err;
public:
    explicit  SoBigQueueException(std::string err);
    const char* what() const noexcept override;
};


