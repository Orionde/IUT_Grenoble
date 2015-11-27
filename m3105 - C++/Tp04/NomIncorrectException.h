#ifndef NOMINCORRECTEXCEPTION_H
#define	NOMINCORRECTEXCEPTION_H


#include "SalarieException.h"
#include <sstream>

class NomIncorrectException : public SalarieException {
public:
    NomIncorrectException(std::string nom);
    const char *what() const noexcept;
private:
    std::string m_nom;
};

#endif

