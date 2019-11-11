#pragma once

#include <iostream>
#include <sstream>
#include "Veiculo.h"
#include "Restaurante.h"

using namespace std;

class Pessoa
{
private:
	string nome;
	string NIF;
public:
	Pessoa();
	Pessoa(string n, string nif);
	string getNIF();
	bool operator == (Pessoa& p);
};

class Cliente : public Pessoa
{
private:
	string email;
	string morada;
public:
	Cliente(string n, string nif, string e, string m);
	void setEmail(string email);
	void setMorada(string morada);
	string getEmail();
	int encomenda();
};

class Funcionario : public Pessoa
{
private:
	string dataNasc;
	double salario;
public:
	Funcionario(string n, string nif, string dn, double s);
};

class Administrativo : public Funcionario
{
private:
	string funcao;
public:
	Administrativo(string n, string nif, string dn, double s, string f);
};

class Entregador : public Funcionario
{
private:
	Veiculo veiculo;
	//vector<Entrega> entregas;
public:
	Entregador(string n, string nif, string dn, double s, Veiculo &v);
};

