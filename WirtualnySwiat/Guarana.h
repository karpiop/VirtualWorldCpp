#ifndef Guarana_H
#define Guarana_H
#include "Roslina.h"

class Guarana : public Roslina {
public:
	Guarana(int x, int y, Swiat* swiat);
	~Guarana();
	void kolizja(Organizm *o);
};
#endif