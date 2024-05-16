#include "FileFormatException.h"

const char *FileFormatException::what() const noexcept {
    return err.data();
}

FileFormatException::FileFormatException(std::string err) {
    this->err = std::move(err);
}
