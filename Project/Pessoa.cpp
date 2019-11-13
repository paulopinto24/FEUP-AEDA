#include "Pessoa.h"

Pessoa::Pessoa() {};

using namespace std;

Pessoa::Pessoa(string n, string nif) {
	nome = n;
	NIF = nif;
}

bool Pessoa::operator==(Pessoa& p) {
	if (this->NIF == p.NIF)
		return true;
	else return false;
}

int Pessoa::encomenda()
{
	return 0;
}

string Pessoa::getNIF() {
	return this->NIF;
}

string Pessoa::getNome() {
	return nome;
}

Cliente::Cliente(string n, string nif, string e, string m, string c, string b) :Pessoa(n, nif) {
	email = e;
	morada = m;
	base = b;
	concelho = c;
}

void Cliente::setEmail(string email) {
	this->email = email;
}

void Cliente::setMorada(string morada) {
	this->morada = morada;
}

string Cliente::getEmail() {
	return this->email;
}

int Cliente::encomenda() {
	int option;

	cout << "1 - Restaurant\n2 - Geographic zone\n3 - Price\n4 - Food type\n";
	cin >> option;

	if (option == 1) {
		// usar printByRes
	}
	else if(option == 2) {
		int ft;
		// usar printByZone
	}
	else if (option == 3) {
		// usar printByPrice
	}
	else if (option == 4) {
		// usar printByType
	}
	else {
		cerr << "Erro no processamento da encomenda...\n";
		return 1;
	}

	int dia, mes, hora, minuto;

	cout << "Month : "; cin >> mes;
	cout << "Day : "; cin >> dia;
	cout << "Hour : "; cin >> hora;
	cout << "Minute : "; cin >> minuto;

	ostringstream d;
	d << dia << '-' << mes << "-2019";
	string data(d.str());   // so para o caso de ser mais facil trabalhar c string, senao descartar

	ostringstream h;
	h << hora << ':' << minuto;
	string horas(h.str());   // so para o caso de ser mais facil trabalhar c string, senao descartar

	// encontrar funcionario para realizar encomenda
	// caso nao haja nenhum disponivel, retornar um valor diferente de 0

	return 0;
}

string Cliente::getMorada()
{
	return morada;
}

Funcionario::Funcionario(string n, string nif, string dn, double s) : Pessoa(n, nif) {
	dataNasc = dn;
	salario = s;
}

string Funcionario::getDataNasc()
{
	return dataNasc;
}

double Funcionario::getSalario()
{
	return salario;
}

Administrativo::Administrativo(string n, string nif, string dn, double s, string f) : Funcionario(n, nif, dn, s) {
	funcao = f;
}

string Administrativo::getFunc()
{
	return funcao;
}

Entregador::Entregador(string n, string nif, string dn, double s, Veiculo& v) : Funcionario(n, nif, dn, s) {
	veiculo = v;
}

void Entregador::setCom(double comissao)
{
	this->comissao = comissao;
}

//GETTERS DE ENTREGADOR
Veiculo Entregador::getVeiculo()
{
	return veiculo;
}

double Entregador::getComissao()
{
	return comissao;
}

//GETTER PARA CLIENTE
string Cliente::getConcelho()
{
	return concelho;
}




