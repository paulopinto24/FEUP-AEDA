#pragma once

#ifndef BASE_H
#define BASE_H

#include <map>

#include "Pessoa.h" 
#include "GPScoord.h"
//#include "Entrega.h"

class Cliente;
class Administrativo;
class Entregador;
class Entrega;

using namespace std;

class Base 
{
private:
	string distrito;
	string morada;
	string concelho;
	GPScoord gps;
	vector<Cliente> clientes; //estava em publico, nao percebi entao pus privado
	vector<Administrativo> admins;
	vector<Entregador> entregs;
	vector<Restaurante> restaurantes;
	vector<string> concelhosFront;
	vector<Cliente> lista_negra;
	//map<Entregador, Entrega> historial;
	// ter uma lista por base de restaurantes ?? ou associar o restaurante à base pela morada/coordenadas gps?
	// ter uma lista de entregadores (so e apenas se tivermos tempo)
public:
	//Base();
	Base(const string d, const string m, const string c, GPScoord& gpscoord);
	//getters
	string getDistrito();
	string getMorada();
	string getConcelho();
	GPScoord getLocation();
	Cliente getCliente(int i);
	int getClientesSize();
	int getAdminsS();
	int getEntregsS();
	int getRestaurantesS();
	int getFrontS();
	int getBlackS();
	Administrativo getAdmin(int i);
	Entregador getEntreg(int i);
	Restaurante getRes(int i);
	vector<Restaurante> getRestaurantes();
	string getFront(int i);
	Cliente getBlack(int i);
	//adders
	bool addCliente(Cliente);
	bool addAdmin(Administrativo& ad);
	bool addEntregador(Entregador &);
	bool addRestaurante(Restaurante&);
	void addBlack(Cliente c);
	void addFront(string s);
	//printers
	string printByRes();
	string printByZone(string);
	string printByPrice(double);
	string printByType(string);

	void deleteClient(Cliente);
};


#endif // !BASE_H
