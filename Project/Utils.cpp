#include "Utils.h"

int loadApplication(UghEatsFD *p1) {
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
		if (cntLin < 3) {
			cntLin++;
			continue;
		}
		else {
			if (str == "---") {
				if (strVec.size() != 0) {
					Base b = parseBase(strVec);
					p1->addBase(b);
					strVec.clear();
					continue;
				}
				else {
					break;
				}
			}
			else {
				strVec.push_back(str);
				continue;
			}
		}
	}

	cout << "Application loaded." << endl;

	inFile.close();

	return 0;
}

int saveApplication(UghEatsFD *p1) {
	fstream outFile;
	outFile.open("UghEatsFD.txt", fstream::out);

	if (!(outFile.is_open())) {
		cout << "Error saving application." << endl;
		return 1;
	}

	outFile << "UghEats" << endl;
	outFile << "Bases:" << endl;

	for (int i = 0; i < 3; i++) {
		outFile << p1->getBase(i).getDistrito() << endl;
		outFile << p1->getBase(i).getMorada() << endl;
		outFile << p1->getBase(i).getConcelho() << endl;
		outFile << p1->getBase(i).getLocation().getLat() << ";" << p1->getBase(i).getLocation().getLon() << endl;
		outFile << p1->getBase(i).getGerente().getNome() << ";"
			<< p1->getBase(i).getGerente().getNIF() << ";"
			<< p1->getBase(i).getGerente().getDataNasc() << ";"
			<< p1->getBase(i).getGerente().getSalario() << ";"
			<< p1->getBase(i).getGerente().getFunc() << endl;
		for (int j = 0; j < p1->getBase(i).getClientesSize(); j++) {
			outFile << p1->getBase(i).getCliente(j).getNome() << ";"
				<< p1->getBase(i).getCliente(j).getNIF() << ";"
				<< p1->getBase(i).getCliente(j).getEmail() << ";"
				<< p1->getBase(i).getCliente(j).getMorada() << endl;
		}
		outFile << "---" << endl;
	}

	return 0;

}

vector<string> parseBySemiColon(string line) {
	string s1, s2;
	stringstream ss(line);
	vector<string> ret;

	while (getline(ss, s2, ';')) {
		ret.push_back(s2);
	}

	return ret;
}

Base parseBase(vector<string> vec) {
	
	string distrito;
	string morada;
	string concelho;

	distrito = vec.at(0);
	morada = vec.at(1);
	concelho = vec.at(2);

	vector<string> tmp;

	tmp = parseBySemiColon(vec.at(3));
	
	GPScoord location(stof(tmp.at(0)), stof(tmp.at(1)));

	tmp = parseBySemiColon(vec.at(4));
	//decidi considerar o gerente um administrativo com func de gerente
	Administrativo gerente(tmp.at(0), tmp.at(1), tmp.at(2), stod(tmp.at(3)), tmp.at(4));
	Base base(distrito, morada, concelho, location);
	base.addGerente(gerente);

	//ciclo que adiciona clientes a base que ja se encontrem no ficheiro
	for (int i = 5; i < vec.size(); i++) {
		tmp = parseBySemiColon(vec.at(i));
		Cliente cl(tmp.at(0), tmp.at(1), tmp.at(2), tmp.at(3));
		base.addCliente(cl);
	}

	return base;

}
