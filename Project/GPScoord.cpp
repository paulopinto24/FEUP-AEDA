#include "GPScoord.h"

GPScoord::GPScoord() {};

GPScoord::GPScoord(int d, int m, float s, char dir)
{
	degrees = d;
	minutes = m;
	seconds = s;
	direction = dir;
};