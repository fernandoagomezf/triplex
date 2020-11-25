#include "invalid_level.hpp"

using triplex::invalid_level;

const char* invalid_level::what() const {
    return "An invalid level was requested.";
}