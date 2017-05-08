#ifndef Lis_H
#define Lis_H
#include "Zwierze.h"

class Lis : public Zwierze {
public:
	Lis(int x, int y, Swiat* swiat);
	~Lis();
	void akcja();
};
#endif