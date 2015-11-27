#ifdef _LISTE_CHAINEE_TRIEE

#include <cassert>
#include <cstdlib>

#include "Cellule.h"
#include "ListeTrieeChainee.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////////
//Constructeurs

template<class TypeInfo>
ListeTrieeChainee<TypeInfo>::ListeTrieeChainee() : ptrTete(nullptr), nbCellules(0) {
}

template<class TypeInfo>
ListeTrieeChainee<TypeInfo>::ListeTrieeChainee(const ListeTrieeChainee<TypeInfo>& uneListe) {
    ptrTete = copieListe(uneListe.ptrTete);
    nbCellules = uneListe.nbCellules;
}

template<class TypeInfo>
Cellule<TypeInfo>* ListeTrieeChainee<TypeInfo>::copieListe(const Cellule<TypeInfo>* laListeOriginale) {
    // création d'une liste vide pour y ranger la copie
    Cellule<TypeInfo>* laListeCopiee = nullptr;
    if (laListeOriginale != nullptr) { // La liste originale n'est pas vide
        // construction de la première Cellule de la copie
        // avec l'information portée par la première Cellule de la laListeOriginale
        laListeCopiee = new Cellule<TypeInfo>(laListeOriginale->getInfo());
        // avec comme suivante le résutlat de la copie de la suite de la laListeOriginale
        laListeCopiee->setSuivante(copieListe(laListeOriginale->getSuivante()));
    } // end if
    // rendre la copie
    return laListeCopiee;
} // end copieListe

template<class TypeInfo>
ListeTrieeChainee<TypeInfo>::~ListeTrieeChainee() {
    vide();
}

////////////////////////////////////////////////////////////////////////////////
//Méthodes d'insertion

template<class TypeInfo>
void ListeTrieeChainee<TypeInfo>::insere(const TypeInfo& nouvelleInfo) {
    // NOTER que l'insertion est toujours possible !!
    // -> ce ne sera plus le cas sur un ensemble représenté par une liste chaînée triée

    // pointeur sur la nouvelle cellule à insérer (création, construction)
    Cellule<TypeInfo>* ptrNouvelleCellule = new Cellule<TypeInfo>(nouvelleInfo);
    // pointeur sur la cellule qui précède la cellule à insérer
    Cellule<TypeInfo>* ptrCellulePrecedente = getCellulePrecedente(nouvelleInfo);

    // la liste est vide ou on doit insérer en tête
    if (estVide() || (ptrCellulePrecedente == nullptr)) { // insertion en tête
        ptrNouvelleCellule->setSuivante(ptrTete);
        ptrTete = ptrNouvelleCellule;
    } else { // insertion comme suivante de la cellule précédentes
        Cellule<TypeInfo>* ptrCelluleSuivante = ptrCellulePrecedente->getSuivante();
        ptrNouvelleCellule->setSuivante(ptrCelluleSuivante);
        ptrCellulePrecedente->setSuivante(ptrNouvelleCellule);
    } // end if

    nbCellules++; // une cellule de plus dans cette liste
} // end insere

template<class TypeInfo>
void ListeTrieeChainee<TypeInfo>::insereRec(const TypeInfo& nouvelleInfo) {
    insereRecWorker(ptrTete, nouvelleInfo);
}

template<class TypeInfo>
void ListeTrieeChainee<TypeInfo>::insereRecWorker(Cellule<TypeInfo>*& ptrCetteListe, const TypeInfo& nouvelleInfo) {
    if (ptrCetteListe == nullptr)
        insere(nouvelleInfo);
    else {
        if (ptrCetteListe->getInfo() >= nouvelleInfo)
            insere(nouvelleInfo);
        else
            insereRecWorker(ptrCetteListe->getRefSuivante(), nouvelleInfo);
    }
}
////////////////////////////////////////////////////////////////////////////////
//Méthodes de suppression

template<class TypeInfo>
bool ListeTrieeChainee<TypeInfo>::supprimePremOccInfo(const TypeInfo& uneInfo) {
    // la valeur que l'on doit supprimer est-elle présente ?
    bool estValPresente = false;
    if (!estVide()) { // cette liste n'est pas vide
        Cellule<TypeInfo>* ptrCelluleASupprimer = ptrTete;

        // pointeur sur la cellule qui précède la cellule à supprimer
        Cellule<TypeInfo>* ptrCellulePrecedente = getCellulePrecedente(uneInfo);
        if (ptrCellulePrecedente != nullptr) { // la cellule précédente existe !
            // pointeur sur la cellule à supprimer
            ptrCelluleASupprimer = ptrCellulePrecedente->getSuivante();
        } // end if

        // mise à jour -> on a trouvé une cellule à supprimer qui contient uneInfo
        estValPresente = (ptrCelluleASupprimer != nullptr) && (uneInfo == ptrCelluleASupprimer->getInfo());

        if (estValPresente) { // on va supprimer une cellule qui est présente
            // pointeur sur la cellule qui suit la cellule à supprimer
            Cellule<TypeInfo>* ptrCelluleSuivante = ptrCelluleASupprimer->getSuivante();
            if (ptrCelluleASupprimer == ptrTete) { // suppression de la première cellule
                ptrTete = ptrCelluleSuivante;
            } else {
                // supprimer la cellule de la liste en mettant à jour la suivante de la cellule précédente
                // cette suivante est la cellule qui suit la cellule à supprimer
                ptrCellulePrecedente->setSuivante(ptrCelluleSuivante);
            } // end if

            // libérer la cellule à supprimer
            ptrCelluleASupprimer->setSuivante(nullptr);
            delete ptrCelluleASupprimer;
            ptrCelluleASupprimer = nullptr;

            nbCellules--; // une cellule de moins
        } // end if (uneInfo n'est pas présente)
    } // end if (cette liste est vide)

    return estValPresente;
} // end supprimeTrie

