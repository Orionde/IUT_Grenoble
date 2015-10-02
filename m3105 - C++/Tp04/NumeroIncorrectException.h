#ifndef NUMEROINCCORECTEXCEPTION_H
#define	NUMEROINCCORECTEXCEPTION_H

#include "SalarieException.h"

class NumeroIncorrectException : public SalarieException {
public:
    NumeroIncorrectException(std::string num);
    const char *what() const noexcept;
private:
    std::string m_num;

};

#endif

