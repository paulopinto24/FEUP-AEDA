#include "Base.h"
#include "GPScoord.h"



Base::Base(const string d, const string m, const string c, GPScoord &gpscoord, Pessoa &g) {
	this->distrito = d;
	this->morada = m;
	this->concelho = c;
	gps = gpscoord;
	gerente = g;
}