#include "Wilk.h"
#include <iostream>

Wilk::Wilk(int x, int y, Swiat* swiat) {
	sila = 9;
	inicjatywa = 5;
	polozenieX = poprzedniePolozenieX = x;
	polozenieY = poprzedniePolozenieY = y;
	this->swiat = swiat;
	gatunek = 'W';
}

Wilk::~Wilk() {
	std::cout << "Destrukor wilka\n";
}
