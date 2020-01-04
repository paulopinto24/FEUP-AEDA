#include "Veiculo.h"

Veiculo::Veiculo(string m, string t, string da, string mat, int ne, float km) {
	tipo = t;
	marca = m;
	dataAquisicao = da;
	matricula = mat;
	kms = km;
	numero_entregas = ne;
}

void Veiculo::doEntrega() {
	float random = ((float)rand()) / (float)RAND_MAX;
	float ran = random * 14.9;

	this->kms += 0.1 + ran;
	this->numero_entregas++;
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

/*
string Veiculo::getDataAquisicao() {
	return dataAquisicao;
}*/

string Veiculo::getMatricula() {
	return matricula;
}

int Veiculo::getEntregas() {
	return numero_entregas;
}

float Veiculo::getKms() {
	return kms;
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
	if (this->marca == v1.marca && this->tipo == v1.tipo && this->dataAquisicao == v1.dataAquisicao)
		return true;
	return false;
}

bool Veiculo::operator<(const Veiculo& v1) const {
	if (this->numero_entregas < v1.numero_entregas)
		return true;
	if (this->numero_entregas == v1.numero_entregas) {
		if (this->kms < v1.kms)
			return true;
	}
	return false;
}

Veiculo::Veiculo()
{
}


