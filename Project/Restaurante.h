#pragma once

#include <string>
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
	string getProduto();
	double getPreco();
	string getNome();
	string getTipo();
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
	//bool operator==(Restaurante& r);
	string getNome();
	//vector<Produto> getProdutos();
	//ostringstream printProducts();
	void addProduto(Produto);
	string getMorada();
	string getConcelho();
	bool getAvailable();
	string getTpCul(int i);
	int getTpCulS();
	int getProdS();
	Produto getProd(int i);
};
