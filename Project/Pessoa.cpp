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

Cliente::Cliente(string n, string nif, string e, string m) :Pessoa(n, nif) {
	email = e;
	morada = m;
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

	cout << "1 - Restaurant\n2 - Food Type\n3 - Plate";
	cin >> option;

	if (option == 1) {
		// loop para mostrar todos os restaurantes e escolher 1 (mostrar o preço da entrega -> 3 ou 5€)
		// fazer loop com todas as comidas do restaurante escolhido
	}
	else if(option == 2) {
		int ft;
		// fazer loop com todos os tipos de comida e escolher 1
		// fazer loop com todos os restaurantes que tem esse tipo de comida (mostrar o preço da entrega -> 3 ou 5€)
		// fazer loop com todas as comidas do restaurante escolhido
	}
	else if (option == 3) {
		// fazer loop de todos os pratos de todos os restaurantes e escolher 1
		// fazer loop de todos os restaurantes que tem esse prato (mostrar o preço da entrega -> 3 ou 5€)
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




