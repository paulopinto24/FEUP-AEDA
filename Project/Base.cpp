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

bool Base::addAdmin(Administrativo & ad)
{
	for (int i = 0; i < admins.size(); i++) {
		if (admins.at(i) == ad) {
			return false;
		}
	}
	admins.push_back(ad);
	return true;
}

Administrativo Base::getGerente()
{
	return admins.at(0);
}
int Base::getClientesSize()
{
	return clientes.size();
}

int Base::clientesSize() {
	return this->clientes.size();
}

bool Base::addEntregador(Entregador &e) {
	for (int i = 0; i < entregs.size(); i++) {
		if (entregs.at(i) == e) {
			return false;
		}
	}
	this->entregs.push_back(e);
	return true;
}

int Base::entregsSize() {
	return this->entregs.size();
}

bool Base::addRestaurante(Restaurante& r) {
	/*for (int i = 0; i < restaurantes.size(); i++) {
		if (restaurantes.at(i) == r) {
			return false;
		}
	}*/
	restaurantes.push_back(r);
	return true;
}

vector<Restaurante> Base::getRestaurantes() {
	return this->restaurantes;
}

//void Base::printByRes() {
//	ostringstream oss;
//	for (int i = 0; i < restaurantes.size(); i++) {
//		oss << restaurantes.at(i).getNome() << endl;
//		vector<Produto> produtos = restaurantes.at(i).getProdutos();
//		for (int j = 0; j < produtos.size(); j++) {
//			oss << " -> " << produtos.at(i).getProduto() << "   " << produtos.at(i).getPreco() << endl;
//		}
//	}
//}

void Base::addBlack(Cliente c)
{
	lista_negra.push_back(c);
}

void Base::addFront(string s)
{
	concelhosFront.push_back(s);
}

int Base::getAdminsS()
{
	return admins.size();
}

int Base::getEntregsS()
{
	return entregs.size();
}

int Base::getRestaurantesS()
{
	return restaurantes.size();
}

int Base::getFrontS()
{
	return concelhosFront.size();
}

int Base::getBlackS()
{
	return lista_negra.size();
}

Administrativo Base::getAdmin(int i)
{
	return admins.at(i);
}

Entregador Base::getEntreg(int i)
{
	return entregs.at(i);
}

Restaurante Base::getRes(int i)
{
	return restaurantes.at(i);
}

string Base::getFront(int i)
{
	return concelhosFront.at(i);
}

Cliente Base::getBlack(int i)
{
	return lista_negra.at(i);
}









