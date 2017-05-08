#include "Owca.h"
#include <iostream>

Owca::Owca(int x, int y, Swiat* swiat) {
	sila = 4;
	inicjatywa = 4;
	polozenieX = poprzedniePolozenieX = x;
	polozenieY = poprzedniePolozenieY = y;
	this->swiat = swiat;
	gatunek = 'O';
}

Owca::~Owca() {
	std::cout << "Destruktor owcy\n";
}