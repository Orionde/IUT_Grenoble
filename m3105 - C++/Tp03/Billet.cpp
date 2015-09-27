#include "Billet.h"

Billet::Billet(std::string nom, const Trajet& untrajet, const Tarif& untarif) : Produit(nom), 
m_trajet(untrajet), m_tarif(untarif){}

const Trajet& Billet::getTrajet() const {
    return m_trajet;
}

const Tarif& Billet::getTarif() const {
    return m_tarif;
}

float Billet::getPrix() const {
    return m_trajet.getDistance() * m_tarif.getPrixAuKm();
}

void Billet::afficher(std::ostream& cout) const {
    m_trajet.afficher(cout);
    m_tarif.afficher(cout);
}