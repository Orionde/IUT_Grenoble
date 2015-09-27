#include "BilletReduit.h"

BilletReduit::BilletReduit(std::string nom, const Trajet& unTrajet, const Tarif& unTarif, const Promotion& unePromo) :
Billet::Billet(nom, unTrajet, unTarif), m_promotion(unePromo){}

float BilletReduit::getPrix() const {
    return m_promotion.calculePrixReduit(Billet::getPrix());
}

const Promotion& BilletReduit::getPromotion() const {
    return m_promotion;
}
