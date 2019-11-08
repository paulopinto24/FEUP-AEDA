#include "Menus.h"
#include "Utils.h"
#include "Base.h"
#include <iostream>
#include <string>

using namespace std;

template <class B>
int main() {
	UghEatsFD app;
	loadApplication(app);
	welcomeMenu();
	int option = openingMenu();

	switch (option) {
	case 1:
		//clientPage();
		break;
	case 2:
		inscricao();
		break;
	case 3:
		cout << "Goodbye..." << endl;
		system("pause");
		return 0;
	}

	return 0;
}
