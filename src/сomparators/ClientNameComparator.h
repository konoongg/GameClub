#pragma once


#include <string>

struct ClientNameCompare{
    bool operator()(const std::string& lhs, const std::string& rhs) const {
        return lhs < rhs;
    }
};

