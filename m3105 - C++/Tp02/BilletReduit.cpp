#include "BilletReduit.h"

BilletReduit::BilletReduit(const Trajet& unTrajet, const Tarif& unTarif, const Promotion& unePromo) :
Billet::Billet(unTrajet, unTarif), m_promotion(unePromo){}

float BilletReduit::getPrix() const {
    return m_promotion.calculePrixReduit(Billet::getPrix());
}

const Promotion& BilletReduit::getPromotion() const {
    return m_promotion;
}