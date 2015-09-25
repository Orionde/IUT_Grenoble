#include "Pack.h"

Pack::Pack(std::string nom) : Produit(nom){
}

float Pack::getPrix() const
{
    float prix;
    for(auto ptr : m_produits)
        prix += ptr->getPrix();
    return prix;
}



