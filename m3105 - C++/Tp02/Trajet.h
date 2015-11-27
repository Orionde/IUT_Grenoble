#ifndef TRAJET_H
#define TRAJET_H

#include <string>
#include "NombreContraint.h"
class Trajet {

private:
    std::string m_villeDepart;
    std::string m_villeArrivee;
    NombreContraint<int> m_distance;
    const static int DISTANCEMIN;
    const static int DISTANCEMAX;

public:
    Trajet(const std::string& villeDep, const std::string& villeArr, int dist);

    std::string getVilleDepart() const;

    void setVilleDepart(const std::string& villeDep);

    std::string getVilleArrivee() const;

    void setVilleArrivee(const std::string& villeArr);

    int getDistance() const;

    void saisir(std::istream& cin);

    void afficher(std::ostream& cout) const;
};
#endif