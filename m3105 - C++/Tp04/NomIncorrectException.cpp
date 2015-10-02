#include "NomIncorrectException.h"

NomIncorrectException::NomIncorrectException(std::string nom) : m_nom(nom) {
}

const char * NomIncorrectException::what() const noexcept {
    std::stringstream s;
    s << SalarieException::what() << "nom incorrect : " << m_nom;
    return s.str().c_str();
}