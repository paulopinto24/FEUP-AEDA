
#include "UghEatsFD.h"

using namespace std;

UghEatsFD::UghEatsFD()
{
	
}

Base &UghEatsFD::getBase(int i) {
	return bases.at(i);
}


void UghEatsFD::addBase(Base b) {
	bases.push_back(b);
}

//bool Base::addRestaurante(Restaurante& r) {
//	for (int i = 0; i < restaurantes.size(); i++) {
//		if (restaurantes.at(i) == r) {
//			return false;
//		}
//		restaurantes.push_back(r);
//		return true;
//	}
//}



