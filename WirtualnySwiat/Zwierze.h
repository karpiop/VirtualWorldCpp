#ifndef Zwierze_H
#define Zwierze_H
#include "Organizm.h"
class Zwierze : public Organizm {
public:
	void akcja();
	void kolizja(Organizm* napastnik);
	void wroc();
protected:
	int poprzedniePolozenieX;
	int poprzedniePolozenieY;
};
#endif