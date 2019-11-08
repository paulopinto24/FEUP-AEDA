#pragma once

#include <string>
#include <iostream>
#include "Veiculo.h"
#include "Restaurante.h"
#include "UghEatsFD.h"
#include "Base.h"

using namespace std;

class Pessoa
{
private:
	string nome;
	string NIF;
public:
	Pessoa();
	Pessoa(string n, string nif);
	bool operator == (Pessoa& p);
};

class Cliente : public Pessoa
{
private:
	string email;
	string morada;
public:
	Cliente(string n, string nif, string e, string m);
	//bool encomenda(Restaurante r, string d, string hora);
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