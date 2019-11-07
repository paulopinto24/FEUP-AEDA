
#include "UghEatsFD.h"


UghEatsFD::UghEatsFD()
{
	Base Porto("Porto", "some", "random", 1, 2, 3, 'N');
	Base Lisboa("Lisboa", "some", "random", 4, 5, 6, 'O');
	Base Faro("Faro", "some", "random", 7, 8, 9, 'S');

	bases.push_back(Porto);
	bases.push_back(Lisboa);
	bases.push_back(Faro);
}