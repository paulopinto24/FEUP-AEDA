#ifndef BASE_H
#define BASE_H

#include <string>
#include "GPScoord.h"

using namespace std;

class Base : public GPScoord
{
private:
	string distrito;
	string morada;
	string concelho;
	GPScoord gps;

public:
	Base(string d, string m, string c, int d, int m, float s, char dir);
};









#endif // !BASE_H