template<class TypeInfo>
bool ListeTrieeChainee<TypeInfo>::supprimePremOccInfoRec(const TypeInfo& uneInfo) {
    return supprimePremOccInfoRecWorker(ptrTete, uneInfo);
}

template<class TypeInfo>
bool ListeTrieeChainee<TypeInfo>::supprimeAtPosit(int laPosition) {
    // ICI on vérifie que la suppression est possible avant de la réaliser
    // Et on utilise la méthode qui retourne un pointeur sur la cellule qui précède la cellule
    // après après laquelle insérer

    // La suppression est-elle possible ?
    bool estValPresente = (laPosition >= 1) && (laPosition <= nbCellules);
    if (estValPresente) {
        Cellule<TypeInfo>* ptrTemp = nullptr;
        if (laPosition == 1) {
            // Supprimer la première Cellule
            ptrTemp = ptrTete; // save pointer to node
            ptrTete = ptrTete->getSuivante();
        } else {
            // Trouver la Cellule qui précède la Cellule à supprimer
            Cellule<TypeInfo>* ptrCellulePrecedente = getCelluleAtPosit(laPosition - 1);

            // Pointeur sur la Cellule à supprimer
            ptrTemp = ptrCellulePrecedente->getSuivante();

            // la suivante de la précédente devient la suivante de la cellule à supprimer
            ptrCellulePrecedente->setSuivante(ptrTemp->getSuivante());
        } // end if

        // libérer la Cellule à supprimer
        ptrTemp->setSuivante(nullptr);
        delete ptrTemp;
        ptrTemp = nullptr;

        nbCellules--; // une Cellule en moins dans cette ListeChaineeTriee
    } // end if

    return estValPresente;
} // end supprCelluleAtPosition

template<class TypeInfo>
bool ListeTrieeChainee<TypeInfo>::supprimeAtPositRec(int laPosition) {
    // si suppression possible appeller supprimeAtPositRecProcWorker() qui met à jour cette liste
    bool suppressionPossible = (laPosition >= 1) && (laPosition <= nbCellules);
    if (suppressionPossible)
        supprimeAtPositRecWorker(ptrTete, laPosition);
    return suppressionPossible;
} // end supprimeAtPositRec

template<class TypeInfo>
bool ListeTrieeChainee<TypeInfo>::supprimePremOccInfoRecWorker(Cellule<TypeInfo>*& ptrCetteListe, const TypeInfo & uneInfo) {
    /*
     * ALGORITHME
     */
    if (ptrCetteListe == nullptr || ptrCetteListe->getInfo() > uneInfo)
        return false;
    else if (ptrCetteListe->getInfo() == uneInfo) {
        Cellule<TypeInfo> *tmp = ptrCetteListe;
        ptrCetteListe = ptrCetteListe->getSuivante();
        delete tmp;
        nbCellules--;
        return true;
    } else
        return (supprimePremOccInfoRecWorker(ptrCetteListe->getRefSuivante(), uneInfo));
}

template<class TypeInfo>
void ListeTrieeChainee<TypeInfo>::vide() {
    while (!estVide())
        supprimeAtPosit(1);
} // end vider

template<class TypeInfo>
void ListeTrieeChainee<TypeInfo>::supprimeAtPositRecWorker(Cellule<TypeInfo>*& ptrCetteListe, const int laPosition) {
    if (laPosition == 1) {
        Cellule<TypeInfo> *tmp = ptrCetteListe;
        ptrCetteListe = ptrCetteListe->getSuivante();
        delete tmp;
        nbCellules--;
    } else
        supprimeAtPositRecWorker(ptrCetteListe->getRefSuivante(), laPosition - 1);
}

////////////////////////////////////////////////////////////////////////////////
//Méthodes d'accès

template<class TypeInfo>
int ListeTrieeChainee<TypeInfo>::getPosit(const TypeInfo& uneInfo) const {
    int position = 1; // initialisation
    // pointeur temporaire pour parcourir cette liste sans la détruire
    Cellule<TypeInfo>* ptrTemp = ptrTete;

    // tant que la liste n'est pas vide et que la valeur courante est strictement inférieure à la valeur à supprimer
    while ((ptrTemp != nullptr) && (uneInfo > ptrTemp->getInfo())) {
        // avancer sur cette liste et dans la position
        ptrTemp = ptrTemp->getSuivante();
        position++;
    } // end while

    // si on n'a pas trouvé (on a la position que la valeur devrait occuper)
    if ((ptrTemp == nullptr) || (uneInfo != ptrTemp->getInfo()))
        position = -position;

    return position;
} // end

