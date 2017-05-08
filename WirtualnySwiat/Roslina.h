#ifndef Roslina_H
#define Roslina_H
#include "Organizm.h"
class Roslina : public Organizm {
public:
	void akcja();
	void kolizja(Organizm* o);
private:
};
#endif