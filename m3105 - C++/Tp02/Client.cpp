#include "Client.h"

Client::Client(const string nom) : m_nom(nom) {
}

string Client::getNom() const {
    return m_nom;
}

vector<Billet> Client::getBillets() const
{
    return m_billets;
}

 void Client::addBillet(Billet b) const
 {
     m_billets.push_back(b);
 }