#pragma once

#include "Restaurante.h"

class Encomenda
{
	Restaurante restaurante;
	string data;
	vector<Produto> produtos;
public:
	Encomenda(Restaurante r, string d, const vector<Produto>& p);
};

