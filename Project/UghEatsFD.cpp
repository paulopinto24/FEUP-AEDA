
#include "UghEatsFD.h"
#include "Utils.h"
#include "Exceptions.h"

using namespace std;

UghEatsFD::UghEatsFD()
{
	
}

Base &UghEatsFD::getBase(int i) {
	return bases.at(i);
}


void UghEatsFD::addBase(Base b) {
	bases.push_back(b);
}

void UghEatsFD::getProfit() {
	cout << "Choose an option: " << endl;
	cout << "1 - See profit by Base" << endl;
	cout << "2 - See profit by Restaurante" << endl;
	cout << "3 - See profit by Cliente" << endl;
	cout << "4 - See profit over time" << endl;
	cout << "5 - Quit" << endl;

	while (1) {
		double res = 0.0;
		int option;
		cin >> option;
		if (option == 1) {
			for (unsigned int i = 0; i < bases.size(); i++) {
				Base b = bases.at(i);
				cout << b.getDistrito() << "   ";
				for (unsigned int j = 0; j < b.getEntregaStrS(); j++) {
					string e = b.getEntregaStr(j);
					vector<string> evec;
					evec = parseBySemiColon(e);
					res += stod(evec.at(2));
				}
				cout << res << endl;
				res = 0.0;
			}
		}
		if (option == 2) {
			vector<string> rest;
			vector<double> prof;

			for (unsigned int i = 0; i < bases.size(); i++) {
				Base b = bases.at(i);
				for (unsigned int j = 0; j < b.getEntregaStrS(); j++) {
					string e = b.getEntregaStr(j);
					vector<string> evec;
					evec = parseBySemiColon(e);
					bool found = false;
					for (unsigned int k = 0; k < rest.size(); k++) {
						if (rest.at(k) == evec.at(1)) {
							prof.at(k) += stod(evec.at(2));
							found = true;
							break;
						}
					}
					if (!found) {
						rest.push_back(evec.at(1));
						prof.push_back(stod(evec.at(2)));
					}
					found = false;
				}
			}



			for (unsigned int i = 0; i < rest.size(); i++) {
				cout << rest.at(i) << "   " << prof.at(i) << endl;
			}
		}
		if (option == 3) {
			vector<string> cli;
			vector<double> prof;

			for (unsigned int i = 0; i < bases.size(); i++) {
				Base b = bases.at(i);
				for (unsigned int j = 0; j < b.getEntregaStrS(); j++) {
					string e = b.getEntregaStr(j);
					vector<string> evec;
					evec = parseBySemiColon(e);
					bool found = false;
					for (unsigned int k = 0; k < cli.size(); k++) {
						if (cli.at(k) == evec.at(0)) {
							prof.at(k) += stod(evec.at(2));
							found = true;
							break;
						}
					}
					if (!found) {
						cli.push_back(evec.at(0));
						prof.push_back(stod(evec.at(2)));
					}
					found = false;
				}
			}

			for (unsigned int i = 0; i < cli.size(); i++) {
				cout << cli.at(i) << "   " << prof.at(i) << endl;
			}
		}

		if (option == 4) {
			string beg, end;
			cout << "Choose the time interval" << endl;
			cout << "Beginning(aaaa-mm-dd|hh:mm): ";
			cin >> beg;
			cout << "End(aaaa-mm-dd|hh:mm): ";
			cin >> end;

			for (unsigned int i = 0; i < bases.size(); i++) {
				Base b = bases.at(i);
				cout << b.getDistrito() << endl;
				for (unsigned int j = 0; j < b.getEntregaStrS(); j++) {
					string e = b.getEntregaStr(j);
					vector<string> evec;
					evec = parseBySemiColon(e);
					string eTime = evec.at(3);
					if (eTime >= beg && eTime <= end) {
						cout << e << endl;
					}
				}
			}




		}
		if (option == 5) {
			return;
		}
	}
}

void UghEatsFD::banUser() {
	int base;
	cout << "\nSelect base:\n1 - Porto\n2 - Lisboa\n3 - Faro\n";
	cin >> base;
	while (1) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "You have entered wrong input" << endl;
			cin >> base;
		}
		else {
			break;
		}
	}

	Base* b = &bases.at(base - 1);

	string nif;
	cout << "Insert NIF: ";
	cin >> nif;

	bool found = false;

	for (unsigned int i = 0; i < b->getClientesSize(); i++) {
		if (b->getCliente(i).getNIF() == nif) {
			found = true;
			b->addBlack(b->getCliente(i));
			b->deleteClient(b->getCliente(i));
			b->sortClientes();
			b->sortBlack();
		}
	}

	if (!found) {
		throw ClienteInexistente(nif);
	}
}




