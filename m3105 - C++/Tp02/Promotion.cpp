#include "Promotion.h"

const float Promotion::TAUXMIN = 0.01 ;
const float Promotion::TAUXMAX = 0.99;

Promotion::Promotion(const std::string& unLibelle, float unTaux) :
m_libelle(unLibelle), m_tauxReduction(unTaux, TAUXMIN, TAUXMAX){}

std::string Promotion::getLibelle() const {
    return m_libelle;
}

float Promotion::calculePrixReduit(float prix) const {
    return prix - (prix * m_tauxReduction.getVal());
}

void Promotion::saisir(std::istream& cin) {
    cin >> m_libelle >> m_tauxReduction;
}

void Promotion::afficher(std::ostream& cout) const {
     cout << m_libelle << m_tauxReduction;
}
