#ifndef BASE_H
#define BASE_H

#include <string>
#include "GPScoord.h"
#include "Pessoa.h"
#include <vector>

using namespace std;


class Base : public GPScoord, Pessoa
{
private:
	string distrito;
	string morada;
	string concelho;
	GPScoord gps;
	Pessoa gerente;
	vector<Cliente> clientes;

public:
	Base();
	Base(const string d, const string m, const string c, GPScoord& gpscoord, Pessoa &g);
	bool addCliente(Cliente);
};









#endif // !BASE_H