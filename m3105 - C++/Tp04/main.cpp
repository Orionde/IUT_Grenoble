#include <cstdlib>
#include <iostream>

#include "NomIncorrectException.h"
#include "NumeroIncorrectException.h"
#include "Salarie.h"


using namespace std;

int main() {

    try {
        Salarie s1("jacqueline", "1234567891234", 12.5);
    }
    catch(NomIncorrectException &e)
    {
        cout << e.what() << endl;
    }
    
    catch(NumeroIncorrectException &e)
    {
        cout << e.what() << endl;
    }
    return 0;
}
