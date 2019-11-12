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
	vector<Cliente> clientes; //estava em publico, nao percebi entao pus privado
	vector<Administrativo> gerente;
	vector<Restaurante> restaurantes;
	// ter uma lista por base de restaurantes ?? ou associar o restaurante à base pela morada/coordenadas gps?
	// ter uma lista de entregadores (so e apenas se tivermos tempo)
public:
	//Base();
	Base(const string d, const string m, const string c, GPScoord& gpscoord);
	bool addCliente(Cliente);
	string getDistrito();
	string getMorada();
	string getConcelho();
	GPScoord getLocation();
	Cliente getCliente(int i);
	void addGerente(Administrativo& ad);
	Administrativo getGerente();
	int getClientesSize();
};


#endif // !BASE_H