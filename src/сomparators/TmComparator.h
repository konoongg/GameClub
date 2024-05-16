#pragma once

#include <ctime>

struct TmComparator {
    bool operator()(const std::tm& lhs, const std::tm& rhs) const {
        if (lhs.tm_hour < rhs.tm_hour) return true;
        if (lhs.tm_hour > rhs.tm_hour) return false;
        if (lhs.tm_min < rhs.tm_min) return true;
        if (lhs.tm_min > rhs.tm_min) return false;
        return false;
    }
};



