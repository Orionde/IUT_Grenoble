#ifndef SALARIEEXCEPTION_H
#define	SALARIEEXCEPTION_H

#include <exception>
#include <string>
#include <sstream>

class SalarieException : public std::exception {
public:

    virtual const char * what() const noexcept;

};

#endif

