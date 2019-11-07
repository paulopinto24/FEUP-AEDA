#include "Menus.h"
#include "Utils.h"
#include "Base.h"
#include <iostream>
#include <string>
using namespace std;


int main() {
	UghEatsFD app;
	loadApplication(app);
	welcomeMenu();
	openingMenu();



	system("pause");

	return 0;
}
