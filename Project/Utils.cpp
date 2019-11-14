#include "Utils.h"

int loadApplication(UghEatsFD* p1) {
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

int saveApplication(UghEatsFD* p1) {
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
		outFile << p1->getBase(i).getConcelho() << ";" << p1->getBase(i).getMorada() << endl;
		outFile << p1->getBase(i).getLocation().getLat() << ";" << p1->getBase(i).getLocation().getLon() << endl;
		outFile << p1->getBase(i).getDistrito() << "_res.txt" << endl;
		outFile << p1->getBase(i).getDistrito() << "_func.txt" << endl;
		outFile << p1->getBase(i).getDistrito() << "_cli.txt" << endl;
		outFile << p1->getBase(i).getDistrito() << "_black.txt" << endl;
		outFile << p1->getBase(i).getDistrito() << "_front.txt" << endl;

		fstream outRes;
		string s = p1->getBase(i).getDistrito() + "_res.txt";
		outRes.open(s, fstream::out);

		if (!(outRes.is_open())) {
			cout << "Error saving application." << endl;
			return 1;
		}

		for (int j = 0; j < p1->getBase(i).getRestaurantesS(); j++) {
			outRes << p1->getBase(i).getRes(j).getNome() << endl;
			outRes << p1->getBase(i).getRes(j).getConcelho() << ";" << p1->getBase(i).getRes(j).getMorada() << endl;
			outRes << p1->getBase(i).getRes(j).getAvailable() << endl;
			for (int k = 0; k < p1->getBase(i).getRes(j).getTpCulS(); k++) {
				if (k == p1->getBase(i).getRes(j).getTpCulS() - 1) {
					outRes << p1->getBase(i).getRes(j).getTpCul(k) << endl;
					break;
				}
				outRes << p1->getBase(i).getRes(j).getTpCul(k) << ";";
			}
			for (int k = 0; k < p1->getBase(i).getRes(j).getProdS(); k++) {
				outRes << p1->getBase(i).getRes(j).getProd(k).getNome() << ";"
					<< p1->getBase(i).getRes(j).getProd(k).getTipo() << ";"
					<< p1->getBase(i).getRes(j).getProd(k).getPreco() << endl;
			}

			outRes << "---" << endl;
		}

		outRes.close();

		fstream outFunc;
		s = p1->getBase(i).getDistrito() + "_func.txt";
		outFunc.open(s, fstream::out);

		if (!(outFunc.is_open())) {
			cout << "Error saving application." << endl;
			return 1;
		}

		for (int j = 0; j < p1->getBase(i).getAdminsS(); j++) {
			outFunc << p1->getBase(i).getAdmin(j).getNome() << ";"
				<< p1->getBase(i).getAdmin(j).getNIF() << ";"
				<< p1->getBase(i).getAdmin(j).getDataNasc() << ";"
				<< p1->getBase(i).getAdmin(j).getSalario() << ";"
				<< p1->getBase(i).getAdmin(j).getFunc() << endl;
		}

		outFunc << "---" << endl;

		for (int j = 0; j < p1->getBase(i).getEntregsS(); j++) {
			outFunc << p1->getBase(i).getEntreg(j).getNome() << ";"
				<< p1->getBase(i).getEntreg(j).getNIF() << ";"
				<< p1->getBase(i).getEntreg(j).getDataNasc() << ";"
				<< p1->getBase(i).getEntreg(j).getSalario() << ";"
				<< p1->getBase(i).getEntreg(j).getVeiculo().getMarca() << "/"
				<< p1->getBase(i).getEntreg(j).getVeiculo().getTipo() << "/"
				<< p1->getBase(i).getEntreg(j).getVeiculo().getDataAquisicao() << ";"
				<< p1->getBase(i).getEntreg(j).getComissao() << endl;
		}

		outFunc.close();

		fstream outClie;
		s = p1->getBase(i).getDistrito() + "_cli.txt";
		outClie.open(s, fstream::out);

		if (!(outClie.is_open())) {
			cout << "Error saving application." << endl;
			return 1;
		}

		for (int j = 0; j < p1->getBase(i).getClientesSize(); j++) {
			outClie << p1->getBase(i).getCliente(j).getNome() << ";"
				<< p1->getBase(i).getCliente(j).getNIF() << ";"
				<< p1->getBase(i).getCliente(j).getEmail() << ";"
				<< p1->getBase(i).getCliente(j).getConcelho() << ";"
				<< p1->getBase(i).getCliente(j).getMorada() << endl;

		}

		outClie.close();

		fstream outB;
		s = p1->getBase(i).getDistrito() + "_black.txt";
		outB.open(s, fstream::out);

		if (!(outB.is_open())) {
			cout << "Error saving application." << endl;
			return 1;
		}

		for (int j = 0; j < p1->getBase(i).getBlackS(); j++) {
			outB << p1->getBase(i).getBlack(j).getNome() << ";"
				<< p1->getBase(i).getBlack(j).getNIF() << ";"
				<< p1->getBase(i).getBlack(j).getEmail() << ";"
				<< p1->getBase(i).getBlack(j).getConcelho() << ";"
				<< p1->getBase(i).getBlack(j).getMorada() << endl;
		}

		outB.close();

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

vector<string> parseBySlash(string line) {
	string s1, s2;
	stringstream ss(line);
	vector<string> ret;

	while (getline(ss, s2, '/')) {
		ret.push_back(s2);
	}

	return ret;
}

Base parseBase(vector<string> vec) {

	string distrito;
	string morada;
	string concelho;

	distrito = vec.at(0); //distrito

	vector<string> tmp;
	tmp = parseBySemiColon(vec.at(1)); //morada

	concelho = vec.at(0);
	morada = tmp.at(1);

	tmp = parseBySemiColon(vec.at(2)); //coord GPS

	GPScoord location(stof(tmp.at(0)), stof(tmp.at(1)));

	Base b(distrito, morada, concelho, location);

	//abre o ficheiro de texto com os restaurantes da base
	fstream inRes;
	inRes.open(vec.at(3), fstream::in);

	if (!(inRes.is_open())) {
		cout << "Error loading restaurants." << endl;
		exit(-1);
	}

	string strg;
	vector<string> strgVec;
	vector<string> tipsCul;
	vector<Produto> prods;
	int cnt = 0;
	while (getline(inRes, strg)) {
		cnt++;
		if (strg == "---") {
			tmp = parseBySemiColon(strgVec.at(1));
			Restaurante res(strgVec.at(0), tmp.at(1), tmp.at(0), tipsCul, stoi(strgVec.at(2)));
			for (int i = 0; i < prods.size(); i++) {
				res.addProduto(prods.at(i));
			}
			b.addRestaurante(res);
			strgVec.clear();
			tipsCul.clear();
			prods.clear();
			cnt = 0;
			continue;
		}
		else {
			if (cnt < 4) {
				strgVec.push_back(strg);
			}
			else if (cnt == 4) {
				tipsCul = parseBySemiColon(strg);
			}  
			else if (cnt > 4) {
				tmp = parseBySemiColon(strg);
				Produto prod(tmp.at(0), tmp.at(1), stod(tmp.at(2)));
				prods.push_back(prod);
			}
		}

	}

	inRes.close();

	//abre o ficheiro de texto com os funcionarios da base
	fstream inFunc;
	inFunc.open(vec.at(4), fstream::in);

	if (!(inFunc.is_open())) {
		cout << "Error loading employees." << endl;
		exit(-1);
	}

	bool trig = false;
	while (getline(inFunc, strg)) {
		if (strg == "---") {
			trig = true;
			continue;
		}

		if (trig) {
			tmp = parseBySemiColon(strg);
			vector<string> veicInf = parseBySlash(tmp.at(4));
			Veiculo v(veicInf.at(0), veicInf.at(1), veicInf.at(2));
			Entregador e(tmp.at(0), tmp.at(1), tmp.at(2), stod(tmp.at(3)), v);
			e.setCom(stod(tmp.at(5)));
			b.addEntregador(e);
		}
		else {
			tmp = parseBySemiColon(strg);
			Administrativo admin(tmp.at(0), tmp.at(1), tmp.at(2), stod(tmp.at(3)), tmp.at(4));
			b.addAdmin(admin);
		}
	}

	inFunc.close();

	//abre o ficheiro de texto com os clientes da base
	fstream inClient;
	inClient.open(vec.at(5), fstream::in);

	if (!(inClient.is_open())) {
		cout << "Error loading clients." << endl;
		exit(-1);
	}


	while (getline(inClient, strg)) {
		tmp = parseBySemiColon(strg);
		Cliente c(tmp.at(0), tmp.at(1), tmp.at(2), tmp.at(4), tmp.at(3), distrito);
		b.addCliente(c);
	}

	inClient.close();

	//abre o ficheiro de texto com a lista negra
	fstream inB;
	inB.open(vec.at(6), fstream::in);

	if (!(inB.is_open())) {
		cout << "Error loading black list." << endl;
		exit(-1);
	}


	while (getline(inB, strg)) {
		tmp = parseBySemiColon(strg);
		Cliente c(tmp.at(0), tmp.at(1), tmp.at(2), tmp.at(4), tmp.at(3), distrito);
		b.addBlack(c);
	}

	inB.close();

	//abre o ficheiro de texto com os concelhos fronteira
	fstream inFront;
	inFront.open(vec.at(7), fstream::in);

	if (!(inFront.is_open())) {
		cout << "Error loading boredering settlements." << endl;
		exit(-1);
	}


	while (getline(inFront, strg)) {
		b.addFront(strg);
	}

	inFront.close();

	cout << "Done." << endl;

	return b;

}
