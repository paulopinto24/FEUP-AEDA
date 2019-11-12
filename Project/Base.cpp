#include "Base.h"




Base::Base(const string d, const string m, const string c, GPScoord&gpscoord) {
	this->distrito = d;
	this->morada = m;
	this->concelho = c;
	gps = gpscoord;
}

bool Base::addCliente(Cliente c) {
	for (int i = 0; i < clientes.size(); i++) {
		if (clientes.at(i) == c)
			return false;
	}
	clientes.push_back(c);
	return true;
}

string Base::getDistrito() {
	return distrito;
}

string Base::getMorada()
{
	return morada;
}

string Base::getConcelho()
{
	return concelho;
}

GPScoord Base::getLocation()
{
	return gps;
}

Cliente Base::getCliente(int i)
{
	return clientes.at(i);
}

void Base::addGerente(Administrativo & ad)
{
	gerente.push_back(ad);
}

Administrativo Base::getGerente()
{
	return gerente.at(0);
}

int Base::getClientesSize()
{
	return clientes.size();
}









