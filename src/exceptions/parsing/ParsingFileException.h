#pragma once

#include <exception>
#include <string>

class ParsingFileException : public std::exception {
protected:
    std::string err;

public:
    ParsingFileException(std::string err);
    const char* what() const noexcept override;
};