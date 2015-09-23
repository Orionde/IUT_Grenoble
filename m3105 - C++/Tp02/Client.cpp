#include "Client.h"

Client::Client(const string nom) : m_nom(nom) {
}

string Client::getNom() const {
    return m_nom;
}

const vector<const Billet*>& Client::getBillets() const
{
    return m_billets;
}

 void Client::addBillet(const Billet &b)
 {
     m_billets.push_back(&b);
 }