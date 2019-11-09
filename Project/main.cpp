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
	int option = openingMenu();

	switch (option) {
	case 1:
		//clientPage();
		break;
	case 2:
		//inscricao();
		break;
	case 3:
		cout << "Goodbye..." << endl;
		system("pause");
		return 0;
	}

	return 0;
}
