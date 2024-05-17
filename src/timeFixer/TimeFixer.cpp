#include <iomanip>
#include "TimeFixer.h"

std::string TimeFixer::ToFixedWidthString(int number) {
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << number;
    return oss.str();
}