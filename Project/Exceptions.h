#pragma once

#include <string>
#include <iostream>

using namespace std;

class Excecao {
private:
	string info;
public:
	Excecao(const string info) {
		this->info = info;
	}

	string getInfo() {
		return this->info;
	}
};

class ClienteInexistente : public Excecao {
public:
	ClienteInexistente(const string info) : Excecao(info) {}
};

class OpcaoInvalida : public Excecao {
public:
	OpcaoInvalida(const string info) : Excecao(info){}
};

class NifEmUso : public Excecao {
public:
	NifEmUso(const string info) : Excecao(info){}
};

class NifInexistente : public Excecao {
public:
	NifInexistente(const string info) : Excecao(info) {}
};

class EmailInexistente : public Excecao {
public:
	EmailInexistente(const string info) : Excecao(info) {}
};

class EmailEmUso : public Excecao {
public:
	EmailEmUso(const string info) : Excecao(info) {}
};

