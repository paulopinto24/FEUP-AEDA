#include "GPScoord.h"

GPScoord::GPScoord() {};

GPScoord::GPScoord(float lat, float lon)
{
	latitude = lat;
	longitude = lon;
}

float GPScoord::getLat() {
	return latitude;
}

float GPScoord::getLon() {
	return longitude;
}

