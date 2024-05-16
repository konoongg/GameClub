#pragma once

#include <exception>
#include <string>

class GameClubException : public std::exception {
protected:
    std::string err;

public:
    GameClubException(std::string err);
    virtual const char* what() const noexcept override;
};