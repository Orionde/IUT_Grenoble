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

}

#endif