#ifndef NOMBRECONTRAINT_H
#define	NOMBRECONTRAINT_H
#include <iostream>

using namespace std;

template <class TypeNumerique>

class NombreContraint {
public:
    NombreContraint<TypeNumerique>(TypeNumerique valeur = 0, TypeNumerique min = 0, TypeNumerique max = 100);
    TypeNumerique getMin();
    TypeNumerique getMax();
    TypeNumerique getVal();

    void setMin(TypeNumerique min);
    void setMax(TypeNumerique max);
    void setVal(TypeNumerique val);

    void saisir(istream & cin = std::cin);
    void afficher(ostream &cout = std::cout) const;

    operator NombreContraint();




private:
    TypeNumerique m_min;
    TypeNumerique m_max;
    TypeNumerique m_val;

};
template <class TypeNumerique> ostream & operator <<(ostream & cout, const NombreContraint<TypeNumerique> & n);
template <class TypeNumerique> istream& operator >>(istream& cin, NombreContraint<TypeNumerique> & n);

#include "NombreContraint.cpp"
#endif

