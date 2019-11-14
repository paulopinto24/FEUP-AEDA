#pragma once

#include <string>

using namespace std;

class Veiculo
{
private:
	string marca;
	string tipo;
	string dataAquisicao;
public:
	Veiculo();
	Veiculo(string, string, string);
	string getTipo();
	string getMarca();
	string getDataAquisicao();
	void setMarca(string);
	void setTipo(string);
	void setDataAquisicao(string);
	bool operator == (const Veiculo& v) const;
};


