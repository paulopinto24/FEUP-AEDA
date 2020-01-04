
#include "UghEatsFD.h"
#include "Utils.h"

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
			for (int i = 0; i < bases.size(); i++) {
				Base b = bases.at(i);
				cout << b.getDistrito() << "   ";
				for (int j = 0; j < b.getEntregaStrS(); j++) {
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

			for (int i = 0; i < bases.size(); i++) {
				Base b = bases.at(i);
				for (int j = 0; j < b.getEntregaStrS(); j++) {
					string e = b.getEntregaStr(j);
					vector<string> evec;
					evec = parseBySemiColon(e);
					bool found = false;
					for (int k = 0; k < rest.size(); k++) {
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



			for (int i = 0; i < rest.size(); i++) {
				cout << rest.at(i) << "   " << prof.at(i) << endl;
			}
		}
		if (option == 3) {
			vector<string> cli;
			vector<double> prof;

			for (int i = 0; i < bases.size(); i++) {
				Base b = bases.at(i);
				for (int j = 0; j < b.getEntregaStrS(); j++) {
					string e = b.getEntregaStr(j);
					vector<string> evec;
					evec = parseBySemiColon(e);
					bool found = false;
					for (int k = 0; k < cli.size(); k++) {
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

			for (int i = 0; i < cli.size(); i++) {
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

			for (int i = 0; i < bases.size(); i++) {
				Base b = bases.at(i);
				cout << b.getDistrito() << endl;
				for (int j = 0; j < b.getEntregaStrS(); j++) {
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

	for (int i = 0; i < b->getClientesSize(); i++) {
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

//void UghEatsFD::insert_func(string fnif) {
//	funcionario_tab.insert(fnif);
//}

void UghEatsFD::show_func() {
	for (const auto& elem : func) {
		cout << elem.getNIF() << endl;
	}
}

int UghEatsFD::funcionario_tabS() {
	return funcionario_tab.size();
}

void UghEatsFD::ins_func(Funcionario f) {
	func.insert(f);
}

void UghEatsFD::check_func_records() {
	cout << "==========================================" << endl;
	cout << "================W. RECORDS================" << endl;
	cout << "==========================================" << endl;
	cout << "Choose one of the following options:" << endl;
	cout << "1 - Check all listings of Funcionarios" << endl;
	cout << "2 - Check all listings of current Funcionarios" << endl;
	cout << "3 - Check all listings of past Funcionarios" << endl;
	cout << "4 - Check all listings of Administradores (in development)" << endl;
	cout << "5 - Check all listings of Entregadores (in development)" << endl;
	cout << "6 - Quit" << endl;
	
	while (1) {
		cout << "-> ";

		int option;
		cin >> option;


		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "You have entered wrong input" << endl;
			continue;
		}

		if (option != 1 && option != 2 && option != 3 && option != 4 && option != 5 && option != 6) {
			cout << "Please choose a valid option" << endl;
			continue;
		}

		if(option == 1){
			cout << "=========================================================================================" << endl;
			cout << "NAME================NIF==========BIRTHDATE=====SALARY====CURRENT WORKER=======TYPE=======" << endl;

			for (auto itr = func.begin(); itr != func.end(); ++itr) {

				size_t size1 = 20 - itr->getNome().size();
				string space1(size1, ' ');

				size_t size2 = 13 - itr->getNIF().size();
				string space2(size2, ' ');

				size_t size3 = 14 - itr->getDataNasc().size();
				string space3(size3, ' ');

				size_t size4 = 10 - itr->getsSalario().size();
				string space4(size4, ' ');

				size_t size5 = 21 - itr->getAtual().size();
				string space5(size5, ' ');

				cout << itr->getNome() << space1 << itr->getNIF() << space2 << itr->getDataNasc() <<
					space3 << itr->getsSalario() << space4  << itr->getAtual()  << space5 << itr->getAdmin() << endl;
			}
		}
		else if (option == 2) {
			cout << "=======================================================================" << endl;
			cout << "NAME================NIF==========BIRTHDATE=====SALARY====TYPE==========" << endl;

			for (auto itr = func.begin(); itr != func.end(); ++itr) {
				if (itr->getAtual() == "Y") {
					size_t size1 = 20 - itr->getNome().size();
					string space1(size1, ' ');

					size_t size2 = 13 - itr->getNIF().size();
					string space2(size2, ' ');

					size_t size3 = 14 - itr->getDataNasc().size();
					string space3(size3, ' ');

					size_t size5 = 10 - itr->getsSalario().size();
					string space5(size5, ' ');

					cout << itr->getNome() << space1 << itr->getNIF() << space2 << itr->getDataNasc() <<
						space3 << itr->getsSalario() << space5 << itr->getAdmin() << endl;
				}
			}
		}
		else if (option == 3) {
			cout << "=======================================================================" << endl;
			cout << "NAME================NIF==========BIRTHDATE=====SALARY====TYPE==========" << endl;

			for (auto itr = func.begin(); itr != func.end(); ++itr) {
				if (itr->getAtual() == "N") {
					size_t size1 = 20 - itr->getNome().size();
					string space1(size1, ' ');

					size_t size2 = 13 - itr->getNIF().size();
					string space2(size2, ' ');

					size_t size3 = 14 - itr->getDataNasc().size();
					string space3(size3, ' ');

					size_t size5 = 10 - itr->getsSalario().size();
					string space5(size5, ' ');

					cout << itr->getNome() << space1 << itr->getNIF() << space2 << itr->getDataNasc() <<
						space3 << itr->getsSalario() << space5 << itr->getAdmin() << endl;
				}
			}
		}
		else if (option == 4) {
			cout << "==============================================================================" << endl;
			cout << "NAME================NIF==========BIRTHDATE=====SALARY====CURRENT WORKER=======" << endl;

			for (auto itr = func.begin(); itr != func.end(); ++itr) {
				if (itr->getAdmin() == "ADMIN") {
					size_t size1 = 20 - itr->getNome().size();
					string space1(size1, ' ');

					size_t size2 = 13 - itr->getNIF().size();
					string space2(size2, ' ');

					size_t size3 = 14 - itr->getDataNasc().size();
					string space3(size3, ' ');

					size_t size4 = 10 - itr->getsSalario().size();
					string space4(size4, ' ');

					cout << itr->getNome() << space1 << itr->getNIF() << space2 << itr->getDataNasc() <<
						space3 << itr->getsSalario() << space4 << itr->getAtual() << endl;
				}
			}
		}
		else if (option == 5) {
			cout << "==============================================================================" << endl;
			cout << "NAME================NIF==========BIRTHDATE=====SALARY====CURRENT WORKER=======" << endl;

			for (auto itr = func.begin(); itr != func.end(); ++itr) {
				if (itr->getAdmin() == "ENTREG") {
					size_t size1 = 20 - itr->getNome().size();
					string space1(size1, ' ');

					size_t size2 = 13 - itr->getNIF().size();
					string space2(size2, ' ');

					size_t size3 = 14 - itr->getDataNasc().size();
					string space3(size3, ' ');

					size_t size4 = 10 - itr->getsSalario().size();
					string space4(size4, ' ');

					cout << itr->getNome() << space1 << itr->getNIF() << space2 << itr->getDataNasc() <<
						space3 << itr->getsSalario() << space4 << itr->getAtual() << endl;
				}
			}
		}
		else if (option == 6) {
			break;
		}
		
	}


}




