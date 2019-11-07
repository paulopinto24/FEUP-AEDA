#include "Veiculo.h"

Veiculo::Veiculo(string mat, string mar) {
	matricula = mat;
	marca = mar;
}

string Veiculo::getMarca() {
	return marca;
}

string Veiculo::getMatricula() {
	return matricula;
}

void Veiculo::setMarca(string m) {
	marca = m;
}

void Veiculo::setMatricula(string m) {
	matricula = m;
}

bool Veiculo::operator==(const Veiculo & v1) const {
	if (this->marca == v1.marca && this->matricula == v1.matricula)
		return true;
	return false;
}