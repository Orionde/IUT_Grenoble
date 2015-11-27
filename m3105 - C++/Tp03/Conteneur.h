#ifndef CONTENEUR_H
#define CONTENEUR_H

#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Conteneur{
    
    
        public:
		static Conteneur<T>* getInstance();
		void ajouter(const T & element);
		void afficher(ostream & cout);
		const T &  choisirElement();

	private:
		vector<const T*> m_contenu;
                static Conteneur <T>* m_instance;
protected:
    Conteneur();
};

#include "Conteneur.cpp"
#endif
