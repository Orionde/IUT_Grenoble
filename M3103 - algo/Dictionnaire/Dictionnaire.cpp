/* 
 * File:   xmlwiktionary.cpp
 * Author: hb
 * 
 * Created on 22 mai 2014, 14:57
 */

#include "Dictionnaire.h"
#include <iostream>     // pour cout
#include <iomanip>      // pour setw()
#include <limits>       // pour numeric_limits<unsigned int>::max()

using namespace std;

/**
 * Constucteur de dictionnaire
 * 
 * @param filename  chemin d'accès au fichier XML qui contient le dictionnaire
 */
Dictionnaire::Dictionnaire(const char* filename) {
    // Chargement du fichier XML en mémoire
    imageDictionnaire.LoadFile(filename);
    // Initialisation de l'attribut dictionnary avec le premier fils (element <wiktionary>)
    leDictionnaire = imageDictionnaire.FirstChildElement();
}

/*
 * out : nombre d'entrées dans le dictionnaire
 */
int Dictionnaire::getNbEntries() const {
    // initialisation du nombre d'entrées
    int nb = 0;
    XMLElement * current = leDictionnaire->FirstChildElement();
    
    while(current != nullptr)
    {
        current = current->NextSiblingElement();
        nb ++;                
    }

    return nb;
}

/*
 * in : entry une entrée du dictionnaire
 * out : nombres de lexmèmes (ou unité lexicale) -> unité de sens et de son
 */
int Dictionnaire::getNbLexemesEntry(XMLElement* entry) const {
    int nbLexems = 0; //on doit avoir de toute manière au moins un lexème par entrée
        
    /*
     *  A COMPLETER
     */

    return nbLexems;
}

/*
 * in : entry une entrée du dictionnaire
 * out : pointeur sur l'étymologie de entry si elle existe (NULL sinon)
 * l'étymologie est unique, il suffit donc d'accèder au fils de entry de type etym
 */
XMLElement* Dictionnaire::getEtymEntry(XMLElement* entry) {
        
    /*
     *  A COMPLETER
     */

    return nullptr;
}



/*
 * in : defs un élement contenant les définitions d'un lexeme, peut être NULL !
 *      s'il n'est pas nul <tolevel-def>+ (dans la partique +)
 * out : nombres de définitions
 */
int Dictionnaire::getNbTopLevelDefS(XMLElement* defs) const {
    int nbDefs = 0; //on n'a pas forcément de définition
        
    /*
     *  A COMPLETER
     */

    return nbDefs;
}


int Dictionnaire::getNbEntriesRecWorker(const XMLElement* entreeCourante) const {
   cout << "a" << endl;     
    if(entreeCourante != nullptr)
        return (getNbEntriesRecWorker(entreeCourante->NextSiblingElement()) + 1);
    else
        return 0;
}


int Dictionnaire::getNbEntriesRec() const {
    return getNbEntriesRecWorker(leDictionnaire->FirstChildElement());
}


//void Dictionnaire::Print() const {
//    dictionaryfile.Print();
//}


void Dictionnaire::afficheEntriesForm() {
    int rank = 0;
    XMLElement *current = leDictionnaire->FirstChildElement();
    while(current)
    {
        cout << "rang : " << rank << " : ";
        cout << current->Attribute("form") << endl;
        
        current = current->NextSiblingElement();
        rank++;
    }
}


/*
 * affichage des entrées du dictionnaire dans un intervalle
 */
void Dictionnaire::afficheRangedEntriesForm(unsigned int inf, unsigned int sup) {
    XMLElement *current = leDictionnaire->FirstChildElement();
    int i;
    while(i < inf){
        current = current->NextSiblingElement();
        i++;
    }
    while((i <= sup) || (sup == 0 && current != nullptr))
    {
        cout << "rang : " << i << " : ";
        cout << current->Attribute("form") << endl;
        
        current = current->NextSiblingElement();
        i++;
    }
}

/*
 * pointeur sur l'élément <entry> correspondant à la forme form
 */
XMLElement* Dictionnaire::getEntryForForm(string entryForm) {
        
    /*
     *  A COMPLETER
     */

    return nullptr;
}

bool Dictionnaire::isForm(string form)
{
    XMLElement *current = leDictionnaire->FirstChildElement();
    while(current && current->Attribute("form") != form)
    {
         current = current->NextSiblingElement();
    }
    return current != nullptr;
}

Dictionnaire::~Dictionnaire() {
}

