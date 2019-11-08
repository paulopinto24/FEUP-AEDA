#include "Base.h"

template <class G, class P, class C>
Base<G,P,C>::Base(){}

template <class G, class P, class C>
Base<G,P,C>::Base(const string d, const string m, const string c, G &gpscoord, P &g) {
	this->distrito = d;
	this->morada = m;
	this->concelho = c;
	gps = gpscoord;
	gerente = g;
}

template <class G, class P, class C>
bool Base<G,P,C>::addCliente(C c) {
	for (int i = 0; i < clientes.size; i++) {
		if (clientes.at(i) == c)
			return false;
	}
	clientes.push_back(c);
	return true;
}