//  HB librement inspiré de
//  Data Abstraction & Problem Solving with C++: Walls and Mirrors
//  Frank M. Carrano and Tim Henry.
//  2013 – Pearson Education

/** Interface pour le type abstrait de donnée Liste
    C'est une classe abstraite dont vont hériter chacune des classes qui
    instancient finalement la liste chaînée
 
    On voit bien cela puisque cette classe ne décrit pas les données
    Elle ne décrit que les méthodes
    @file ListeInterface.h */

#ifndef _PILE_INTERFACE
#define _PILE_INTERFACE

template<class TypeInfo>
class PileInterface {
public:
    /** cette (this) pile est-elle vide ,
     @return True si la liste est vide ; False sinon. */
    virtual bool estVide() const = 0;

    /** insertion d'un élément contentant nouvelleInfo en sommet de pile.
     @pre  Aucune.
     @post élément contenant nouvelleInfo est ajouté en sommet de pile.
     @param nouvelleInfo  information à ranger en sommet de pile. */
    virtual void empile(const TypeInfo& nouvelleInfo) = 0;

    /** suppression de l'élément en sommet de pile.
     @pre  Aucune.
     @post la pile à pour sommet l'élément si se trouvait sous l'ancien sommet de pile. */
    virtual bool depile() = 0;
    
    /** consultation de l'élément en sommet de pile.
     @pre  Aucune.
     @post la pile demeure inchangée. 
     @retrun élément situé en sommet de pile*/
    virtual TypeInfo consulteSommet() const = 0;

}; // end ListInterface
#endif