#include "Base.h"


Base::Base(){}

Base::Base(const string d, const string m, const string c, GPScoord&gpscoord) {
	this->distrito = d;
	this->morada = m;
	this->concelho = c;
	gps = gpscoord;
}

//OBTER TAMANHOS DE VETORES DAS COISAS DA BASE

int Base::getClientesSize()
{
	return clientes.size();
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

int Base::getHisS()
{
	return historial.size();
}

int Base::getEntregaStrS()
{
	return historialStr.size();
}

//GETTERS DOS MESMOS VETORES

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

string Base::getEntregaStr(int i)
{
	return historialStr.at(i);
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

Entrega Base::getHis(int i)
{
	return historial.at(i);
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

bool Base::addEntregador(Entregador &e) {
	for (int i = 0; i < entregs.size(); i++) {
		if (entregs.at(i) == e) {
			return false;
		}
	}
	this->entregs.push_back(e);
	return true;
}

bool Base::addRestaurante(Restaurante& r) {
	for (int i = 0; i < restaurantes.size(); i++) {
		if (restaurantes.at(i) == r) {
			return false;
		}
	}
	restaurantes.push_back(r);
	return true;
}

vector<Restaurante> Base::getRestaurantes() {
	return this->restaurantes;
}

string Base::printByRes() {

	ostringstream oss;

	for (int i = 0; i < restaurantes.size(); i++) {
		int j = i + 1;
		oss << j << " - " << restaurantes.at(i).printProducts() << endl;
	}

	string res(oss.str());

	return res;
}

int Base::printByZone(string c) {
	vector<int> resByZone;
	ostringstream oss;
	int resOption;
	int cnt = 1;

	for (int i = 0; i < restaurantes.size(); i++) {
		if (restaurantes.at(i).getConcelho() == c) {
			resByZone.push_back(i);
			oss << cnt << " - " << restaurantes.at(i).printProducts() << endl;
			cnt++;
		}
	}

	string res(oss.str());

	cout << res;
	cin >> resOption;
	
	return resByZone.at(resOption - 1);
}

//string Base::printByPrice(double p) {
//	ostringstream oss;
//
//	for (int i = 0; i < restaurantes.size(); i++) {
//		oss << restaurantes.at(i).getNome() << endl;
//		for (int j = 0; j < restaurantes.at(i).getProdByPrice(p).size(); j++) {
//			oss << " -> " << restaurantes.at(i).getProdByPrice(p).at(j).getNome() << endl;
//		}
//	}
//
//	string res(oss.str());
//
//	return res;
//}

string Base::printByPrice(double p) {
	ostringstream oss;

	for (int i = 0; i < restaurantes.size(); i++) {
		int k = i + 1;
		oss << k << " - " << restaurantes.at(i).getNome() << endl;
		for (int j = 0; j < restaurantes.at(i).getProdS(); j++) {
			if (restaurantes.at(i).getProd(j).getPreco() <= p) {
				oss << "-> " << restaurantes.at(i).getProd(j).getNome() << "   " 
					<< restaurantes.at(i).getProd(j).getPreco() << endl;
			}
		}
	}

	string res(oss.str());

	return res;
}

//string Base::printByType(string t) {
//	ostringstream oss;
//	vector<Restaurante> rest;
//	bool add = false;
//
//	for (int i = 0; i < restaurantes.size(); i++) {
//		for (int j = 0; j < restaurantes.at(i).getType(t).size(); j++) {
//			if (restaurantes.at(i).getType(t).at(j) == t) {
//				add = true;
//			}
//		}
//
//		if (add) {
//			rest.push_back(restaurantes.at(i));
//			add = false;
//		}
//	}
//
//	string res(oss.str());
//
//	return res;
//}

string Base::printByType(string t) {
	ostringstream oss;
	vector<Restaurante> rest;
	bool add = false;

	for (int i = 0; i < restaurantes.size(); i++) {
		int k = i + 1;
		oss << k << " - " << restaurantes.at(i).getNome() << endl;
		for (int j = 0; j < restaurantes.at(i).getProdS(); j++) {
			if (restaurantes.at(i).getProd(j).getTipo() == t) {
				oss << "-> " << restaurantes.at(i).getProd(j).getNome() << "   "
					<< restaurantes.at(i).getProd(j).getPreco() << endl;
			}
		}

	}

	string res(oss.str());

	return res;
}

void Base::deleteClient(Cliente cliente) {
	for (unsigned int i = 0; i < clientes.size(); i++) {
		if (clientes.at(i) == cliente) {
			clientes.erase(clientes.begin() + i);
		}
	}
}

void Base::sortClientes() {
	for (unsigned int i = 1; i < clientes.size(); i++)
	{
		Cliente tmp = clientes.at(i);
		int j;
		for (j = i; j > 0 && tmp < clientes.at(j - 1); j--)
			clientes.at(j) = clientes.at(j - 1);
		clientes.at(j) = tmp;
	}
}

void Base::addBlack(Cliente c)
{
	lista_negra.push_back(c);
}

void Base::addFront(string s)
{
	concelhosFront.push_back(s);
}

void Base::addEntrega(Entrega e)
{
	historial.push_back(e);
}

void Base::addEntregaStr(string e)
{
	historialStr.push_back(e);
}

void Base::sortBlack() {

	// selection sort

	int min_idx;

	for (unsigned int i = 0; i < lista_negra.size() - 1; i++)
	{
		min_idx = i;
		for (unsigned int j = i + 1; j < lista_negra.size(); j++)
			if (lista_negra.at(j).getNIF() < lista_negra.at(min_idx).getNIF())
				min_idx = j;

		Cliente temp = lista_negra.at(min_idx);
		lista_negra.at(min_idx) = lista_negra.at(i);
		lista_negra.at(i) = temp;
	}
}








