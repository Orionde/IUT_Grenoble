#include "Trajet.h"

const int Trajet::DISTANCEMIN = 1;
const int Trajet::DISTANCEMAX = 2000;

Trajet::Trajet(const std::string& villeDep, const std::string& villeArr, int dist) :
m_distance(dist, DISTANCEMIN, DISTANCEMAX) {
    setVilleDepart(villeDep);
    setVilleArrivee(villeArr);
}


std::string Trajet::getVilleDepart() const {
    return m_villeDepart;
}

void Trajet::setVilleDepart(const std::string& villeDep) {
    m_villeDepart = villeDep;
}

std::string Trajet::getVilleArrivee() const {
    return m_villeArrivee;
}

void Trajet::setVilleArrivee(const std::string& villeArr) {
    m_villeArrivee = villeArr;
}

int Trajet::getDistance() const {
    return m_distance.getVal();
}

void Trajet::saisir(std::istream& cin) {
    cin >> m_distance >> m_villeDepart >> m_villeArrivee;
}

void Trajet::afficher(std::ostream& cout) const {
    cout << m_distance << m_villeDepart << m_villeArrivee;
}
