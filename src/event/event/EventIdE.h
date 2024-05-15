#pragma once

enum class EventIdE : int {
    CAME = 1,
    SIT_AT_TABLE = 2,
    WAIT = 3,
    LEAVE = 4,
    LEAVE_AT_END = 11,
    SIT_AT_EMPTY_TABLE = 12,
    EXCEPTION = 13
};
