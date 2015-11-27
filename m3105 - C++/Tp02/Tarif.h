#ifndef TARIF_H
#define TARIF_H
#include <iostream>
#include <string>
#include "NombreContraint.h"
class Tarif {

private:
    std::string m_libelle;
    NombreContraint<float> m_prixAuKm;
    
    static const float PRIXMIN;
    static const float PRIXMAX;

public:
    Tarif(const std::string& unLibelle, float unPrixKilo);

    std::string getLibelle() const;

    void setLibelle(std::string libelle);

    float getPrixAuKm() const;

    void saisir(std::istream& cin);

    void afficher(std::ostream& cout) const;
};
#endif