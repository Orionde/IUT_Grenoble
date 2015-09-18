#include "Tarif.h"

const float Tarif::PRIXMIN = 0.01;
const float Tarif::PRIXMAX = 10.00;
Tarif::Tarif(const std::string& unLibelle, float unPrixKilo) : 
m_libelle(unLibelle), m_prixAuKm(unPrixKilo, PRIXMIN, PRIXMAX){}

std::string Tarif::getLibelle() const {
    return m_libelle;
}


float Tarif::getPrixAuKm() const {
    return m_prixAuKm.getVal();
}

void Tarif::saisir(std::istream& cin) {
    cin >> m_libelle >> m_prixAuKm;
}

void Tarif::afficher(std::ostream& cout) const {
    cout << m_libelle << m_prixAuKm;
}
