#pragma once

#include <iostream>
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

void openingMenu() {
	cout << "1 - Sign in" << endl;
	cout << "2 - Sign up" << endl;
	cout << "3 - Quit" << endl;
	cout << endl;

	int option;

	cin >> option;
	/*
	switch (option) {
	case 1:
		
	}*/
}

bool validEmail(string const& email) {
	string gmail = "@gmail.com";
	string hotmail = "@hotmail.com";
	string feup = "@fe.up.pt";

	if (email.length() >= gmail.length()) {
		if (email.compare(email.length() - gmail.length(), gmail.length(), gmail))
			return true;
	}
	if (email.length() >= hotmail.length()) {
		if (email.compare(email.length() - hotmail.length(), hotmail.length(), hotmail))
			return true;
	}
	if (email.length() >= feup.length()) {
		if (email.compare(email.length() - feup.length(), feup.length(), feup))
			return true;
	}
	return false;
}

bool inscricao() {
	int base;
	Base b;
	cout << "Select base:\n -> Porto(1)\n -> Lisboa(2)\n -> Faro(3)";
	cin >> base;

	while (base < 1 || base > 3) {
		cerr << "Please input a valid base:\n -> Porto(1)\n -> Lisboa(2)\n -> Faro(3)";
		cin.clear();
		cin.ignore();
		cin >> base;
	}

	/*
	switch (base) {
	case 1:
		b = Porto;
	case 2:
		b = Lisboa;
	case 3:
		b = Faro;
	}*/

	string nome;
	string morada;
	int inif;
	string email;

	cout << "Name : ";
	getline(cin, nome);

	cout << endl << "Email : ";
	cin >> email;
	while (!validEmail(email)) {
		cerr << "Please insert a valid email: ";
		cin.clear();
		cin.ignore();
		cin >> email;
	}

	cout << endl << "Morada : ";
	getline(cin, morada);

	cout << endl << "NIF : ";
	cin >> inif;
	string nif = to_string(inif);
	while (nif.length() != 9) {
		cerr << "Please insert a valid NIF : ";
		cin.clear();
		cin.ignore();
		cin >> inif;
	}

	cout << endl << endl;

	//b.addCliente(Cliente(nome, nif, email, morada));
}


