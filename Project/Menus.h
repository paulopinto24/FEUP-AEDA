#pragma once

#include "Base.h"

using namespace std;

void welcomeMenu() {
	cout << "===============================================================" << endl;
	cout << "Welcome to UghEats! The application that copis UberEats in such" << endl;
	cout << "a shameless way we're surprised we haven't been sued yet!" << endl;
	cout << "Start by signing in! If you you're not a registered client," << endl;
	cout << "sign up now!" << endl;
	cout << "===============================================================" << endl;
	cout << endl;
}

string openingMenu() {
	cout << "1 - Sign in (function to develop once the rest is done)" << endl;
	cout << "2 - Sign up" << endl;
	cout << "3 - Quit" << endl;

	string option;

	getline(cin, option);

	while (option != "1" && option != "2" && option != "3") {
		cerr << "Please insert a valid option... \n";
		cin.clear();
		cin.ignore();
		cin >> option;
	}

	cout << endl;
	
	return option;
}

// função testa se um email é válido i.e. tem formato de email
bool validEmail(string const& email) {
	string teste = "q";    // isto é so para nao ter q escrever um mail completo de cada vez que estou a testar o codigo (apagar antes de enviar para entrega)
	string gmail = "@gmail.com";
	string hotmail = "@hotmail.com";
	string feup = "@fe.up.pt";

	if (email.length() >= teste.length()) {
		if (email.compare(email.length() - teste.length(), teste.length(), teste) == 0)
			return true;
	}
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

// função para ver se o NIF é composto apenas por dígitos
bool is_digits(const string& str)
{
	return str.find_first_not_of("0123456789") == string::npos;
}

bool inscricao(Base b) {
	
	string nome;
	string morada;
	string nif;
	string email;

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
	/*   descomentar quando forem criadas as bases

	for (int i = 0; i < b.clientesSize(); i++) {
		if (email == b.getCliente(i).getEmail) {
			cerr << "This email is already in use...\n";
			return false;
		}
	}*/

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
	/*
	for (int i = 0; i < b.clientesSize(); i++) {
		if (nif == b.getCliente(i).getNIF()) {
			cerr << "This NIF is already in use...\n";
			return false;
		}
	}*/

	cout << endl << endl;

	//b.addCliente(Cliente(nome, nif, email, morada, b.getDistrito()));

	return true; // tem a ver com controlo de erros, se retornar true é pq deu bem, se retornar false não foi possível adicionar cliente
}

void entrar(Base base) { //posteriormente esta funçao retornará um cliente
	int option;
	cout << "1 - Sign up email\n2- Sign up with NIF\n\n";
	cin >> option;
	cin.clear();
	cin.ignore();

	while (option < 1 || option > 2) {
		cerr << "Please input a valid option:\n1 - Sign up email\n2- Sign up with NIF\n\n";
		cin >> option;
		cin.clear();
		cin.ignore();
	}

	if (option == 1) {
		string email;

		cout << "Please input your email: ";
		cin >> email;

		/*
		for (int i = 0; i < base.clientes.size(); i++) {
			if (base.clientes.at(i).getEmail == email) {
				return base.clientes.at(i);
			}
		}*/

		cerr << email << " NOT FOUND" << endl;
		exit(1);
	}
	else {
		string nif;

		cout << "Please input your NIF: ";
		cin >> nif;

		/*
		for (int i = 0; i < base.clientes.size(); i++) {
			if (base.clientes.at(i).getNIF() == nif) {
				//return base.clientes.at(i);
			}
		}*/

		cerr << nif << " NOT FOUND" << endl;
		exit(1);
	}
}

void clientPage(Cliente cliente) {
	int option;

	cout << "Options (...)\n\n";
	cout << "1 - Order\n2 - Change email\n3 - Change address\n";
	cin >> option;

	string email;
	string morada;

	switch(option){
	case 1:
		//cliente.encomenda();
		break;
	case 2:
		cout << "New email : ";
		getline(cin, email);
		cliente.setEmail(email);
		break;
	case 3:
		cout << "New address : ";
		getline(cin, morada);
		cliente.setMorada(morada);
		break;
	default:
		break;
	}
}


