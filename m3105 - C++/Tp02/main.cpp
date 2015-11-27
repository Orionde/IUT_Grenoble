#include <cstdlib>
#include "Billet.h"
#include "Client.h"
#include "Conteneur.h"

using namespace std;

int main() {
    Trajet trajet("Grenoble", "Lyon", 34);
    Tarif tarif("Normal", 2);
    Billet billet(trajet, tarif);
    //billet.afficher(cout);
    Client c("Hubert");
    c.addBillet(billet);
    //c.afficher(cout);
    /*Conteneur <Billet> conteneur;
    conteneur.ajouter(billet);
    conteneur.afficher(cout);*/
    Conteneur <Trajet> c_traj;
    c_traj.ajouter(trajet);
    c_traj.choisirElement(cout, cin);

    return 0;
}