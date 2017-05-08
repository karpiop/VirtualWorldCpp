#include "Mlecz.h"
#include <iostream>
#include "Swiat.h"

Mlecz::Mlecz(int x, int y, Swiat * swiat) {
	sila = 0;
	inicjatywa = 0;
	polozenieX = x;
	polozenieY = y;
	this->swiat = swiat;
	gatunek = 'M';
}

Mlecz::~Mlecz() {
	std::cout << "Destruktor mlecza\n";
}

void Mlecz::akcja() {
	Roslina::akcja();
	Roslina::akcja();
	wiek--;
}
