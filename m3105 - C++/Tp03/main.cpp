#include <cstdlib>
#include <iostream>
#include "Billet.h"
#include "Client.h"
#include "Conteneur.h"
#include "Reservation.h"
#include "Pack.h"

using namespace std;

int main() {
    
    Reservation resa("resa1", 2, 31.2);
    resa.afficher(cout);
    cout << endl;
    float prixtotal = resa.getPrix();
    cout << prixtotal;
    
    Trajet t("Grenoble", "Paris", 124);
    Tarif ta("normal", 9);
    
    Billet billet1("truc", t, ta);
    billet1.afficher(cout);
    
    Pack pack("MonPack");
    
    pack.ajouter(resa);
    pack.ajouter(billet1);
    
    pack.afficher(cout);
    return 0;
}