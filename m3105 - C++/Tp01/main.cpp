
#include <cstdlib>
#include "EntierContraint.h"

using namespace std;

int main(int argc, char** argv) {
    int val = 2;
    int min = 1;
    int max = 3;
   try {
        EntierContraint entier(val, min, max);
        //entier.afficher();
        cin >> entier;
        cout << entier;
        //cout << "Pas d’exception levée" << endl;
        
        
    } catch (char const *erreur) {
        cout << "Exception levée : " << erreur << endl;
    }    
    return 0;
}

