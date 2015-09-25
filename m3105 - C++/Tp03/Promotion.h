#ifndef PROMOTION_H
#define PROMOTION_H

#include <string>
#include <iostream>
#include "NombreContraint.h"

class Promotion {

private:
    std::string m_libelle;
    NombreContraint<float> m_tauxReduction;
    static const float TAUXMIN;
    static const float TAUXMAX;

public:
    Promotion(const std::string& unLibelle, float unTaux);

    std::string getLibelle() const;

    void setLibelle(const std::string& libelle);

    float calculePrixReduit(float prix) const;

    void saisir(std::istream& cin);

    void afficher(std::ostream& cout) const;
};

#endif