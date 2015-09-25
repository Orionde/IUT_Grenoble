#include "Reservation.h"

Reservation::Reservation(std::string nomHotel, int nbJours, float prixJour) : Produit(nomHotel),
m_nbJours(nbJours, 1, 365), m_prixJour(prixJour, 30, 1000) {
}

float Reservation::getPrix() const {
    return m_nbJours.getVal() * m_prixJour.getVal();
}
void Reservation::afficher(std::ostream cout)
{
    cout << m_nbJours.getVal() << " " << m_prixJour.getVal();
}
