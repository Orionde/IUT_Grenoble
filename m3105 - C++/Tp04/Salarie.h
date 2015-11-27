#ifndef SALARIE_H
#define	SALARIE_H

#include <iostream>
#include <string.h>
#include <ctype.h>

#include "SalarieException.h"


class Salarie {
public:
    Salarie(std::string nom, std::string numSS, float salaire) throw(SalarieException);

    std::string getNom() const;
    void setNom(std::string nom);

    std::string getNumeroSS() const;
    void setNumeroSS(std::string numeroSS);

    float getSalaireMensuel() const;
    void setSalaireMensuel(float salaireMensuel);

    float getImpot() const;

private:
    std::string m_nom;
    std::string m_numeroSS;
    float m_salaireMensuel;

};

#endif