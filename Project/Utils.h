#pragma once

#include "UghEatsFD.h"
#include <iostream>
#include <fstream>
using namespace std;

int loadApplication(UghEatsFD p1) {
	fstream inFile;
	inFile.open("UghEatsFD.txt", fstream::in);

	if (!(inFile.is_open())) {
		cout << "Error loading application." << endl;
		return 1;
	}

	vector<string> strVec;
	string str;
	int cntLin = 1;

	cout << "Loading application..." << endl;

	while (getline(inFile, str)) {
		if (cntLin < 4) {
			cntLin++;
			continue;
		}
		else {
			if (str == "---") {
				//process inf collected in strVec
				strVec.clear();
				continue;
			}
			else {
				strVec.push_back(str);
				continue;
			}
		}
	}

	inFile.close();

}


