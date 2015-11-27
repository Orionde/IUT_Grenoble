/************************
 *    ETUDIANT
 ************************/


/** Implementation de la classe PileCellules.
    @file PileCellules.cpp */

#ifdef PILECELLULES_H

#include <cstdlib>
#include <iostream>
#include <new>

#include "PileCellules.h"   // gestion de l'exception bad_alloc

using namespace std;

/****************************************************************************
 *      CONSTRUCTEURS                                                       
 ****************************************************************************/

template<class TypeInfo>
PileCellules<TypeInfo>::PileCellules() : ptrSommet(nullptr) {

} // end contructeur par défaut

template<class TypeInfo>
PileCellules<TypeInfo>::PileCellules(const PileCellules<TypeInfo>& unePile) {
    // la pile originale va être parcourrue comme une liste !

    // Pointeur sur la première cellule de la liste
    Cellule<TypeInfo>* ptrPileOriginale = unePile.ptrSommet;

    // unePile est vide
    if (ptrPileOriginale == nullptr) {
        ptrSommet = nullptr; // cette pile (la nouvelle) est vide
    } else {
        // Copie du sommet
        ptrSommet = new Cellule<TypeInfo>();
        ptrSommet->setInfo(ptrPileOriginale->getInfo());

        // avancer dans la pile originale (comme dans une liste)
        ptrPileOriginale = ptrPileOriginale->getSuivante();

        // pointeur supplémentaire pour parcourir la pile en cours de création (cette pile)
        Cellule<TypeInfo>* ptrPileNouvelle = ptrSommet;

        // copier les cellules qui restent

        while (ptrPileOriginale != nullptr) {
            // obtenir l'information portée par la cellule
            TypeInfo infoSuivant = ptrPileOriginale->getInfo();

            // créer une cellule à mettre dans la nouvelle pile
            Cellule<TypeInfo>* nouvelleCellule = new Cellule<TypeInfo>(infoSuivant);

            // lier la nouvelle cellule à la nouvelle pile
            ptrPileNouvelle->setSuivante(nouvelleCellule);

            // avancer sur les deux liste       
            ptrPileNouvelle = ptrPileNouvelle->getSuivante();
            ptrPileOriginale = ptrPileOriginale->getSuivante();
        } // end while

        // la dernière cellule de la pile n'a pas de successeur
        ptrPileNouvelle->setSuivante(nullptr);
    } // end if

} // end contructeur par copie

/****************************************************************************
 *      DESTRUCTEUR                                                         
 ****************************************************************************/

template<class TypeInfo>
PileCellules<TypeInfo>::~PileCellules() {
    vide();
} // end ~PileCellules

/****************************************************************************
 *      METHODES UTILITAIRES PUBLIQUES                                      
 ****************************************************************************/

template<class TypeInfo>
bool PileCellules<TypeInfo>::estVide() const {
    return (ptrSommet == nullptr);
}

template<class TypeInfo>
void PileCellules<TypeInfo>::empile(const TypeInfo& nouvelleInfo) throw (bad_alloc) {
    
    try {
            
        } catch (bad_alloc& ba) {
        cout << "Plus de place en mémoire pour empiler ! " << ba.what() << endl;
    } // end try/catch
}

template<class TypeInfo>
bool PileCellules<TypeInfo>::depile() throw (PrecondVioleeExcep) {
    /*
     * A COMPLETER
     */
    return true;

    /*
    if (!estVide()) {
        ...
    } else { // si la pile est déjà vide, lever une exception
        throw (PrecondVioleeExcep("méthode depile() appelée sur une pile vide !"));
    }
     */
}

template<class TypeInfo>
TypeInfo PileCellules<TypeInfo>::consulteSommet() const throw (PrecondVioleeExcep) {
    /*
     * Instruction suivante à enlever !!
     */
    return "à des fins de trace";
    /*
    if (!estVide()) {
     
         // A COMPLETER
        
        return 0;
    } else { // si la pile est déjà vide, lever une exception
        throw (PrecondVioleeExcep("méthode consulteSommet() appelée sur une pile vide !"));
    }
    */
}

/*****************************************************************************
 *    METHODES UTILITAIRES PRIEES                                        
 ****************************************************************************/

template<class TypeInfo>
void PileCellules<TypeInfo>::vide() {
    while (!estVide())
        depile();
}


//  Fin implementation de la classe PileCellules.

#endif