#ifndef CLIENT_H
#define	CLIENT_H

#include <string>
#include <vector>
#include "Billet.h"


using namespace std;

class Client {

public:
    Client(const string nom);
    string getNom() const;
    const vector<const Billet*>& getBillets() const;
    void addBillet(const Billet &b);
    void afficher(std::ostream& cout) const;
    float getPrix() const;
private:
    string m_nom;
    vector<const Billet*> m_billets;

};

#endif

