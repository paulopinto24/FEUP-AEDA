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
public:
	Entrega(Encomenda enc, Entregador ent);
	void setSuccess(bool ans);
	double getCustoTotal();
	Entregador getEntregador();
	
};

