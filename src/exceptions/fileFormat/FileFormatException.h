#pragma once

#include <exception>
#include <string>

class FileFormatException : public std::exception {
protected:
    std::string err;

public:
    FileFormatException(std::string err);
    const char* what() const noexcept override;
};