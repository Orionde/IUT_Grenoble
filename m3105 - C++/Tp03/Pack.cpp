#include "Pack.h"

Pack::Pack(std::string nom) : Produit(nom) {
}

float Pack::getPrix() const {
    float prix = 0;
    for (auto ptr : m_produits)
        prix += ptr->getPrix();
    return prix;
}

void Pack::afficher(std::ostream &cout) const {
    for(auto ptr : m_produits)
            ptr->afficher(cout);
    
    
}

void Pack::ajouter(Produit &produit) {
    m_produits.push_back(&produit);
}
