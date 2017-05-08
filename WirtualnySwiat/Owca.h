#ifndef Owca_H
#define Owca_H
#include "Zwierze.h"

class Owca : public Zwierze {
public:
	Owca(int x, int y, Swiat* swiat);
	~Owca();
};
#endif