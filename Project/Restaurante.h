#pragma once

#include <vector>
#include <sstream>

using namespace std;

class Produto
{
private:
	string nome;
	string tipo;
	double preco;
public:
	Produto(string, string, double);
	string getNome();
	double getPreco();
	string getTipo();
	bool operator==(Produto& p);
};

class Restaurante
{
private:
	string nome;
	string morada;
	string concelho;
	vector<string> tipoCulinaria;
	vector<Produto> produtos;
	bool available;
public:
	Restaurante();
	Restaurante(string, string, string, vector<string>&, bool);
	bool isAvailable();
	bool operator==(Restaurante& r);
	string getNome();
	vector<Produto> getProdutos();
	string getMorada();
	string getConcelho();
	string printProducts();
	bool addProduto(Produto);
	vector<Produto> getProdByPrice(double);
	vector<string> getType(string);

	bool getAvailable();
	string getTpCul(int i);
	int getTpCulS();
	int getProdS();
	Produto getProd(int i);
};
