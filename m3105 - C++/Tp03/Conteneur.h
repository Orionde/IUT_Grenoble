#ifndef CONTENEUR_H
#define CONTENEUR_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

template <class T> class Singleton
{
    public :
        static T& Instance()
        {
            static T object;
            return object;
        }
};

class Conteneur : public Singleton<OnlyOne>{
    
    friend class Singleton<OnlyOne>;
        public:
		Conteneur();
		void ajouter(const T & element);
		void afficher(ostream & cout);
		const T &  choisirElement(ostream & cout, istream &cin);

	private:
		vector<const T*> m_contenu;
};

#include "Conteneur.cpp"
#endif
