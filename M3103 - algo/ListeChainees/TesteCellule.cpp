/* 
 * File:   TestCellules.cpp
 * Author: hb
 *
 * Created on 16 août 2014, 17:53
 */

#include <cstdlib>
#include <iostream>

#include "Cellule.h"

using namespace std;

/**
 * Une procédure modèle qui affiche des Cellules contenant n'importe quel type d'information
 * ATTENTION il faut que les éléments puissent s'afficher savec la méthode
 *            -> affiche() de la classe Cellule
 * 
 * @param unePile
 */
template<typename TypeInfo>
void afficheCellules(Cellule<TypeInfo>* ptrCell) {
    //variable pour le parcours le la liste de cellules initialisée avec la valeur du paramètre effectif
    Cellule<TypeInfo>* ptrCellCour;
    // Initialisaton
    ptrCellCour = ptrCell;
    cout << "la liste de cellules contient -> ";
    // Tant qu'il y a une cellule
    while (ptrCellCour) {
        // Afficher le contenu de la Cellule courante
        ptrCellCour->affiche();
        cout << ' ';
        // Avancer sur la Cellule suivante
        ptrCellCour = ptrCellCour->getSuivante();
    }
    cout << endl;
} // end afficheCellulesFromCell

int main() {
    /*
     * UNE TRACE DU RESULTAT A OBTENIR EST PROPOSEE EN FIN DE FICHIER
     */

    // PREMIERE PARTIE
    cout << "MANIPULATION DE POINTEUR SUR DES CELLULES CONTENANT DES ENTIERS" << endl;
    // Déclarer et construire une variable ptrCelInt1 de type pointeur sur une Cellule entière (Cellule<int>*) contenant la valeur 2
    Cellule<int>* ptrCelInt1 = new Cellule<int>(2);

    cout << "L'information portée par la cellule CelInt1 est : ";
    // Afficher l'information portée par la cellule
    ptrCelInt1->affiche();

    cout << endl;

    // Déclarer et construire une variable ptrCelInt2 de type pointeur sur une Cellule entière (Cellule<int>*) contenant la valeur 3
    Cellule<int>* ptrCelInt2 = new Cellule<int>(3);

    // Faire en sorte que CelInt2 soit la cellule qui suit la cellule CelInt1
    ptrCelInt1->setSuivante(ptrCelInt2);

    // Afficher la liste dont la tête de liste est CelInt2 avec la procédure affiche()
    cout << "A partir de CelInt2, " << endl;
    ptrCelInt2->affiche();
    

    // Déclarer et construire une variable ptrCelInt3 de type pointeur sur une Cellule entière (Cellule<int>*) contenant la valeur 1
    // et qui est suivie de CelInt1
     Cellule<int>* ptrCelInt3 = new Cellule<int>(1);
     ptrCelInt3->setSuivante(ptrCelInt1);

    // Afficher la liste dont la tête de liste est CelInt3 avec la procédure afficheCellules()
    Cellule<int> *tmp = ptrCelInt3;
    
    cout << endl << "AFFICHAGE DE LA LISTE : " << endl;
    while(tmp != nullptr)
    {
       tmp->affiche();
       cout << " ";
       tmp = tmp->getRefSuivante();
    }
     cout << endl << "FIN AFFICHAGE DE LA LISTE." << endl;


    // DEUXIEME PARTIE
    cout << endl << endl << "MANIPULATION DE CELLULES CONTENANT DES ENTIERS" << endl;
    // Déclarer et construire une variable CelInt1 de type Cellule entière (Cellule<int>) contenant la valeur 2
    Cellule<int> cellInt1(2);

    cout << "L'information portée par la cellule CelInt1 est : ";
    //Afficher l'information portée par la cellule
    cellInt1.affiche();
    cout << endl;

    // Déclarer et construire une variable ptrCelInt2 de type Cellule entière (Cellule<int>) contenant la valeur 3
    Cellule<int> cellInt2(3);

    // Faire en sorte que CelInt2 soit la cellule qui suit la cellule CelInt1
    cellInt1.setSuivante(&cellInt2);

    // Afficher la liste dont la tête de liste est CelInt2 avec la procédure afficheCellules()
    cout << "A partir de CelInt2, ";
    cellInt2.affiche();
    cout << endl;

    // Déclarer et construire une variable CelInt3 de type Cellule entière (Cellule<int>) contenant la valeur 1
    // et qui est suivie de CelInt1
    Cellule<int> cellInt3(1);
    cellInt3.setSuivante(&cellInt1);

    // Afficher la liste dont la tête de liste est CelInt3 avec la procédure afficheCellules()
    cout << "A partir de CelInt3, ";
    Cellule<int> *tmp2 = &cellInt3;
    while(tmp2 != nullptr)
    {
       tmp2->affiche();
       cout << " ";
       tmp2 = tmp2->getRefSuivante();
    }


    // TROISIEME PARTIE
    cout << endl << endl << "MANIPULATION DE POINTEUR SUR DES CELLULES CONTENANT DES CHAINES" << endl;
    // Déclarer et construire une variable ptrCelString1 de type pointeur sur une Cellule entière (Cellule<string>*) contenant la valeur "deux"
    Cellule<string> *ptrCelStr1 = new Cellule<string>("deux");

    cout << "L'information portée par la cellule CelString1 est : ";
    // Afficher l'information portée par la cellule
    ptrCelStr1->affiche();

    cout << endl;

    // Déclarer et construire une variable ptrCelString2 de type pointeur sur une Cellule entière (Cellule<string>*) contenant la valeur "trois"
    Cellule<string> *ptrCelStr2 = new Cellule<string>("trois");

    // Faire en sorte que ptrCelString2 soit la cellule qui suit la cellule ptrCelString1
    ptrCelStr1->setSuivante(ptrCelStr2);

    // Afficher la liste dont la tête de liste est CelString2 avec la procédure afficheCellules()
    cout << "A partir de CelString2, ";
    ptrCelStr2->affiche();
        cout << endl;

    // Déclarer et construire une variable ptrCelString3 de type pointeur sur une Cellule entière (Cellule<string>*) contenant la valeur "un"
    // et qui est suivie de CelString1
    Cellule<string> *ptrCelStr3 = new Cellule<string>("un");
    ptrCelStr3->setSuivante(ptrCelStr1);

    // Afficher la liste dont la tête de liste est CelString3 avec la procédure afficheCellules()
    cout << "A partir de CelString3, ";
    Cellule<string>* tmp3 = ptrCelStr3;
    while(tmp3 != nullptr)
    {
       tmp3->affiche();
       cout << " ";
       tmp3 = tmp3->getRefSuivante();
    }



    // QUATRIEME PARTIE
    cout << endl << endl << "MANIPULATION DE CELLULES CONTENANT DES CHAINES" << endl;
    // Déclarer et construire une variable CelString1 de type Cellule entière (Cellule<string>) contenant la valeur "deux"
    Cellule<string> celStr1("deux");

    cout << "L'information portée par la cellule CelString1 est : ";
    // Afficher l'information portée par la cellule
    celStr1.affiche();

    cout << endl;

    // Déclarer et construire une variable ptrCelString2 de type Cellule entière (Cellule<string>) contenant la valeur "trois"
     Cellule<string> celStr2("trois");


    // Faire en sorte que CelString2 soit la cellule qui suit la cellule CelString1
     celStr1.setSuivante(&celStr2);

    // Afficher la liste dont la tête de liste est CelString2 avec la procédure afficheCellules()
    cout << "A partir de CelString2, ";
       celStr2.affiche();

    cout << endl;

    // Déclarer et construire une variable ptrCelString3 de type Cellule entière (Cellule<string>) contenant la valeur "un"
    // et qui est suivie de CelString1
     Cellule<string> celStr3("un");
     celStr3.setSuivante(&celStr1);

    // Afficher la liste dont la tête de liste est CelString3 avec la procédure afficheCellules()
    cout << "A partir de CelString3, ";
    Cellule<string>* tmp4 = &celStr3;
    while(tmp4 != nullptr)
    {
       tmp4->affiche();
       cout << " ";
       tmp4 = tmp4->getRefSuivante();
    }

    return 0;
}

// TRACE A OBTENIR
/*
 MANIPULATION DE POINTEUR SUR DES CELLULES CONTENANT DES ENTIERS
L'information portée par la cellule CelInt1 est : 2
A partir de CelInt2, la liste de cellules contient -> 3 
A partir de CelInt3, la liste de cellules contient -> 1 2 3 

MANIPULATION DE CELLULES CONTENANT DES ENTIERS
L'information portée par la cellule CelInt1 est : 2
A partir de CelInt2, la liste de cellules contient -> 3 
A partir de CelInt3, la liste de cellules contient -> 1 2 3 

MANIPULATION DE POINTEUR SUR DES CELLULES CONTENANT DES CHAINES
L'information portée par la cellule CelString1 est : deux
A partir de CelString2, la liste de cellules contient -> trois 
A partir de CelString3, la liste de cellules contient -> un deux trois 

MANIPULATION DE CELLULES CONTENANT DES CHAINES
L'information portée par la cellule CelString1 est : deux
A partir de CelString2, la liste de cellules contient -> trois 
A partir de CelString3, la liste de cellules contient -> un deux trois 
 */

