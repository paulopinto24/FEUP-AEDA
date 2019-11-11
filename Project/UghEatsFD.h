#pragma once

#ifndef UGHEATSFD_H
#define UGHEATSFD_H

#include <vector>
#include "Base.h"


class UghEatsFD
{
private:
	vector<Base> bases;
public:
	UghEatsFD();
	Base getBase(int);
};




#endif // !_UGHEATSFD_H