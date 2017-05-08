#include "Zolw.h"
#include <iostream>
#include "Swiat.h"

Zolw::Zolw(int x, int y, Swiat* swiat) {
	sila = 2;
	inicjatywa = 1;
	polozenieX = poprzedniePolozenieX = x;
	polozenieY = poprzedniePolozenieY = y;
	this->swiat = swiat;
	gatunek = 'Z';
}

Zolw::~Zolw() {
	std::cout << "Destruktor zowia\n";
}

void Zolw::akcja() {
	if (rand() % 4) {
		wiek++;
	}
	else {
		Zwierze::akcja();
	}
}

void Zolw::kolizja(Organizm * napastnik) {
	if (napastnik->getGatunek() != gatunek && napastnik->getSila() < 5) {
		((Zwierze*)napastnik)->wroc();
		std::string log = "tura " + std::to_string(swiat->getWiek()) + ":\t";
		log += "Z odgania ";
		log += napastnik->getGatunek();
		swiat->dodajLog(log);
	}
	else {
		Zwierze::kolizja(napastnik);
	}
}
