#ifndef BILLET_H
#define	BILLET_H
#include "Trajet.h"
#include "Tarif.h"
#include "Produit.h"

class Billet : public Produit{

private:
    const Trajet & m_trajet;
    const Tarif & m_tarif;

public:
    Billet(std:: string nom, const Trajet& untrajet, const Tarif& untarif);

    const Trajet& getTrajet() const;

    const Tarif& getTarif() const;

    virtual float getPrix() const;

    void afficher(std::ostream& cout) const;
};

#endif