#include <cstdlib>
#include "Billet.h"

using namespace std;

int main() {
    Trajet trajet("Grenoble", "Lyon", 34);
    Tarif tarif("Normal", 2);
    Billet billet(trajet, tarif);
    billet.afficher(cout);
    Client c("Hubert");
    c.add(billet);

    return 0;
}

