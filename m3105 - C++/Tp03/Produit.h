#ifndef PRODUIT_H
#define	PRODUIT_H

#include <string>
#include <iostream>

class Produit {
public:
    Produit(std::string nom);
    
    std::string getNom() const;
    virtual float getPrix() const = 0;
    
    virtual void ajouter(Produit &produit);
    
   virtual void afficher(std::ostream &cout);
   
protected:
    std::string m_nom;
    
};

#endif

