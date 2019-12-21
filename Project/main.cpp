#include "UghEatsFD.h"
#include "Utils.h"
#include "Menus.h"

using namespace std;


int selectBase() {
	int base;
	cout << "\nSelect base:\n1 - Porto\n2 - Lisboa\n3 - Faro\n";
	cin >> base;
	cin.clear();
	cin.ignore();

	while (base < 1 || base > 3) {
		cerr << "Please input a valid base:\n -> Porto(1)\n -> Lisboa(2)\n -> Faro(3)\n";
		cin >> base;
		cin.clear();
		cin.ignore();
	}

	return base - 1;
}

int main() {
	UghEatsFD app;
	if (loadApplication(&app)) {
		cout << "Error loading application." << endl;
		return 1;
	}
	while(1){
	welcomeMenu();
	int option{};
	string opt = openingMenu();

	if (opt == "1")
		option = 1;
	else if (opt == "2")
		option = 2;
	else if (opt == "3")
		option = 3;
	else if (opt == "AdminAEDA1920")
		option = 4;

	
		if (option == 1) {
			Base &base = app.getBase(selectBase());

			try {
				clientPage(entrar(base), base);
			}
			catch (NifInexistente(nif)) {
				cout << "Exception caught: account " << nif.getInfo() << " does not exist" << endl << endl;
			}
			catch (BannedAccount(nif)) {
				cout << "Exception caught: account " << nif.getInfo() << " has been banned" << endl << endl;
			}

			continue;
		}
		else if (option == 2) {
			Base& base = app.getBase(selectBase());

			try {
				if (!inscricao(base)) {
					cerr << "Error processing sign in...\n";
					continue;
				}
			}
			catch (NifEmUso(nif)) {
				cout << "Exception caught: " << nif.getInfo() << " already in use" << endl;
				continue;
			}
			catch (EmailEmUso(email)) {
				cout << "Exception caught: " << email.getInfo() << " already in use" << endl;
				continue;
			}

			clientPage(base.getCliente(base.getClientesSize() - 1), base);
			base.sortClientes();
			continue;
		}
		else if (option == 3) {

			cout << "Goodbye..." << endl;
			saveApplication(&app);
			break;

		}
		else if (option == 4) {
			developerMenu(&app);
			continue;
		}
		else return -1;

	}

	return 0;
}
