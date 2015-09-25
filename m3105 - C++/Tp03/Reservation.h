#ifndef RESERVATION_H
#define	RESERVATION_H

#include <string>
#include <iostream>
#include "NombreContraint.h"
#include "Produit.h"

class Reservation : public Produit{
public:
    Reservation(std::string nomHotel, int nbJours, float prixJour);
    
    float getPrix() const;
    void afficher(std::ostream cout);
private:
    NombreContraint<int> m_nbJours;
    NombreContraint<float> m_prixJour;
};

#endif

