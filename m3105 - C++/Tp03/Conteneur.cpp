#include "NombreContraint.h"

#ifdef CONTENEUR_H

template <class T>
Conteneur<T>::Conteneur() : m_contenu() {
}

template <class T>
void Conteneur<T>::ajouter(const T & element) {
	m_contenu.push_back(&element);
}

template <class T>
void Conteneur<T>::afficher(ostream & cout) {
	for (auto i : m_contenu)
		i->afficher(cout);
}

template <class T>
const T & Conteneur<T>::choisirElement(ostream & cout, istream & cin) {
	NombreContraint<int> n(1, 1, m_contenu.size());
	bool ok;
	do{
		try{
			afficher(cout);
			cout << endl << "Choix : ";
			n.saisir(cin);
			ok= true;
		}
		catch(const char *e){
			cout << "Choix entre 1 et " << m_contenu.size() << endl;
			ok = false;
		}
	}while(!ok);
	return (*m_contenu[n.getVal() -1]);

}
#endif
