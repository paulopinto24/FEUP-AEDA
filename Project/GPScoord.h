#ifndef GPScoord_H
#define GPScoord_H

class GPScoord
{
private:
	int degrees;
	int minutes;
	float seconds;
	char direction;
public:
	//GPScoord();
	GPScoord(int d, int m, float s, char dir);
};


#endif // !GPScoord_H

