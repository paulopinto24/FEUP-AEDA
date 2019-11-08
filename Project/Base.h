#ifndef BASE_H
#define BASE_H

#include <string>
#include "GPScoord.h"
#include "Pessoa.h"
#include <vector>

using namespace std;

template <class G, class P, class C>
class Base 
{
private:
	string distrito;
	string morada;
	string concelho;
	G gps;
	P gerente;
	vector<C> clientes;

public:
	Base();
	Base(const string d, const string m, const string c, G& gpscoord, P &g);
	bool addCliente(C);
};









#endif // !BASE_H