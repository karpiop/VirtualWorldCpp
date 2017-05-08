#ifndef Antylopa_H
#define Antylopa_H
#include "Zwierze.h"

class Antylopa : public Zwierze {
public:
	Antylopa(int x, int y, Swiat* swiat);
	~Antylopa();
	void akcja();
	void kolizja(Organizm * napastnik);
};
#endif