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

string Produto::getNome() {
	return nome;
}

double Produto::getPreco() {
	return preco;
}

string Produto::getTipo() {
	return tipo;
}

bool Produto::operator==(Produto& p) {
	if (nome == p.nome) return true;
	else return false;
}

Restaurante::Restaurante()
{
	available = false;
}

bool Restaurante::isAvailable() {
	return this->available;
}

bool Restaurante::operator==(Restaurante &r) {
	if (this->morada == r.morada) {
		return true;
	}
	else return false;
}

string Restaurante::getNome() {
	return nome;
}

vector<Produto> Restaurante::getProdutos() {
	return produtos;
}

bool Restaurante::addProduto(Produto p)
{
	for (int i = 0; i < produtos.size(); i++) {
		if (produtos.at(i) == p) {
			return false;
		}
	}
	produtos.push_back(p);
	return true;
}

string Restaurante::printProducts() {
	ostringstream oss;
	oss << this->nome << endl;
	for (int i = 0; i < produtos.size(); i++) {
		oss << " -> " << produtos.at(i).getNome() << "   " << produtos.at(i).getPreco() << endl;
	}

	string print(oss.str());

	return print;
}

vector<Produto> Restaurante::getProdByPrice(double p) {
	vector<Produto> prods;

	for (int i = 0; i < produtos.size(); i++) {
		if (produtos.at(i).getPreco() <= p) {
			prods.push_back(produtos.at(i));
		}
	}

	return prods;
}

vector<string> Restaurante::getType(string t) {
	return tipoCulinaria;
}

//GETTERS DE RESTAURANTE
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



