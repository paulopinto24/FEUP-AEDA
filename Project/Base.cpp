#include "Base.h"

Base::Base(){}

Base::Base(const string d, const string m, const string c, GPScoord &gpscoord, Pessoa &g) {
	this->distrito = d;
	this->morada = m;
	this->concelho = c;
	gps = gpscoord;
	gerente = g;
}

bool Base::addCliente(Cliente c) {
	for (int i = 0; i < clientes.size; i++) {
		if (clientes.at(i) == c)
			return false;
	}
	clientes.push_back(c);
	return true;
}