#pragma once

#include <exception>

namespace triplex {
    using std::exception;

    class invalid_level 
        : public exception {
        public:
            const char* what() const override;
    };
}