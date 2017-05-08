#ifndef Zolw_H
#define Zolw_H
#include "Zwierze.h"

class Zolw : public Zwierze {
public:
	Zolw(int x, int y, Swiat* swiat);
	~Zolw();
	void akcja();
	void kolizja(Organizm * napastnik);
};
#endif