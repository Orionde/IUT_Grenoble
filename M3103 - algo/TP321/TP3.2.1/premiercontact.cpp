

// documentation : http://www.cplusplus.com/reference/stack/stack/

#include <stack>
#include <string>
#include <iostream>
#include <cstdlib>
#include "PrecondVioleeExcep.h"

using namespace std;

/**
 * affiche les informations depuis le sommet jusqu'au fond de pile
 * @param unePile
 */
template<typename T>
void affichePile(stack<T> unePile) {
    // dupliquer la pile pour faire un parcours destructif (depile) sur celle-ci
    stack<T> pileTemporaire(unePile);
    cout << "En partant du sommet pile contient -> ";
    while (!pileTemporaire.empty()) {
        cout << pileTemporaire.top() << " ";
        pileTemporaire.pop();
    }
    cout << endl;
}

void testeEmpile() {
    cout << "-----------------------TEST EMPILE-------------------------" << endl;
    stack<string> pile;

    cout << "Est vide : " << pile.empty() << endl;

    pile.push("zero");
    affichePile(pile);

    pile.push("deux");
    affichePile(pile);

    pile.push("trois");
    affichePile(pile);

    pile.push("quatre");
    affichePile(pile);

    pile.push("cinq");
    affichePile(pile);

    cout << "Est vide : " << pile.empty() << endl;

}

void testeDepile() {
    cout << "-----------------------TEST DEPILE-------------------------" << endl;
    stack<string> pile;

    pile.push("zero");
    pile.push("un");
    pile.push("deux");
    pile.push("trois");
    pile.push("quatre");
    pile.push("cinq");

    affichePile(pile);

    while (!pile.empty()) {
        pile.pop();
        affichePile(pile);
    }

    affichePile(pile);

}

void testeBorneDepile() {
    cout << "-----------------------TEST BORNES-------------------------" << endl;
    stack<string> pile;

    //DEBUT testeBorneDepile()
    //
    //  Remplissage de la pile -->   ma pile actuelle -> En partant du sommet pile contient -> cinq quatre trois deux un zero 
    //  ma pile actuelle -> En partant du sommet pile contient -> quatre trois deux un zero 
    //  ma pile actuelle -> En partant du sommet pile contient -> trois deux un zero 
    //  ma pile actuelle -> En partant du sommet pile contient -> deux un zero 
    //  ma pile actuelle -> En partant du sommet pile contient -> un zero 
    //  ma pile actuelle -> En partant du sommet pile contient -> zero 
    //  ma pile actuelle -> En partant du sommet pile contient -> 
    //
    //pop() sur une pile vide :
    if (!pile.empty())
        pile.pop();
    else
        cout << "Pile vide." << endl;
    //  /!\ pop() sur une pile vide ne délenche pas d'exeption ; on a un comportement idéfini
    //  /!\ le programmeur doit s'assurer que cette situation ne se produit pas !
    //
    //  -> /!\ DESOLE, la pile est vide, pas de pop() possible !
    //
    //front() sur une pile vide : 
    //  /!\ front() sur une pile vide ne délenche pas d'exeption ; on a un comportement idéfini
    //  /!\ le programmeur doit s'assurer que cette situation ne se produit pas !
    //
    //  -> /!\ DESOLE, la pile est vide, pas de front() possible !
    pile.push("zero");
    pile.push("un");
    if (!pile.empty())
        cout << "top : " << pile.top() << endl;
    else
        cout << "Pile vide." << endl;
    //FIN testeBorneDepile()

}

int main() {
    testeEmpile();
    testeDepile();
    testeBorneDepile();
    return 0;
} // end main

// TRACE ATTENDU
/*
DEBUT testeEmpile()

  Liste vide ? : 1 devrait répondre vrai (1) !

  empile zéro --> En partant du sommet pile contient -> zero 
   - le sommet contient : zero
  empile un --> En partant du sommet pile contient -> un zero 
   - le sommet contient : un
  empile deux --> En partant du sommet pile contient -> deux un zero 
   - le sommet contient : deux
  empile trois --> En partant du sommet pile contient -> trois deux un zero 
   - le sommet contient : trois
  empile quatre --> En partant du sommet pile contient -> quatre trois deux un zero 
   - le sommet contient : quatre
  empile cinq --> En partant du sommet pile contient -> cinq quatre trois deux un zero 
   - le sommet contient : cinq
  Liste vide ? : 0 devrait répondre faux (0) !

FIN testeEmpile()

DEBUT testeDepile()

  Remplissage de la pile --> En partant du sommet pile contient -> cinq quatre trois deux un zero 

  3 consulteSommet() et depile()
   ma pile actuelle --> En partant du sommet pile contient -> cinq quatre trois deux un zero 
  sommet actuel : cinq
   ma pile actuelle --> En partant du sommet pile contient -> quatre trois deux un zero 
  sommet actuel : quatre
   ma pile actuelle --> En partant du sommet pile contient -> trois deux un zero 
  sommet actuel : trois
   ma pile actuelle --> En partant du sommet pile contient -> deux un zero 
  sommet actuel : deux

FIN testeDepile()

DEBUT testeBorneDepile()

  Remplissage de la pile -->   ma pile actuelle -> En partant du sommet pile contient -> cinq quatre trois deux un zero 
  ma pile actuelle -> En partant du sommet pile contient -> quatre trois deux un zero 
  ma pile actuelle -> En partant du sommet pile contient -> trois deux un zero 
  ma pile actuelle -> En partant du sommet pile contient -> deux un zero 
  ma pile actuelle -> En partant du sommet pile contient -> un zero 
  ma pile actuelle -> En partant du sommet pile contient -> zero 
  ma pile actuelle -> En partant du sommet pile contient -> 

pop() sur une pile vide :
  /!\ pop() sur une pile vide ne délenche pas d'exeption ; on a un comportement idéfini
  /!\ le programmeur doit s'assurer que cette situation ne se produit pas !

  -> /!\ DESOLE, la pile est vide, pas de pop() possible !

front() sur une pile vide : 
  /!\ front() sur une pile vide ne délenche pas d'exeption ; on a un comportement idéfini
  /!\ le programmeur doit s'assurer que cette situation ne se produit pas !

  -> /!\ DESOLE, la pile est vide, pas de front() possible !

FIN testeBorneDepile()

 */
