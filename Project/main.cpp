#include "UghEatsFD.h"
#include "Utils.h"
#include "Menus.h"

using namespace std;

int main() {
	ifstream inFile;

	inFile.open("UghEatsFD.txt");

	/*cout << "hello\n";

	if (!(inFile.is_open())) {
		cout << "Error loading application." << endl;
		return -1;
	}

	inFile.close();

	ofstream outFile;

	outFile.open("UghEatsFD.txt");

	outFile << "Pila" << endl;

	outFile.close();*/








	UghEatsFD app;
	//loadApplication(app);
	welcomeMenu();
	int option{};
	string opt = openingMenu();

	if (opt == "1")
		option = 1;
	else if (opt == "2")
		option = 2;
	else if (opt == "3")
		option = 3;

	switch (option) {
	case 1:
		//clientPage();
		break;
	case 2:
		int base;
		cout << "Select base:\n1 - Porto\n2 - Lisboa\n3 - Faro\n";
		cin >> base;
		cin.clear();
		cin.ignore();

		while (base < 1 || base > 3) {
			cerr << "Please input a valid base:\n -> Porto(1)\n -> Lisboa(2)\n -> Faro(3)\n";
			cin >> base;
			cin.clear();
			cin.ignore();
		}
		
		//inscricao(app.getBase(base));
		break;
	case 3:
		cout << "Goodbye..." << endl;
		return 0;
	}

	return 0;
}
