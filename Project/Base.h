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
	vector<Administrativo> admins;
	vector<Entregador> entregs;
	vector<Restaurante> restaurantes;
	vector<string> concelhosFront;
	vector<Cliente> lista_negra;
	// ter uma lista por base de restaurantes ?? ou associar o restaurante à base pela morada/coordenadas gps?
	// ter uma lista de entregadores (so e apenas se tivermos tempo)
public:
	//Base();
	Base(const string d, const string m, const string c, GPScoord& gpscoord);
	string getDistrito();
	string getMorada();
	string getConcelho();
	GPScoord getLocation();
	Cliente getCliente(int i);
	bool addCliente(Cliente);
	int getClientesSize();
	int clientesSize();
	bool addAdmin(Administrativo& ad);
	Administrativo getGerente();
	bool addEntregador(Entregador &);
	int entregsSize();
	bool addRestaurante(Restaurante&);
	vector<Restaurante> getRestaurantes();
	//void printByRes();
	void addBlack(Cliente c);
	void addFront(string s);
	int getAdminsS();
	int getEntregsS();
	int getRestaurantesS();
	int getFrontS();
	int getBlackS();
	Administrativo getAdmin(int i);
	Entregador getEntreg(int i);
	Restaurante getRes(int i);
	string getFront(int i);
	Cliente getBlack(int i);
};


#endif // !BASE_H