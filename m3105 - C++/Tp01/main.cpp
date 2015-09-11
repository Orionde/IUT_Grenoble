
#include <cstdlib>
//#include "EntierContraint.h"
#include "NombreContraint.h"

using namespace std;

int main(int argc, char** argv) {
    float val = 2;
    float min = 1;
    float max = 3;
   try {
        NombreContraint<float> entier(val, min, max);
        //entier.afficher();
        //cin >> entier;
        //cout << entier;
        entier.afficher();
        //cout << "Pas d’exception levée" << endl;
        
        
    } catch (char const *erreur) {
        cout << "Exception levée : " << erreur << endl;
    }    
    return 0;
}

