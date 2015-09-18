#ifndef CLIENT_H
#define	CLIENT_H

#include <string>
#include <vector>
#include "Billet.h"


using namespace std;

class Client {

public:
    Client(const string nom);
    string getNom() const ;
    vector<Billet> getBillets() const;
    void addBillet(Billet b) const;
private:
    string m_nom;
    vector<Billet> m_billets;

};

#endif

