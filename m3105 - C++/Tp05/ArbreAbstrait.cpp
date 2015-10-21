#include <stdlib.h>
#include <typeinfo>
#include "ArbreAbstrait.h"
#include "Symbole.h"
#include "SymboleValue.h"
#include "Exceptions.h"

////////////////////////////////////////////////////////////////////////////////
// NoeudSeqInst
////////////////////////////////////////////////////////////////////////////////

NoeudSeqInst::NoeudSeqInst() : m_instructions() {
}

int NoeudSeqInst::executer() {
    for (unsigned int i = 0; i < m_instructions.size(); i++)
        m_instructions[i]->executer(); // on exécute chaque instruction de la séquence
    return 0; // La vlaeur renvoyée ne représente rien !
}

void NoeudSeqInst::ajoute(Noeud* instruction) {
    if (instruction != nullptr) m_instructions.push_back(instruction);
}

void NoeudSeqInst::traduitEnCPP(ostream & cout, unsigned int indentation) const {
    for (unsigned int i = 0; i < m_instructions.size(); i++)
        m_instructions[i]->traduitEnCPP(cout, indentation);
}


////////////////////////////////////////////////////////////////////////////////
// NoeudAffectation
////////////////////////////////////////////////////////////////////////////////

NoeudAffectation::NoeudAffectation(Noeud* variable, Noeud* expression)
: m_variable(variable), m_expression(expression) {
}

int NoeudAffectation::executer() {
    int valeur = m_expression->executer(); // On exécute (évalue) l'expression
    ((SymboleValue*) m_variable)->setValeur(valeur); // On affecte la variable
    return 0; // La valeur renvoyée ne représente rien !
}

void NoeudAffectation::traduitEnCPP(ostream & cout, unsigned int indentation) const {
    cout << setw(4 * indentation) << "";
    cout << ((SymboleValue*) m_variable) << "=";
    if (typeid (*m_expression) == typeid (SymboleValue)) {
        cout << m_expression->executer();
        m_expression->traduitEnCPP(cout, 0);
    } else
        m_expression->traduitEnCPP(cout, 0);
    cout << endl;
}

////////////////////////////////////////////////////////////////////////////////
// NoeudOperateurBinaire
////////////////////////////////////////////////////////////////////////////////

NoeudOperateurBinaire::NoeudOperateurBinaire(Symbole operateur, Noeud* operandeGauche, Noeud* operandeDroit)
: m_operateur(operateur), m_operandeGauche(operandeGauche), m_operandeDroit(operandeDroit) {
}

int NoeudOperateurBinaire::executer() {
    int og, od, valeur;
    if (m_operandeGauche != nullptr) og = m_operandeGauche->executer(); // On évalue l'opérande gauche
    if (m_operandeDroit != nullptr) od = m_operandeDroit->executer(); // On évalue l'opérande droit
    // Et on combine les deux opérandes en fonctions de l'opérateur
    if (this->m_operateur == "+") valeur = (og + od);
    else if (this->m_operateur == "-") valeur = (og - od);
    else if (this->m_operateur == "*") valeur = (og * od);
    else if (this->m_operateur == "==") valeur = (og == od);
    else if (this->m_operateur == "!=") valeur = (og != od);
    else if (this->m_operateur == "<") valeur = (og < od);
    else if (this->m_operateur == ">") valeur = (og > od);
    else if (this->m_operateur == "<=") valeur = (og <= od);
    else if (this->m_operateur == ">=") valeur = (og >= od);
    else if (this->m_operateur == "et") valeur = (og && od);
    else if (this->m_operateur == "ou") valeur = (og || od);
    else if (this->m_operateur == "non") valeur = (!og);
    else if (this->m_operateur == "/") {
        if (od == 0) throw DivParZeroException();
        valeur = og / od;
    }
    return valeur; // On retourne la valeur calculée
}

void NoeudOperateurBinaire::traduitEnCPP(ostream & cout, unsigned int indentation) const {
    if (m_operandeGauche != nullptr)
        cout << ((SymboleValue*) m_operandeGauche)->getChaine();
    cout << " ";

    if (this->m_operateur == "et")
        cout << "&&";
    else if (this->m_operateur == "ou")
        cout << "||";
    else if (this->m_operateur == "non")
        cout << "!";
    else {
        cout << ((SymboleValue*) m_operateur)->getChaine());
    }
    cout << " ";

    if (m_operandeDroit != nullptr)
            cout << ((SymboleValue*) m_operandeDroit)->getChaine();

    }

////////////////////////////////////////////////////////////////////////////////
// NoeudInstSi
////////////////////////////////////////////////////////////////////////////////

NoeudInstSi::NoeudInstSi(Noeud* condition, Noeud* sequence)
        : m_condition(condition), m_sequence(sequence) {
}

int NoeudInstSi::executer() {
    if (m_condition->executer()) m_sequence->executer();

        return 0; // La valeur renvoyée ne représente rien !
    }

void NoeudInstSi::traduitEnCPP(ostream & cout, unsigned int indentation) const {

    cout << setw(4 * indentation) << "" << "if (";
            m_condition->traduitEnCPP(cout, 0);
            cout << ") {" << endl;
            m_sequence->traduitEnCPP(cout, indentation + 1);
            cout << setw(4 * indentation) << "" << "}" << endl;
}


////////////////////////////////////////////////////////////////////////////////
// NoeudInstTantQue
////////////////////////////////////////////////////////////////////////////////

NoeudInstTantQue::NoeudInstTantQue(Noeud* condition, Noeud * sequence)
        : m_condition(condition), m_sequence(sequence) {
}

