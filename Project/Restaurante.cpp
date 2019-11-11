#include "Restaurante.h"

Restaurante::Restaurante(string n, string m, vector<string> &t) {
	nome = n;
	morada = m;
	tipoCulinaria = t;
}

Produto::Produto(string n, string t, double p) {
	nome = n;
	tipo = t;
	preco = p;
}

Restaurante::Restaurante()
{
}

bool Restaurante::isAvailable() {
	return this->available;
}


