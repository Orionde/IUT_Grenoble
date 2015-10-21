#ifndef ARBREABSTRAIT_H
#define ARBREABSTRAIT_H
// Contient toutes les déclarations de classes nécessaires
//  pour représenter l'arbre abstrait

#include <stdlib.h>
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

#include "Symbole.h"
#include "Exceptions.h"

////////////////////////////////////////////////////////////////////////////////

class Noeud {
    // Classe abstraite dont dériveront toutes les classes servant à représenter l'arbre abstrait
    // Remarque : la classe ne contient aucun constructeur
public:
    virtual int executer() = 0; // Méthode pure (non implémentée) qui rend la classe abstraite

    virtual void ajoute(Noeud* instruction) {
        throw OperationInterditeException();
    }
<<<<<<< HEAD
    virtual void traduitEnCPP(ostream & cout, unsigned int indentation)const = 0;
=======
    virtual void traduitEnCPP(ostream & cout, unsigned int indentation){}   
>>>>>>> e5dbfe7edc638e2043353c4510eab1223be1be6c
    virtual ~Noeud() {
    } // Présence d'un destructeur virtuel conseillée dans les classes abstraites
};

////////////////////////////////////////////////////////////////////////////////

class NoeudSeqInst : public Noeud {
    // Classe pour représenter un noeud "sequence d'instruction"
    //  qui a autant de fils que d'instructions dans la séquence
public:
    NoeudSeqInst(); // Construit une séquence d'instruction vide

    ~NoeudSeqInst() {
    } // A cause du destructeur virtuel de la classe Noeud
    int executer(); // Exécute chaque instruction de la séquence
    void ajoute(Noeud* instruction); // Ajoute une instruction à la séquence
    void traduitEnCPP(ostream & cout, unsigned int indentation) const;
<<<<<<< HEAD
  
=======

>>>>>>> e5dbfe7edc638e2043353c4510eab1223be1be6c

private:
    vector<Noeud *> m_instructions; // pour stocker les instructions de la séquence
};

////////////////////////////////////////////////////////////////////////////////

class NoeudAffectation : public Noeud {
    // Classe pour représenter un noeud "affectation"
    //  composé de 2 fils : la variable et l'expression qu'on lui affecte
public:
    NoeudAffectation(Noeud* variable, Noeud* expression); // construit une affectation

    ~NoeudAffectation() {
    } // A cause du destructeur virtuel de la classe Noeud
    int executer(); // Exécute (évalue) l'expression et affecte sa valeur à la variable
    void traduitEnCPP(ostream & cout, unsigned int indentation) const;


private:
    Noeud* m_variable;
    Noeud* m_expression;
};

////////////////////////////////////////////////////////////////////////////////

class NoeudOperateurBinaire : public Noeud {
    // Classe pour représenter un noeud "opération binaire" composé d'un opérateur
    //  et de 2 fils : l'opérande gauche et l'opérande droit
public:
    NoeudOperateurBinaire(Symbole operateur, Noeud* operandeGauche, Noeud* operandeDroit);
    // Construit une opération binaire : operandeGauche operateur OperandeDroit

    ~NoeudOperateurBinaire() {
    } // A cause du destructeur virtuel de la classe Noeud
    int executer(); // Exécute (évalue) l'opération binaire)
    void traduitEnCPP(ostream & cout, unsigned int indentation)const;

private:
    Symbole m_operateur;
    Noeud* m_operandeGauche;
    Noeud* m_operandeDroit;
};

////////////////////////////////////////////////////////////////////////////////

class NoeudInstSi : public Noeud {
    // Classe pour représenter un noeud "instruction si"
    //  et ses 2 fils : la condition du si et la séquence d'instruction associée
public:
    NoeudInstSi(Noeud* condition, Noeud* sequence);
    // Construit une "instruction si" avec sa condition et sa séquence d'instruction

    ~NoeudInstSi() {
    } // A cause du destructeur virtuel de la classe Noeud
    int executer(); // Exécute l'instruction si : si condition vraie on exécute la séquence
    void traduitEnCPP(ostream & cout, unsigned int indentation) const;


private:
    Noeud* m_condition;
    Noeud* m_sequence;

};


////////////////////////////////////////////////////////////////////////////////

class NoeudInstTantQue : public Noeud {
public:
    NoeudInstTantQue(Noeud* condition, Noeud* sequence);

    ~NoeudInstTantQue() {
    }
    int executer();
    void traduitEnCPP(ostream & cout, unsigned int indentation) const;

private:
    Noeud* m_condition;
    Noeud* m_sequence;
};

////////////////////////////////////////////////////////////////////////////////

class NoeudInstRepeter : public Noeud {
public:
    NoeudInstRepeter(Noeud* condition, Noeud* sequence);

    ~NoeudInstRepeter() {
    }
    int executer();
    void traduitEnCPP(ostream & cout, unsigned int indentation) const;

private:
    Noeud* m_condition;
    Noeud* m_sequence;
};

////////////////////////////////////////////////////////////////////////////////

class NoeudInstPour : public Noeud {
public:
    NoeudInstPour(Noeud* condition, Noeud* seq, Noeud* aff1 = nullptr, Noeud* aff2 = nullptr);

    ~NoeudInstPour() {
    }
    int executer();
    void traduitEnCPP(ostream & cout, unsigned int indentation) const;

private:
    Noeud* m_condition;
    Noeud* m_sequence;
    Noeud* m_affectation;
    Noeud* m_affectation1;

};


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

class NoeudInstEcrire : public NoeudSeqInst {
public:
    NoeudInstEcrire();

    ~NoeudInstEcrire() {
    }
    int executer();
    void ajoute(Noeud* instruction);
    void traduitEnCPP(ostream & cout, unsigned int indentation) const;
private:
    vector<Noeud *> m_instructions;

};

////////////////////////////////////////////////////////////////////////////////

class NoeudInstLire : public Noeud {
public:
<<<<<<< HEAD
    NoeudInstLire();
=======
    NoeudInstLire(Noeud* condition);
>>>>>>> e5dbfe7edc638e2043353c4510eab1223be1be6c

    ~NoeudInstLire() {
    }
    int executer();
    void traduitEnCPP(ostream & cout, unsigned int indentation)const ;

private:
    vector<Noeud*> m_instructions;
};
#endif
