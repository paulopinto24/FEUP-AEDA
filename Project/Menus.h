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

bool inscricao(Base &b) {
	
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
			cerr << "Concelho not valid!!!" << endl;
		}
		else break;
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

	Cliente c = Cliente(nome, nif, email, morada, concelho, b.getDistrito());

	cout << c.getNome() << endl << c.getNIF() << endl << c.getEmail() << endl;

	if (!b.addCliente(c)) {
		cout << "Failure in creating account..." << endl;
	}

	return true; 
}

Cliente entrar(Base base) { 
	int option;
	cout << "\nHow do you want do sign in?\n1 - Sign in email\n2 - Sign in with NIF\n";
	cin >> option;
	cin.clear();
	cin.ignore();

	while (option < 1 || option > 2) {
		cerr << "Please input a valid option:\n1 - Sign up email\n2- Sign up with NIF\n";
		cin >> option;
		cin.clear();
		cin.ignore();
	}

	if (option == 1) {
		string email;

		cout << "Please input your email: ";
		cin >> email;

		for (int i = 0; i < base.getClientesSize(); i++) {
			if (base.getCliente(i).getEmail() == email) {
				return base.getCliente(i);
			}
		}

		cerr << email << " NOT FOUND" << endl;
		exit(1);
	}
	else {
		string nif;

		cout << "Please input your NIF: ";
		cin >> nif;

		for (int i = 0; i < base.getClientesSize(); i++) {
			if (base.getCliente(i).getNIF() == nif) {
				return base.getCliente(i);
			}
		}

		cerr << nif << " NOT FOUND" << endl;
		exit(1);
	}
}

int clientPage(Cliente cliente, Base &b) {
	int option;
	string email;
	string morada;
	string concelho;

	//cliente.encomenda(base);

	while (1) {

		cout << "\nOptions (...)\n";
		cout << "\n1 - Order\n2 - Check account\n3 - Change email\n4 - Change address\n0 - Log out\n";
		cin >> option;
		cin.clear();
		cin.ignore();

		switch (option) {
		case 1:
			//cliente.encomenda();
			continue;
		case 2:
			cout << "Nome : " << cliente.getNome() << endl;
			cout << "Email : " << cliente.getEmail() << endl;
			cout << "Morada : " << cliente.getMorada() << " ; " << cliente.getConcelho() << endl;
			cout << "NIF : " << cliente.getNIF() << endl;
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
					cerr << "Concelho not valid!!!" << endl;
				}
				else break;
			}
			cout << "Morada : ";
			getline(cin, morada);
			b.deleteClient(cliente);
			cliente.setConcelho(concelho);
			cliente.setMorada(morada);
			b.addCliente(cliente);
			continue;
		case 0:
			return 0;
		default:
			return 1;
		}
	}
}


