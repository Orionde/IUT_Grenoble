#ifndef SALAIREINCORRECTEXCEPTION_H
#define	SALAIREINCORRECTEXCEPTION_H

#include "SalarieException.h"
#include <sstream>
class SalaireIncorrectException : public SalarieException{
public:
    SalaireIncorrectException(float salaire);
    const char *what() const noexcept;
private:
    float m_salaire;
};

#endif