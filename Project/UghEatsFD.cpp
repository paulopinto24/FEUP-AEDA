
#include "UghEatsFD.h"

using namespace std;

UghEatsFD::UghEatsFD()
{
	
}

Base UghEatsFD::getBase(int i) {
	return bases.at(i);
}

void UghEatsFD::addBase(Base b) {
	bases.push_back(b);
}



