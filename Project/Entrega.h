#pragma once
#include "Pessoa.h"

class Entregador;
class Encomenda;

class Entrega
{
	double custoFixo;
	double custoTotal;
	bool success;
	vector<Entregador> entregador;
	string restaurante;
	string nif;
	string time;
public:
	Entrega(Encomenda enc, Entregador ent, string r, string nif);
	void setSuccess(bool ans);
	double getCustoTotal();
	Entregador getEntregador();
	string getRestaurante();
	string getNIF();
	string getTime();
	
};

