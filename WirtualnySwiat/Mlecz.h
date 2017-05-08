#ifndef Mlecz_H
#define Mlecz_H
#include "Roslina.h"

class Mlecz : public Roslina {
public:
	Mlecz(int x, int y, Swiat* swiat);
	~Mlecz();
	void akcja();
};
#endif