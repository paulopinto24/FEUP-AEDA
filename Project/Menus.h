#pragma once

#include "Base.h"
#include "Exceptions.h"
#include <conio.h>

using namespace std;

/**
 * @brief Mostra no ecrã uma mensagem inicial
 */
void welcomeMenu() {
	cout << "===============================================================" << endl;
	cout << "Welcome to UghEats! Start by signing in! If you you're not a" << endl;
	cout << "registered client, sign up now!" << endl;
	cout << "===============================================================" << endl;
	cout << endl;
}

/**
 * @brief Permite selecionar entre fazer sign in, sign up ou sair da aplicação
 * @return Retorna a opção escolhida
 */
string openingMenu() {
	cout << "1 - Sign in" << endl;
	cout << "2 - Sign up" << endl;
	cout << "3 - Quit" << endl;
	cout << "AdminAEDA1920" << endl;

	string option;

	getline(cin, option);

	while (option != "1" && option != "2" && option != "3" && option != "AdminAEDA1920") {
		cerr << "Please insert a valid option... \n";
		cin >> option;
		cin.clear();
		cin.ignore();
	}

	cout << endl;

	return option;
}

/**
 * @brief Verifica se um email é válido i.e. se tem formato de email
 * @param email - email a ser verificado
 * @return Retorna verdadeiro se o email for válido, caso contrário retorna falso
 */
bool validEmail(string const& email) {

	string gmail = "@gmail.com";
	string hotmail = "@hotmail.com";
	string feup = "@fe.up.pt";

	if (email.length() >= gmail.length()) {
		if (email.compare(email.length() - gmail.length(), gmail.length(), gmail) == 0)
			return true;
	}
	if (email.length() >= hotmail.length()) {
		if (email.compare(email.length() - hotmail.length(), hotmail.length(), hotmail) == 0)
			return true;
	}
	if (email.length() >= feup.length()) {
		if (email.compare(email.length() - feup.length(), feup.length(), feup) == 0)
			return true;
	}
	return false;
}

/**
 * @brief Verifica se uma string é composta apenas por dígitos
 * @param str - string a ser verificada
 * @return Retorna verdadeiro se a string for composta apenas por dígitos, caso contrário retorna falso
 */
bool is_digits(const string& str)
{
	return str.find_first_not_of("0123456789") == string::npos;
}

/**
 * @brief Verifica se um concelho existe na base
 * @param concelho - string a ser verificada
 * @param b - base onde o concelho deve pertencer
 * @return Retorna verdadeiro se o conselho existir naquela base, caso contrário lança a exceção ConcelhoInexistente
 */
bool is_concelho(Base& b, const string concelho) {
	bool isConcelho = false;

	if (concelho == b.getConcelho()) {
		isConcelho = true;
	}
	else {
		for (int i = 0; i < b.getFrontS(); i++) {
			if (concelho == b.getFront(i)) {
				isConcelho = true;
			}
		}
	}

	if (!isConcelho) {
		throw ConcelhoInexistente(concelho);
	}

	return isConcelho;
}

/**
 * @brief Procura um email numa base
 * @param base - base onde se pretende efetuar a pesquisa
 * @param email - email que se pretende encontrar
 * @return Retorna a posição do email se encontrado, -1 se não existir e -2 de estiver na lista negra
 */
int encontraEmail(Base base, string email) {
	int pos = -1;

	for (int i = 0; i < base.getBlackS(); i++) {
		if (email == base.getBlack(i).getEmail()) {
			pos = -2;
		}
	}

	for (int i = 0; i < base.getClientesSize(); i++) {
		if (email == base.getCliente(i).getEmail()) {
			pos = i;
		}
	}

	return pos;
}

/**
 * @brief Procura um nif numa base
 * @param base - base onde se pretende efetuar a pesquisa
 * @param nif - nif que se pretende encontrar
 * @return Retorna a posição do nif se encontrado, -1 se não existir e -2 de estiver na lista negra
 */
