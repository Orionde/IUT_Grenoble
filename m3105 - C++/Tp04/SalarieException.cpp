#include "SalarieException.h"

const char *SalarieException::what() const noexcept {
        return "Exception Salarié ";
    }