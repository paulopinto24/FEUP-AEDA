#pragma once

#ifndef UGHEATSFD_H
#define UGHEATSFD_H

#include "Base.h"

class ClienteInexistente {
public:
	string nif;
	ClienteInexistente(string n) {
		nif = n;
	}
	string getNif() {
		return nif;
	}
};

class UghEatsFD
{
private:
	vector<Base> bases;
public:
	UghEatsFD();
	Base& getBase(int);
	void addBase(Base b);
	void getProfit();
	void banUser();
};




#endif // !_UGHEATSFD_H