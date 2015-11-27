#include "NumeroIncorrectException.h"

NumeroIncorrectException::NumeroIncorrectException(std::string num): m_num(num) {}

const char * NumeroIncorrectException::what() const noexcept {
    std::stringstream s;
    s << SalarieException::what() << "numéro incorrect : " << m_num;
    return s.str().c_str();
}