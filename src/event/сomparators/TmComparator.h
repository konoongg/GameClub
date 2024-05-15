#pragma once

#include <ctime>

struct TmComparator {
    bool operator()(const std::tm& lhs, const std::tm& rhs) const {
        if (lhs.tm_year < rhs.tm_year) return true;
        if (lhs.tm_year > rhs.tm_year) return false;
        if (lhs.tm_mon < rhs.tm_mon) return true;
        if (lhs.tm_mon > rhs.tm_mon) return false;
        if (lhs.tm_mday < rhs.tm_mday) return true;
        return false;
    }
};



