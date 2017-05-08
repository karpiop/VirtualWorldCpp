#include "Trawa.h"
#include <iostream>

Trawa::Trawa(int x, int y, Swiat * swiat) {
	sila = 0;
	inicjatywa = 0;
	polozenieX = x;
	polozenieY = y;
	this->swiat = swiat;
	gatunek = 'T';
}

Trawa::~Trawa(){
	std::cout << "Destruktor trawy\n";
}
