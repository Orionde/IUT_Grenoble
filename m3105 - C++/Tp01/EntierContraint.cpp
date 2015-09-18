
#include "EntierContraint.h"

EntierContraint::EntierContraint(int val, int min, int max) {


    if (min <= max) {

        m_min = min;
        m_max = max;

        setVal(val);
    } else {
        throw ("min > max");
    }

}

int EntierContraint::getMin() {
    return m_min;
}

int EntierContraint::getMax() {
    return m_max;
}

int EntierContraint::getVal() {
    return m_val;
}

void EntierContraint::setVal(int val) {
    if (val >= m_min && val <= m_max)
        m_val = val;
    else
        throw ("val non compris entre min et max");
}

void EntierContraint::saisir(istream & cin) {
    int val;
    cin >> val;
    setVal(val);
}

void EntierContraint::afficher(ostream &cout) const {
    cout << m_val;
}

EntierContraint::operator int() {
    return m_val;
}

ostream& operator <<(ostream& cout, const EntierContraint & n) {
    n.afficher(cout);
    return(cout);
}

istream& operator >>(istream& cin, EntierContraint& n) {
    n.saisir(cin);
    return(cin);
}

