#include "Pessoa.h"

Pessoa::Pessoa(string n, string nif) {
	nome = n;
	NIF = nif;
}

Cliente::Cliente(string n, string nif, string e, string m) :Pessoa(n, nif) {
	email = e;
	morada = m;
}

Funcionario::Funcionario(string n, string nif, string dn, double s) : Pessoa(n, nif) {
	dataNasc = dn;
	salario = s;
}

Administrativo::Administrativo(string n, string nif, string dn, double s, string f) : Funcionario(n, nif, dn, s) {
	funcao = f;
}

Entregador::Entregador(string n, string nif, string dn, double s, Veiculo& v) : Funcionario(n, nif, dn, s) {
	veiculo = v;
}