int NoeudInstTantQue::executer() {
    while (m_condition->executer())m_sequence->executer();

        return 0; // La valeur renvoyée ne représente rien !
    }

void NoeudInstTantQue::traduitEnCPP(ostream & cout, unsigned int indentation) const {
    //<instTantQue>  ::= tantque (  <expression>  )  <seqInst>  fintantque

    cout << setw(4 * indentation) << "" << "while (";
            m_condition->traduitEnCPP(cout, 0);
            cout << ") {" << endl;
            m_sequence->traduitEnCPP(cout, indentation + 1);
            cout << setw(4 * indentation) << "" << "}" << endl;
}

////////////////////////////////////////////////////////////////////////////////
// NoeudInstRepeter
////////////////////////////////////////////////////////////////////////////////

NoeudInstRepeter::NoeudInstRepeter(Noeud* condition, Noeud * sequence)
        : m_condition(condition), m_sequence(sequence) {
}

int NoeudInstRepeter::executer() {
    while (!m_condition->executer()) m_sequence->executer();

        return 0; // La valeur renvoyée ne représente rien !
    }

void NoeudInstRepeter::traduitEnCPP(ostream & cout, unsigned int indentation) const {
    //<instRepeter> ::= repeter <seqInst> jusquexpressiona( <expression>)

    cout << setw(4 * indentation) << "" << "do { ";
            m_sequence->traduitEnCPP(cout, indentation + 1);
            cout << "}" << endl;
            cout << "" << "while (";
            m_condition->traduitEnCPP(cout, 0);
            cout << ");";
}



////////////////////////////////////////////////////////////////////////////////
// NoeudInstPour
////////////////////////////////////////////////////////////////////////////////

NoeudInstPour::NoeudInstPour(Noeud* condition, Noeud* seq, Noeud* aff1, Noeud * aff2)
        : m_condition(condition), m_sequence(seq), m_affectation(aff1), m_affectation1(aff2) {
}

int NoeudInstPour::executer() {
    cout << m_affectation << endl;
            cout << m_affectation1 << endl;
            cout << m_condition << endl;
            cout << m_sequence << endl;
    if (m_affectation != nullptr && m_affectation1 != nullptr) {
        m_affectation->executer();
        while (m_condition->executer()) {

            m_affectation1->executer();
                    m_sequence->executer();
        }
    }
    return 0; // La valeur renvoyée ne représente rien !
}

void NoeudInstPour::traduitEnCPP(ostream & cout, unsigned int indentation) const {
    //<instRepeter> ::= repeter <seqInst> jusquexpressiona( <expression>)
    cout << setw(4 * indentation) << "" << "for ( ";
    if (m_affectation != nullptr)
            m_affectation->traduitEnCPP(cout, 0);

            m_condition->traduitEnCPP(cout, 0);
            cout << " ;";

        if (m_affectation1 != nullptr) {

            m_affectation->traduitEnCPP(cout, 0);

        }
    cout << ") {" << endl;
            m_sequence->traduitEnCPP(cout, indentation + 1);
            cout << setw(4 * indentation) << "" << "}";
            cout << "" << "while (";
            m_condition->traduitEnCPP(cout, 0);
            cout << ");";
}

////////////////////////////////////////////////////////////////////////////////
// NoeudInstEcrire
////////////////////////////////////////////////////////////////////////////////

NoeudInstEcrire::NoeudInstEcrire() {
}

int NoeudInstEcrire::executer() {

    for (unsigned int i = 0; i < m_instructions.size(); i++) {
        if ((typeid (*m_instructions[i]) == typeid (SymboleValue) && *((SymboleValue*) m_instructions[i]) == "<CHAINE>")) {
            string s = ((SymboleValue*) m_instructions[i])-> getChaine();
                    cout << s.substr(1, s.size() - 2);

        } else {

            cout << m_instructions[i]->executer(); // On exécute chaque instruction de la séquence -> récupérer valeur
        }

    }
    return 0; // La valeur renvoyée ne représente rien !
}

void NoeudInstEcrire::ajoute(Noeud * instruction) {

    if (instruction != nullptr) m_instructions.push_back(instruction);
    }

void NoeudInstEcrire::traduitEnCPP(ostream & cout, unsigned int indentation) const {
    //On considère qu'on met tout en chaines de caractères
    cout << setw(4 * indentation) << "" << "cout << \"";
    for (unsigned int i = 0; i < m_instructions.size(); i++) {
        cout << (SymboleValue*) n)->getChaine();
        if (i < m_instructions.size())
            cout << "\", \"";
        i++;
    }

    cout << "\";";
}


////////////////////////////////////////////////////////////////////////////////
// NoeudInstEcrire
////////////////////////////////////////////////////////////////////////////////

NoeudInstLire::NoeudInstLire(Noeud * condition) : m_instructions() {
}

int NoeudInstLire::executer() {
    int ajout;

    for (Noeud *n : m_instructions) {
        cin >> ajout;
        ((SymboleValue*) n)->setValeur();
    }
    m_condition->executer();
}

void NoeudInstLire::traduitEnCPP(ostream & cout, unsigned int indentation) const {
    //On considère que tout sera transformé en chaines pour l'affichage
    cout << setw(4 * indentation) << "" << "cin >> \"";
    for (unsigned int i = 0; i < m_instructions.size(); i++) {
        cout << (SymboleValue*) m_instructions[i]->getChaine();
        if (i < m_instructions.size())
            cout << "\", \"";
        i++;
    }

    cout << "\";";
}
