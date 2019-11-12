#ifndef BASE_H
#define BASE_H


#include <vector>
#include "Pessoa.h" 
#include "GPScoord.h"

using namespace std;

class Base 
{
private:
	string distrito;
	string morada;
	string concelho;
	GPScoord gps;
	Pessoa gerente;
	// ter uma lista por base de restaurantes ?? ou associar o restaurante à base pela morada/coordenadas gps?
	// ter uma lista de entregadores (so e apenas se tivermos tempo)
public:
	vector<Cliente> clientes;
	Base();
	Base(const string d, const string m, const string c, GPScoord& gpscoord, Pessoa &g);
	bool addCliente(Cliente);
};


#endif // !BASE_H