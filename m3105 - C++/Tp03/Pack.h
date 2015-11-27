#ifndef PACK_H
#define	PACK_H

#include <string>
#include <iostream>
#include <vector>

#include "Produit.h"

class Pack : public Produit {
public:
    Pack(std::string nom);
    float getPrix() const;
    void afficher(std::ostream &cout) const;
    void ajouter(Produit &produit);

private:
    std::vector<Produit*> m_produits;
};

#endif