int encontraNif(Base base, string nif) {
	int pos = -1;

	int left = 0, right = base.getBlackS() - 1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (base.getBlack(middle).getNIF() < nif)
			left = middle + 1;
		else if (base.getBlack(middle).getNIF() > nif)
			right = middle - 1;
		else {
			pos = -2;
			break;
		}
	}

	left = 0, right = base.getClientesSize() - 1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (base.getCliente(middle).getNIF() < nif)
			left = middle + 1;
		else if (base.getCliente(middle).getNIF() > nif)
			right = middle - 1;
		else {
			pos = middle;
			break;
		}
	}

	return pos;
}

/**
 * @brief Permite a um novo cliente inscrever-se mostrando no ecrã todas as instruções
 * @param b - base em que o cliente se pretende inscrever
 * @return Retorna verdadeiro se a inscrição for bem sucedida, caso contrário retorna falso
 */
bool inscricao(Base& b) {

	string nome;
	string morada;
	string nif;
	string email;
	string concelho;

	// Nome
	cout << "\nName : ";
	getline(cin, nome);

	// Email
	cout << endl << "Email : ";
	cin >> email;
	cin.clear();
	cin.ignore();
	while (!validEmail(email)) {
		cerr << "Please insert a valid email: ";
		cin >> email;
		cin.clear();
		cin.ignore();
	}

	if (encontraEmail(b, email) != -1) throw EmailEmUso(email);

	//Concelho
	bool isConcelho = false;
	while (!isConcelho) {
		cout << endl << "Concelho : ";
		cin >> concelho;
		cin.clear();
		cin.ignore();

		try {
			isConcelho = is_concelho(b, concelho);
		}
		catch (ConcelhoInexistente(concelho)) {
			cout << "Exception caught: county " << concelho.getInfo() << " does not exist" << endl;
		}
	}

	// Morada
	cout << endl << "Morada : ";
	getline(cin, morada);

	// NIF
	cout << endl << "NIF : ";
	cin >> nif;
	cin.clear();
	cin.ignore();

	while (nif.length() != 9 || !is_digits(nif)) {
		cerr << "Please insert a valid NIF : ";
		cin >> nif;
		cin.clear();
		cin.ignore();
	}

	cout << endl << endl;

	if (encontraNif(b, nif) != -1) throw NifEmUso(nif);

	b.addCliente(Cliente(nome, nif, email, morada, concelho, b.getDistrito()));
	return true;
}

/**
 * @brief Permite a um cliente entrar numa conta já criada
 * @param base - base a que a conta pertence
 * @return Retorna a conta do cliente
 */
Cliente entrar(Base base) { //posteriormente esta funçao retornará um cliente
	int option;

	cout << "\nHow do you want do sign in?\n1 - Sign in email\n2 - Sign in with NIF\n\n";
	cin >> option;
	cin.clear();
	cin.ignore();

	while (option < 1 || option > 2) {
		cerr << "Please input a valid option:\n1 - Sign in email\n2- Sign in with NIF\n\n";
		cin >> option;
		cin.clear();
		cin.ignore();
	}

	if (option == 1) {
		string email;
		bool isBlack = false;

		while (1) {

			cout << "Please input your email: ";
			cin >> email;
			cin.clear();
			cin.ignore();
			int pos = -1;

			if ((pos = encontraEmail(base, email)) == -1) throw NifInexistente(email);
			else if (pos == -2) throw BannedAccount(email);
			else return base.getCliente(pos);
		}
	}
	else {
		string nif;
		bool isBlack = false;

		while (1) {
			cout << "Please input your NIF: ";
			cin >> nif;
			cin.clear();
			cin.ignore();
			int pos;

			if ((pos = encontraNif(base, nif)) == -1) throw NifInexistente(nif);
			else if (pos == -2) throw BannedAccount(nif);
			else return base.getCliente(pos);
		}
	}
}

/**
 * @brief Permite ao cliente realizar várias ações, como encomendar, verificar a sua conta e alterar as suas informações
 * @param cliente - cliente ao qual pertence a conta
 * @param b - base onde o cliente está inscrito
 * @return Retorna 0 se o cliente saiu de forma normal da sua conta, caso contrário retorna 1
 */
