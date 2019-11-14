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
	welcomeMenu();
	int option{};
	string opt = openingMenu();

	if (opt == "1")
		option = 1;
	else if (opt == "2")
		option = 2;
	else if (opt == "3")
		option = 3;


	Base* baseClient = &app.getBase(selectBase());

	while (1) {
		switch (option) {
		case 1:
			clientPage(entrar(baseClient), baseClient);
			cin >> option;
			break;
		case 2:
			if (!inscricao(app.getBase(selectBase()))) {
				cerr << "Error processing sign in...\n";
				return 1;
			}
			break;
		case 3:
			cout << "Goodbye..." << endl;
			saveApplication(&app);
			return 0;
		}
	}

	return -1;
}
