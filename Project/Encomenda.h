#pragma once

#include <iostream>
#include "Restaurante.h"

using namespace std;

class Encomenda
{
	Restaurante restaurante;
	string data;
	vector<Produto> produtos;
	double pTotal;
	double pFixo;
public:
	Encomenda(Restaurante r, string d, const vector<Produto>& p);
	void printDados();
	void setpTotal();
	void setpFixo(double p);
	double getpFixo();
	double getpTotal();
	string getData();
};

