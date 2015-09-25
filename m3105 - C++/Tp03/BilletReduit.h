#ifndef BILLETREDUIT_H
#define BILLETREDUIT_H

#include "Billet.h"
#include "Promotion.h"

class BilletReduit : public Billet {

    private :
        const Promotion& m_promotion;        
    public:    

    BilletReduit(const Trajet& unTrajet, const Tarif& unTarif, const Promotion& unePromo);

    float getPrix() const;

    const Promotion& getPromotion() const;
};

#endif