#ifdef NOMBRECONTRAINT_H

template <class TypeNumerique>
NombreContraint<TypeNumerique>::NombreContraint(TypeNumerique val, TypeNumerique min, TypeNumerique max) {


	if (min <= max) {

		m_min = min;
		m_max = max;

		setVal(val);
	} else {
		throw ("min > max");
	}

}

template <class TypeNumerique>
TypeNumerique NombreContraint<TypeNumerique>::getMin() {
	return m_min;
}

template <class TypeNumerique>
TypeNumerique NombreContraint<TypeNumerique>::getMax() {
	return m_max;
}

template <class TypeNumerique>
TypeNumerique NombreContraint<TypeNumerique>::getVal() {
	return m_val;
}

template <class TypeNumerique>
void NombreContraint<TypeNumerique>::setVal(TypeNumerique val) {
	if (val >= m_min && val <= m_max)
		m_val = val;
	else
		throw ("val non compris entre min et max");
}

template <class TypeNumerique>
void NombreContraint<TypeNumerique>::saisir(istream & cin) {
	TypeNumerique val;
	cin >> val;
	setVal(val);
}

template <class TypeNumerique>
void NombreContraint<TypeNumerique>::afficher(ostream &cout) const {
	cout << m_val;
}

template <class TypeNumerique>
NombreContraint<TypeNumerique>::operator NombreContraint() {
	return m_val;
}

template <class TypeNumerique>
ostream& operator <<(ostream& cout, const NombreContraint<TypeNumerique> & n) {
	n.afficher(cout);
	return(cout);
}

template <class TypeNumerique>
istream& operator >>(istream& cin, NombreContraint<TypeNumerique> & n) {
	n.saisir(cin);
	return(cin);    
}

#endif
