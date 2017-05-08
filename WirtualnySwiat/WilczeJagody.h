#ifndef WilczeJagody_H
#define WilczeJagody_H
#include "Roslina.h"
class WilczeJagody : public Roslina {
public:
	WilczeJagody(int x, int y, Swiat* swiat);
	~WilczeJagody();
	void kolizja(Organizm *o);
};
#endif