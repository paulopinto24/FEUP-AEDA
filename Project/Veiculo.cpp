#include "Veiculo.h"

Veiculo::Veiculo(string m, string t, string da) {
	tipo = t;
	marca = m;
	dataAquisicao = da;
}

string Veiculo::getMarca() {
	return marca;
}

string Veiculo::getTipo() {
	return tipo;
}

string Veiculo::getDataAquisicao() {
	return dataAquisicao;
}

void Veiculo::setMarca(string m) {
	marca = m;
}

void Veiculo::setTipo(string t) {
	tipo = t;
}

void Veiculo::setDataAquisicao(string ds) {
	dataAquisicao = ds;
}

bool Veiculo::operator==(const Veiculo & v1) const {
	if (this->marca == v1.marca && this->tipo == v1.tipo)
		return true;
	return false;
}

Veiculo::Veiculo()
{
}