template<class TypeInfo>
TypeInfo ListeTrieeChainee<TypeInfo>::getInfoAtPosit(int laPosition) const throw (PrecondVioleeExcep) {
    // vérifier que l'accèse à laPosition est possible
    bool estPresente = (laPosition >= 1) && (laPosition <= nbCellules);
    if (estPresente) {
        // accès à la Cellule à laPosition
        Cellule<TypeInfo>* ptrCellule = getCelluleAtPosit(laPosition);
        // retour de l'info
        return ptrCellule->getInfo();
    } else {
        // lever une exception
        string message = "getInfoAtPosit() appellée avec une liste vide où une position invalide !";
        throw (PrecondVioleeExcep(message));
    } // end if
} // end getValeurAtPosition

template<class TypeInfo>
TypeInfo ListeTrieeChainee<TypeInfo>::getInfoAtPositRec(int laPosition) const throw (PrecondVioleeExcep) {
    return getInfoAtPositRecWorker(ptrTete, laPosition);
} // end getInfoAtPositRec

template<class TypeInfo >
Cellule<TypeInfo>* ListeTrieeChainee<TypeInfo>::getCelluleAtPosit(int laPosition) const {
    // vérifier que laPosition est accessible
    //  -> sinon assert lèvera une exception
    assert((laPosition >= 1) && (laPosition <= nbCellules));

    // on est certain d'atteinde la position
    // pointeur temporaire pour parcourir la "liste" de Cellule sans la détruire
    Cellule<TypeInfo>* ptrTemp = ptrTete;
    // à partir de 1, avancer dans la "liste" de cellules" tant que
    // positionCourante < laPosition
    for (int positionCourante = 1; positionCourante < laPosition; positionCourante++) {
        ptrTemp = ptrTemp->getSuivante();
    }
    // on a trouvé, on rend
    return ptrTemp;
} // end getCelluleAtPosition

template<class TypeInfo>
TypeInfo ListeTrieeChainee<TypeInfo>::getInfoAtPositRecWorker(const Cellule<TypeInfo>* ptrCetteListe, const int laPosition) const throw (PrecondVioleeExcep) {
    return 0;
}

template<class TypeInfo >
Cellule<TypeInfo>* ListeTrieeChainee<TypeInfo>::getCellulePrecedente(const TypeInfo & uneInfo) const {
    // pointeur pour ce promener sur la "liste" de Cellule sans la détruire
    Cellule<TypeInfo>* ptrCellCour = ptrTete;
    // on veut la Cellule précédente de uneInfo
    Cellule<TypeInfo>* ptrCellulePrecedente = nullptr;

    // tant que la liste n'est pas vide et alors  que les valeurs rencontrées
    // sont strictement inférieures à uneInfo cherchée
    while ((ptrCellCour != nullptr) && (uneInfo > ptrCellCour->getInfo())) {
        // avancer la précédente
        ptrCellulePrecedente = ptrCellCour;
        // avancer la courante
        ptrCellCour = ptrCellCour->getSuivante();
    } // end while
    // (ptrTemp == nullptr) || (uneInfo <= ptrTemp->getInfo())
    // | ptrTemp == nullptr | uneInfo <= ptrTemp->getInfo() | Résultat 
    // |     Vrai           |       non examiné                |  ptrCellulePrecedente
    // |     Faux           |       Vrai                       |  ptrCellulePrecedente

    return ptrCellulePrecedente;
} // end getCellulePrecedente



////////////////////////////////////////////////////////////////////////////////
//Méthodes d'affichage

template<class TypeInfo>
void ListeTrieeChainee<TypeInfo>::afficheCroissantRec() const {
    afficheCroissantRecWorker(ptrTete);
}

template<class TypeInfo>
void ListeTrieeChainee<TypeInfo>::afficheCroissantIter() const {
    afficheCroissantIterWorker(ptrTete);
}

template<class TypeInfo>
void ListeTrieeChainee<TypeInfo>::afficheCroissantRecWorker(const Cellule<TypeInfo>* ptrCetteListe) const {
    if (ptrCetteListe != nullptr) {
        cout << ptrCetteListe->getInfo() << " ";
        afficheCroissantRecWorker(ptrCetteListe->getSuivante());
    }
}

template<class TypeInfo>
void ListeTrieeChainee<TypeInfo>::afficheCroissantIterWorker(Cellule<TypeInfo>* ptrCetteListe) const {
    while (ptrCetteListe != nullptr) {
        cout << ptrCetteListe->getInfo() << " ";
        ptrCetteListe = ptrCetteListe->getSuivante();
    }
}

template<class TypeInfo>
bool ListeTrieeChainee<TypeInfo>::estVide() const {
    return nbCellules == 0;
}

template<class TypeInfo>
int ListeTrieeChainee<TypeInfo>::getLongueur() const {
    return nbCellules;
}


}
}

#endif