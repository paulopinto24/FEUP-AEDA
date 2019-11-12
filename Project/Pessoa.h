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
	string getNome();
	bool operator == (Pessoa& p);
	int encomenda();
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
	string getMorada();
	//será necessário saber a que base pertence cada cliente? 
};

class Funcionario : public Pessoa
{
private:
	string dataNasc;
	double salario;
public:
	Funcionario(string n, string nif, string dn, double s);
	string getDataNasc();
	double getSalario();
};

class Administrativo : public Funcionario
{
private:
	string funcao;
public:
	Administrativo(string n, string nif, string dn, double s, string f);
	string getFunc();
};

class Entregador : public Funcionario
{
private:
	Veiculo veiculo;
	//vector<Entrega> entregas;
public:
	Entregador(string n, string nif, string dn, double s, Veiculo &v);
};

