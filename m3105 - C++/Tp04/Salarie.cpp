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
    int i = 1;
    int res = 1;

    std::cout << nom << std::endl;
    if (((('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))) && nom.length() > 0) {
        while (i < (int) nom.length() && res == 1) {
            if (((('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))) || nom[i] == '-') {
                i++;
            } else {
                res = 0;
            }
        }
    } else {
        res = 0;
    }
    if (res == 0) {

        throw NomIncorrectException(nom);
    }
    m_nom = nom;
}

void Salarie::setNumeroSS(std::string numeroSS) {
    int res = 1;
    int i = 0;

    std::cout << numeroSS << std::endl;

    if (numeroSS.length() == 13) {
        while (numeroSS[i] && res) {
            if ('0' > numeroSS[i] || numeroSS[i] > '9') {
                res = 0;

            }
            i++;
        }
    } else
        res = 0;
    if (res == 0) {
        throw NumeroIncorrectException(numeroSS);
    }
    m_numeroSS = numeroSS;

}

void Salarie::setSalaireMensuel(float salaireMensuel) {
    std::cout << salaireMensuel << std::endl;

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
    return (7);
}
