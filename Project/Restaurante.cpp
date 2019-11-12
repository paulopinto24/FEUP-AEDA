#include "Restaurante.h"

Restaurante::Restaurante(string n, string m, string c, vector<string> &t, bool a) {
	nome = n;
	morada = m;
	concelho = c;
	tipoCulinaria = t;
	available = a;
}

Produto::Produto(string n, string t, double p) {
	nome = n;
	tipo = t;
	preco = p;
}

double Produto::getPreco()
{
	return preco;
}

string Produto::getNome()
{
	return nome;
}

string Produto::getTipo()
{
	return tipo;
}



Restaurante::Restaurante()
{
}

bool Restaurante::isAvailable() {
	return this->available;
}

string Restaurante::getNome()
{
	return nome;
}

void Restaurante::addProduto(Produto p)
{
	produtos.push_back(p);
}

string Restaurante::getMorada()
{
	return morada;
}

string Restaurante::getConcelho()
{
	return concelho;
}

bool Restaurante::getAvailable()
{
	return available;
}

string Restaurante::getTpCul(int i)
{
	return tipoCulinaria.at(i);
}

int Restaurante::getTpCulS()
{
	return tipoCulinaria.size();
}

int Restaurante::getProdS()
{
	return produtos.size();
}

Produto Restaurante::getProd(int i)
{
	return produtos.at(i);
}