int clientPage(Cliente cliente, Base& b) {
	int option;
	string email;
	string morada;
	string concelho;
	string deleteAccount;

	//cliente.encomenda(base);

	while (1) {

		cout << "\nOptions (...)\n";
		cout << "\n1 - Order\n2 - Check account\n3 - Change email\n4 - Change address\n5 - Delete Account\n0 - Log out\n";
		cin >> option;
		cin.clear();
		cin.ignore();

		switch (option) {
		case 1:
			cliente.encomenda(b);
			continue;
		case 2:
			cout << "\n=============================" << endl;
			cout << "==       Account Info       ==" << endl;
			cout << "=============================" << endl;
			cout << "Name : " << cliente.getNome() << endl;
			cout << "Email : " << cliente.getEmail() << endl;
			cout << "Address : " << cliente.getMorada() << " ; " << cliente.getConcelho() << endl;
			cout << "NIF : " << cliente.getNIF() << endl;
			_getch();
			continue;
		case 3:
			while (1) {
				cout << "New email : ";
				cin >> email;
				cin.clear();
				cin.ignore();
				if (validEmail(email)) {
					b.deleteClient(cliente);
					cliente.setEmail(email);
					b.addCliente(cliente);
					break;
				}
				else cout << "Please input a valid email...\n";
			}
			continue;
		case 4:
			cout << "New address : ";
			while (1) {
				cout << endl << "Concelho : ";
				cin >> concelho;
				cin.clear();
				cin.ignore();
				bool isConcelho = false;

				if (concelho == b.getConcelho()) {
					isConcelho = true;
				}
				else {
					for (int i = 0; i < b.getFrontS(); i++) {
						if (concelho == b.getFront(i)) {
							isConcelho = true;
						}
					}
				}

				if (!isConcelho) {
					cerr << "County not valid!!!" << endl;
				}
				else break;
			}
			cout << "Address : ";
			getline(cin, morada);
			b.deleteClient(cliente);
			cliente.setConcelho(concelho);
			cliente.setMorada(morada);
			b.addCliente(cliente);
			continue;
		case 5:
			while (1) {
				cout << "Delete account? yes(y) or no(n)" << endl;
				cin >> deleteAccount;
				cin.clear();
				cin.ignore();
				if ("Y" == deleteAccount || "y" == deleteAccount) {
					b.deleteClient(cliente);
					return 0;
				}
				else if ("N" == deleteAccount || "n" == deleteAccount)
					break;
			}
			continue;
		case 0:
			return 0;
		default:
			return 1;
		}
	}
}

/**
 * @brief Permite ao administrador realizar ações de gerência da empresa
 * @param app - aplicação que se pretenda correr
 */
void developerMenu(UghEatsFD* app) {

	cout << endl;
	cout << "WELCOME TO ADMIN MODE" << endl;

	while (1) {
		cout << "Please choose one of the following options: " << endl;
		cout << "1 - See profits" << endl;
		cout << "2 - Ban a user" << endl;
		cout << "3 - Check vehicles" << endl;
		cout << "4 - Check workers' record" << endl;
		cout << "0 - Quit" << endl;

		int option;
		cin >> option;
		while (1) {
			if (cin.fail() || (option != 1 && option != 2 && option != 3 && option != 4 && option != 0)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "You have entered wrong input" << endl;
				cin >> option;
			}
			else {
				break;
			}
		}

		if (option == 1) {
			app->getProfit();
		}
		else if (option == 2) {
			try {
				app->banUser();
			}
			catch (ClienteInexistente & e) {
				cout << "Exception caught: client with NIF " << e.getInfo() << " does not exist" << endl;
				_getch();
			}
		}
		else if (option == 3) {
			app->checkVehicles();
		}
		else if (option == 4) {
			app->check_func_records();
		}
		else if (option == 0) {
			break;
		}
	}

}

















