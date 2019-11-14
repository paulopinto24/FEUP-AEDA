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

// fun��o testa se um email � v�lido i.e. tem formato de email
bool validEmail(string const& email) {
	string teste = "q";    // isto � so para nao ter q escrever um mail completo de cada vez que estou a testar o codigo (apagar antes de enviar para entrega)
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

// fun��o para ver se o NIF � composto apenas por d�gitos
bool is_digits(const string& str)
{
	return str.find_first_not_of("0123456789") == string::npos;
}

bool inscricao(Base b) {
	
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

	for (int i = 0; i < b.getClientesSize(); i++) {
		if (email == b.getCliente(i).getEmail()) {
			cerr << "This email is already in use...\n";
			return false;
		}
	}

	//Concelho
	cout << endl << "Concelho : ";
	cin >> concelho;
	cin.clear();
	cin.ignore();
	bool isConcelho = false;

	if (concelho == b.getConcelho()) {
		isConcelho = true;
	}
	else {
		for (int i = 0; i <= b.getFrontS(); i++) {
			if (concelho == b.getFront(i)) {
				isConcelho = true;
			}
		}
	}

	if (!isConcelho) {
		cerr << "Concelho not valid!!!" << endl;
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
	
	for (int i = 0; i < b.getClientesSize(); i++) {
		if (nif == b.getCliente(i).getNIF()) {
			cerr << "This NIF is already in use...\n";
			return false;
		}
	}

	cout << endl << endl;

	cout << "at� aqui" << endl << endl;

	b.addCliente(Cliente(nome, nif, email, morada, concelho, b.getDistrito()));

	return true; 
}

Cliente entrar(Base* base) { //posteriormente esta fun�ao retornar� um cliente
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

		cout << "Please input your email: ";

		while (1) {
			cin >> email;
			cin.clear();
			cin.ignore();
			for (int i = 0; i < base->getClientesSize(); i++) {
				if (base->getCliente(i).getEmail() == email) {
					return base->getCliente(i);
				}
			}
			
			cerr << email << " NOT FOUND" << endl;
		}

		
	}
	else {
		string nif;

		cout << "Please input your NIF: ";
		cin >> nif;

		for (int i = 0; i < base->getClientesSize(); i++) {
			if (base->getCliente(i).getNIF() == nif) {
				return base->getCliente(i);
			}
		}

		cerr << nif << " NOT FOUND" << endl;
		exit(1);
	}
}

void clientPage(Cliente cliente, Base* b) {
	int option;

	cout << "Options (...)\n\n";
	cout << "1 - Order\n2 - Change email\n3 - Change address\n";
	cin >> option;

	string email;
	string morada;

	switch(option){
	case 1:
		cliente.encomenda(b);
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


