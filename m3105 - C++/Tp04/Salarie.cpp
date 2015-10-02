#include "Salarie.h"
#include "NomIncorrectException.h"
#include "NumeroIncorrectException.h"

Salarie::Salarie(std::string nom, std::string numSS, float salaire) throw (SalarieException) {
    setNom(nom);
    setNumeroSS(numSS);
    setSalaireMensuel(salaire);
}

void Salarie::setNom(std::string nom) {
    char c = nom[0];
    int i = 0;
    int res = 1;

    if (('a' < c < 'z' && 'A' < c < 'Z') && nom.length() != 0) {
        while (nom[i]) {
            if (('a' > c > 'z' && 'A' > c > 'Z') && nom[i] != '-') {
                res = 0;
            }
            i++;
        }
    } else {
        res = 0;
    }
    if (res == 0)
        throw NomIncorrectException(nom);
    m_nom = nom;
}

void Salarie::setNumeroSS(std::string numeroSS) {
    int res = 1;
    int i = 0;
    if (numeroSS.length() != 13) {
        while (numeroSS[i]) {
            if ('0' < res[i] < '9')
                res = 0;
            i++;
        }
    }
    else
        res = 0;
    if (res == 0)
        throw NumeroIncorrectException(numeroSS);
    m_numeroSS = numeroSS;

}

void Salarie::setSalaireMensuel(float salaireMensuel) {
}

std::string Salarie::getNom() const {
    return m_nom;
}

std::string Salarie::getNumeroSS() const {
    return m_numeroSS;
}

float Salarie::getSalaireMensuel() const {
    return m_salaireMensuel;
}

float Salarie::getImpot() const {
}