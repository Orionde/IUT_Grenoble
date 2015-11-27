#include "SalaireIncorrectException.h"

SalaireIncorrectException::SalaireIncorrectException(float salaire) : m_salaire(salaire) {}

const char * SalaireIncorrectException::what() const noexcept
{
    std::stringstream s;
    s << SalarieException::what() << "salaire incorrect" << m_salaire;
    return s.str().c_str();
}
