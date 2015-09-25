#include "Produit.h"

Produit::Produit(std::string nom) : m_nom(nom) {
}

std::string Produit::getNom() const {
    return m_nom;
}

void Produit::ajouter(Produit &produit) {
    throw "Ajout impossible";
}

void Produit::afficher(std::ostream &cout)
{
    cout << m_nom << " " << getPrix();
}