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

	while (1) {

		welcomeMenu();
		int option{};
		string opt = openingMenu();

		if (opt == "1")
			option = 1;
		else if (opt == "2")
			option = 2;
		else if (opt == "3")
			option = 3;

		if (option == 1) {
			Base &base = app.getBase(selectBase());
			clientPage(entrar(base), base);
			continue;
		}
		else if (option == 2) {

			Base& base = app.getBase(selectBase());
			if (!inscricao(base)) {
				cerr << "Error processing sign in...\n";
				return 1;
			}
			
			clientPage(base.getCliente(base.getClientesSize() - 1), base);
			continue;
		}
		else if (option == 3) {

			cout << "Goodbye..." << endl;
			saveApplication(&app);
			break;

		}
		else return -1;

		return 0;
	}

	return 0;
}
