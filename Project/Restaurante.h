#pragma once

#include <string>
#include <vector>

using namespace std;

class Produto
{
private:
	string nome;
	string tipo;
	double preco;
public:
	Produto(string, string, double);
};

class Restaurante
{
private:
	string nome;
	string morada;
	vector<string> tipoCulinaria;
	static vector<Produto> produtos;
public:
	Restaurante(string, string, vector<string>&);
};