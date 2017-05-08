#include "Guarana.h"
#include <iostream>

Guarana::Guarana(int x, int y, Swiat * swiat) {
	sila = 0;
	inicjatywa = 0;
	polozenieX = x;
	polozenieY = y;
	this->swiat = swiat;
	gatunek = 'G';
}

Guarana::~Guarana() {
	std::cout << "Destruktor guarany\n";
}

void Guarana::kolizja(Organizm * o) {
	o->setSila(o->getSila() + 3);
	Roslina::kolizja(o);
}
