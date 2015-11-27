#ifndef ENTIERCONTRAINT_H
#define	ENTIERCONTRAINT_H
#include <iostream>

using namespace std;

class EntierContraint {
public:
    EntierContraint(int valeur = 0, int min = 0, int max = 100);
    int getMin();
    int getMax();
    int getVal();

    void setMin(int min);
    void setMax(int max);
    void setVal(int val);

    void saisir(istream & cin = std::cin);
    void afficher(ostream &cout = std::cout) const;

    operator int();

    friend ostream & operator <<(ostream & cout, const EntierContraint & n);
    friend istream& operator >>(istream& cin, EntierContraint & n);
 
    
private:
    int m_min;
    int m_max;
    int m_val;

};

#endif

