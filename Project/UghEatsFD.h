#pragma once

#ifndef UGHEATSFD_H
#define UGHEATSFD_H

#include "Base.h"


class UghEatsFD
{
private:
	vector<Base> bases;
public:
	UghEatsFD();
	Base& getBase(int);
	void addBase(Base b);
	void getProfit();
};




#endif // !_UGHEATSFD_H