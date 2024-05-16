#include "ParsingFileException.h"

const char *ParsingFileException::what() const noexcept {
    return err.data();
}

ParsingFileException::ParsingFileException(std::string err) {
    this->err = std::move(err);
}
