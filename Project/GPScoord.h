#ifndef GPScoord_H
#define GPScoord_H



class GPScoord
{
private:
	float latitude;
	float longitude;
public:
	GPScoord();
	GPScoord(float lat, float lon);
	float getLat();
	float getLon();
};


#endif // !GPScoord_H

