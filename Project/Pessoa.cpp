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

bool Pessoa::operator < (const Pessoa& p) const {
	if (this->NIF < p.NIF)
		return true;
	else return false;
}

string Pessoa::getNIF() const{
	return this->NIF;
}

string Pessoa::getNome() const{
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

void Cliente::setConcelho(string concelho)
{
	this->concelho = concelho;
}

string Cliente::getEmail() {
	return this->email;
}

int Cliente::encomenda(Base& b) {
	int option;

	cout << "1 - Restaurant\n2 - Geographic zone\n3 - Price\n4 - Food type\n";
	cin >> option;
	while (1) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "You have entered wrong input" << endl;
			cin >> option;
		}
		else {
			break;
		}
	}

	int resOption;

	if (option == 1) {
		cout << b.printByRes() << endl;
		cin >> resOption;
		while (1) {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "You have entered wrong input" << endl;
				cin >> resOption;
			}
			else {
				break;
			}
		}
		vector<Produto> prods;
		Restaurante r = b.getRes(resOption - 1);
		for (int i = 0; i < r.getProdS(); i++) {
			int j = i + 1;
			cout << j << "- " << r.getProd(i).getNome() << " - " 
				<< r.getProd(i).getPreco() << "€ -"
				<< r.getProd(i).getTipo() << endl;
		}
		
		cout << "Choose a product (Press '0' to escape): ";
		int prodOption;
		cin >> prodOption;
		while (1) {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "You have entered wrong input" << endl;
				cin >> prodOption;
			}
			else {
				break;
			}
		}
		while (prodOption != 0) {
			int choice = prodOption - 1;
			prods.push_back(r.getProd(choice));
			cin >> prodOption;
			while (1) {
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "You have entered wrong input" << endl;
					cin >> prodOption;
				}
				else {
					break;
				}
			}
		}

		int dia, mes, hora, minuto;

		cout << "Month : "; cin >> mes;
		while (1) {
			if (cin.fail() || mes < 0 || mes > 12) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "You have entered wrong input" << endl;
				cin >> mes;
			}
			else {
				break;
			}
		}
		
		cout << "Day : "; cin >> dia;
		while (1) {
			if (cin.fail() || dia < 0 || dia > 31) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "You have entered wrong input" << endl;
				cin >> dia;
			}
			else {
				break;
			}
		}

		cout << "Hour : "; cin >> hora;
		while (1) {
			if (cin.fail() || hora < 0 || hora > 24) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "You have entered wrong input" << endl;
				cin >> hora;
			}
			else {
				break;
			}
		}

		cout << "Minute : "; cin >> minuto;
		while (1) {
			if (cin.fail() || minuto < 0 || minuto > 60) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "You have entered wrong input" << endl;
				cin >> minuto;
			}
			else {
				break;
			}
		}


		ostringstream d;
		d << "2019" << "-" << mes << '-' << dia;
		string data(d.str());   // so para o caso de ser mais facil trabalhar c string, senao descartar

		ostringstream h;
		h << hora << ':' << minuto;
		string horas(h.str());   // so para o caso de ser mais facil trabalhar c string, senao descartar

		string time = data + "|" + horas;

		Encomenda encomenda(r, time, prods);
		encomenda.printDados();
		cout << "Confirmar e avançar para entrega? ('0' para sair)" << endl;
		int conf;
		cin >> conf;
		while (1) {
			if (cin.fail() || minuto < 0 || minuto > 60) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "You have entered wrong input" << endl;
				cin >> conf;
			}
			else {
				break;
			}
		}
		if (conf == 0) {
			exit(1);
		}

		if (r.getConcelho() == concelho) {
			encomenda.setpFixo(3.0);
		}
		else {
			encomenda.setpFixo(5.0);
		}
		encomenda.setpTotal();

		Entrega entrega(encomenda, b.getEntreg(rand() % b.getEntregsS()), r.getNome(), this->getNIF());

		cout << "A entrega foi bem sucedida?" << endl;
		cout << "1 - Sim" << endl;
		cout << "0 - Nao" << endl;

		bool success;
		cin >> success;
		while (1) {
			if (cin.fail() || minuto < 0 || minuto > 60) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "You have entered wrong input" << endl;
				cin >> success;
			}
			else {
				break;
			}
		}

		entrega.setSuccess(success);
		b.addEntrega(entrega);
		string e;
		ostringstream strs;
		strs << entrega.getCustoTotal();
		string str = strs.str();
		e = entrega.getNIF() + ";" + entrega.getRestaurante() + ";" + str + ";" + time;
		b.addEntregaStr(e);
	}
	else if(option == 2) {
		string zona;
		cout << "Concelho desejado: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, zona);
		resOption = b.printByZone(zona);
		vector<Produto> prods;
		Restaurante r = b.getRes(resOption);
		for (int i = 0; i < r.getProdS(); i++) {
			int j = i + 1;
			cout << j << "- " << r.getProd(i).getNome() << " - "
				<< r.getProd(i).getPreco() << "€ -"
				<< r.getProd(i).getTipo() << endl;
		}

		cout << "Choose a product (Press '0' to escape): ";
		int prodOption;
		cin >> prodOption;
		while (1) {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "You have entered wrong input" << endl;
				cin >> prodOption;
			}
			else {
				break;
			}
		}
		while (prodOption != 0) {
			int choice = prodOption - 1;
			prods.push_back(r.getProd(choice));
			cin >> prodOption;
			while (1) {
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "You have entered wrong input" << endl;
					cin >> prodOption;
				}
				else {
					break;
				}
			}
		}

		int dia, mes, hora, minuto;

		cout << "Month : "; cin >> mes;
		while (1) {
			if (cin.fail() || mes < 0 || mes > 12) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "You have entered wrong input" << endl;
				cin >> mes;
			}
			else {
				break;
			}
		}

		cout << "Day : "; cin >> dia;
		while (1) {
			if (cin.fail() || dia < 0 || dia > 31) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "You have entered wrong input" << endl;
				cin >> dia;
			}
			else {
				break;
			}
		}

		cout << "Hour : "; cin >> hora;
		while (1) {
			if (cin.fail() || hora < 0 || hora > 24) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "You have entered wrong input" << endl;
				cin >> hora;
			}
			else {
				break;
			}
		}

		cout << "Minute : "; cin >> minuto;
		while (1) {
			if (cin.fail() || minuto < 0 || minuto > 60) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "You have entered wrong input" << endl;
				cin >> minuto;
			}
			else {
				break;
			}
		}


		ostringstream d;
		d << "2019" << "-" << mes << '-' << dia;
		string data(d.str());   // so para o caso de ser mais facil trabalhar c string, senao descartar

		ostringstream h;
		h << hora << ':' << minuto;
		string horas(h.str());   // so para o caso de ser mais facil trabalhar c string, senao descartar

		string time = data + "|" + horas;

		Encomenda encomenda(r, time, prods);
		encomenda.printDados();
		cout << "Confirmar e avançar para entrega? ('0' para sair)" << endl;
		int conf;
		cin >> conf;
		while (1) {
			if (cin.fail() || minuto < 0 || minuto > 60) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "You have entered wrong input" << endl;
				cin >> conf;
			}
			else {
				break;
			}
		}
		if (conf == 0) {
			exit(1);
		}

		if (r.getConcelho() == concelho) {
			encomenda.setpFixo(3.0);
		}
		else {
			encomenda.setpFixo(5.0);
		}
		encomenda.setpTotal();

		Entrega entrega(encomenda, b.getEntreg(rand() % b.getEntregsS()), r.getNome(), this->getNIF());

		cout << "A entrega foi bem sucedida?" << endl;
		cout << "1 - Sim" << endl;
		cout << "0 - Nao" << endl;

		bool success;
		cin >> success;
		while (1) {
			if (cin.fail() || minuto < 0 || minuto > 60) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "You have entered wrong input" << endl;
				cin >> success;
			}
			else {
				break;
			}
		}

		entrega.setSuccess(success);
		b.addEntrega(entrega);
		string e;
		ostringstream strs;
		strs << entrega.getCustoTotal();
		string str = strs.str();
		e = entrega.getNIF() + ";" + entrega.getRestaurante() + ";" + str + ";" + time;
		b.addEntregaStr(e);
	}
	else if (option == 3) {
		double p;
		cout << "Maximum desired price: ";
		cin >> p;
		while (1) {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "You have entered wrong input" << endl;
				cin >> p;
			}
			else {
				break;
			}
		}
		cout << b.printByPrice(p) << endl;
		cin >> resOption;
		while (1) {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "You have entered wrong input" << endl;
				cin >> resOption;
			}
			else {
				break;
			}
		}
		vector<Produto> prods;
		Restaurante r = b.getRes(resOption - 1);
		for (int i = 0; i < r.getProdS(); i++) {
			int j = i + 1;
			if (r.getProd(i).getPreco() <= p) {
				cout << j << "- " << r.getProd(i).getNome() << " - "
					<< r.getProd(i).getPreco() << "€ -"
					<< r.getProd(i).getTipo() << endl;
			}
		}

		cout << "Choose a product (Press '0' to escape): ";
		int prodOption;
		cin >> prodOption;
		while (1) {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "You have entered wrong input" << endl;
				cin >> prodOption;
			}
			else {
				break;
			}
		}
		while (prodOption != 0) {
			int choice = prodOption - 1;
			prods.push_back(r.getProd(choice));
			cin >> prodOption;
			while (1) {
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "You have entered wrong input" << endl;
					cin >> prodOption;
				}
				else {
					break;
				}
			}
		}

		int dia, mes, hora, minuto;

		cout << "Month : "; cin >> mes;
		while (1) {
			if (cin.fail() || mes < 0 || mes > 12) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "You have entered wrong input" << endl;
				cin >> mes;
			}
			else {
				break;
			}
		}

		cout << "Day : "; cin >> dia;
		while (1) {
			if (cin.fail() || dia < 0 || dia > 31) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "You have entered wrong input" << endl;
				cin >> dia;
			}
			else {
				break;
			}
		}

		cout << "Hour : "; cin >> hora;
		while (1) {
			if (cin.fail() || hora < 0 || hora > 24) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "You have entered wrong input" << endl;
				cin >> hora;
			}
			else {
				break;
			}
		}

		cout << "Minute : "; cin >> minuto;
		while (1) {
			if (cin.fail() || minuto < 0 || minuto > 60) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "You have entered wrong input" << endl;
				cin >> minuto;
			}
			else {
				break;
			}
		}


		ostringstream d;
		d << "2019" << "-" << mes << '-' << dia;
		string data(d.str());   // so para o caso de ser mais facil trabalhar c string, senao descartar

		ostringstream h;
		h << hora << ':' << minuto;
		string horas(h.str());   // so para o caso de ser mais facil trabalhar c string, senao descartar

		string time = data + "|" + horas;

		Encomenda encomenda(r, time, prods);
		encomenda.printDados();
		cout << "Confirmar e avançar para entrega? ('0' para sair)" << endl;
		int conf;
		cin >> conf;
		while (1) {
			if (cin.fail() || minuto < 0 || minuto > 60) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "You have entered wrong input" << endl;
				cin >> conf;
			}
			else {
				break;
			}
		}
		if (conf == 0) {
			exit(1);
		}

		if (r.getConcelho() == concelho) {
			encomenda.setpFixo(3.0);
		}
		else {
			encomenda.setpFixo(5.0);
		}
		encomenda.setpTotal();

		Entrega entrega(encomenda, b.getEntreg(rand() % b.getEntregsS()), r.getNome(), this->getNIF());

		cout << "A entrega foi bem sucedida?" << endl;
		cout << "1 - Sim" << endl;
		cout << "0 - Nao" << endl;

		bool success;
		cin >> success;
		while (1) {
			if (cin.fail() || minuto < 0 || minuto > 60) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "You have entered wrong input" << endl;
				cin >> success;
			}
			else {
				break;
			}
		}

		entrega.setSuccess(success);
		b.addEntrega(entrega);
		string e;
		ostringstream strs;
		strs << entrega.getCustoTotal();
		string str = strs.str();
		e = entrega.getNIF() + ";" + entrega.getRestaurante() + ";" + str + ";" + time;
		b.addEntregaStr(e);
	}
	else if (option == 4) {
		string t;
		cout << "Choose a food type: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, t);
		cout << b.printByType(t) << endl;
		cin >> resOption;
		while (1) {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "You have entered wrong input" << endl;
				cin >> resOption;
			}
			else {
				break;
			}
		}
		vector<Produto> prods;
		Restaurante r = b.getRes(resOption - 1);
		for (int i = 0; i < r.getProdS(); i++) {
			int j = i + 1;
			if (r.getProd(i).getTipo() == t) {
				cout << j << "- " << r.getProd(i).getNome() << " - "
					<< r.getProd(i).getPreco() << "€ -"
					<< r.getProd(i).getTipo() << endl;
			}
		}

		cout << "Choose a product (Press '0' to escape): ";
		int prodOption;
		cin >> prodOption;
		while (1) {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "You have entered wrong input" << endl;
				cin >> prodOption;
			}
			else {
				break;
			}
		}
		while (prodOption != 0) {
			int choice = prodOption - 1;
			prods.push_back(r.getProd(choice));
			cin >> prodOption;
			while (1) {
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "You have entered wrong input" << endl;
					cin >> prodOption;
				}
				else {
					break;
				}
			}
		}

		int dia, mes, hora, minuto;

		cout << "Month : "; cin >> mes;
		while (1) {
			if (cin.fail() || mes < 0 || mes > 12) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "You have entered wrong input" << endl;
				cin >> mes;
			}
			else {
				break;
			}
		}

		cout << "Day : "; cin >> dia;
		while (1) {
			if (cin.fail() || dia < 0 || dia > 31) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "You have entered wrong input" << endl;
				cin >> dia;
			}
			else {
				break;
			}
		}

		cout << "Hour : "; cin >> hora;
		while (1) {
			if (cin.fail() || hora < 0 || hora > 24) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "You have entered wrong input" << endl;
				cin >> hora;
			}
			else {
				break;
			}
		}

		cout << "Minute : "; cin >> minuto;
		while (1) {
			if (cin.fail() || minuto < 0 || minuto > 60) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "You have entered wrong input" << endl;
				cin >> minuto;
			}
			else {
				break;
			}
		}


		ostringstream d;
		d << "2019" << "-" << mes << '-' << dia;
		string data(d.str());   // so para o caso de ser mais facil trabalhar c string, senao descartar

		ostringstream h;
		h << hora << ':' << minuto;
		string horas(h.str());   // so para o caso de ser mais facil trabalhar c string, senao descartar

		string time = data + "|" + horas;

		Encomenda encomenda(r, time, prods);
		encomenda.printDados();
		cout << "Confirmar e avançar para entrega? ('0' para sair)" << endl;
		int conf;
		cin >> conf;
		while (1) {
			if (cin.fail() || minuto < 0 || minuto > 60) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "You have entered wrong input" << endl;
				cin >> conf;
			}
			else {
				break;
			}
		}
		if (conf == 0) {
			exit(1);
		}

		if (r.getConcelho() == concelho) {
			encomenda.setpFixo(3.0);
		}
		else {
			encomenda.setpFixo(5.0);
		}
		encomenda.setpTotal();

		Entrega entrega(encomenda, b.getEntreg(rand() % b.getEntregsS()), r.getNome(), this->getNIF());

		cout << "A entrega foi bem sucedida?" << endl;
		cout << "1 - Sim" << endl;
		cout << "0 - Nao" << endl;

		bool success;
		cin >> success;
		while (1) {
			if (cin.fail() || minuto < 0 || minuto > 60) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "You have entered wrong input" << endl;
				cin >> success;
			}
			else {
				break;
			}
		}

		entrega.setSuccess(success);
		b.addEntrega(entrega);
		string e;
		ostringstream strs;
		strs << entrega.getCustoTotal();
		string str = strs.str();
		e = entrega.getNIF() + ";" + entrega.getRestaurante() + ";" + str + ";" + time;
		b.addEntregaStr(e);
	}
	else {
		cerr << "Erro no processamento da encomenda...\n";
		return 1;
	}

	return 0;
}

string Cliente::getMorada()
{
	return morada;
}

bool Cliente::operator == (const Cliente& c) const {
	if (this->email == c.email) return true;
	else return false;
}

Funcionario::Funcionario(){}

Funcionario::Funcionario(string n, string nif, string dn, double s) : Pessoa(n, nif) {
	dataNasc = dn;
	salario = s;
}

string Funcionario::getDataNasc() const
{
	return dataNasc;
}

double Funcionario::getSalario() const
{
	return salario;
}

void Funcionario::setAtual(bool b) {
	atual = b;
}

string Funcionario::getAtual() const{
	if (atual) {
		return "Y";
	}
	else {
		return "N";
	}
}

void Funcionario::setAdmin(bool b)
{
	admin = b;
}

string Funcionario::getAdmin() const
{
	if (admin) {
		return "ADMIN";
	}
	else {
		return "ENTREG";
	}
}

string Funcionario::getsSalario() const {
	ostringstream strs;
	strs << salario;
	string str = strs.str();

	return str;
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




