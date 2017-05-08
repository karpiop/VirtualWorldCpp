#include "Antylopa.h"
#include <iostream>
#include "Swiat.h"

Antylopa::Antylopa(int x, int y, Swiat* swiat) {
	sila = 4;
	inicjatywa = 4;
	polozenieX = poprzedniePolozenieX = x;
	polozenieY = poprzedniePolozenieY = y;
	this->swiat = swiat;
	gatunek = 'A';
}

Antylopa::~Antylopa() {
	std::cout << "Destrukor antylopy\n";
}

void Antylopa::akcja() {
	Zwierze::akcja();
	Zwierze::akcja();
	wiek--;
}

void Antylopa::kolizja(Organizm * napastnik) {
	if (gatunek!=napastnik->getGatunek() && rand() % 2 && (polozenieX > 0 && swiat->jestPustePole(polozenieX - 1, polozenieY)
		|| polozenieX - 1 < swiat->getSzerokosc() && swiat->jestPustePole(polozenieX + 1, polozenieY)
		|| polozenieY > 0 && swiat->jestPustePole(polozenieX, polozenieY - 1)
		|| polozenieY - 1 < swiat->getWysokosc() && swiat->jestPustePole(polozenieX, polozenieY + 1))) {
		int x, y;
		do {
			x = polozenieX;
			y = polozenieY;
			if (rand() % 2) {
				x += rand() % 2 * 2 - 1;
			}
			else {
				y += rand() % 2 * 2 - 1;
			}
		} while (!(x >= 0 && x < swiat->getSzerokosc() && y >= 0 && y < swiat->getWysokosc()));
		polozenieX = x;
		polozenieY = y;
		std::string log;
		log += "tura ";
		log += std::to_string(swiat->getWiek());
		log += ":\tA czmycha przed ";
		log += napastnik->getGatunek();
		swiat->dodajLog(log);
	}
	else {
		Zwierze::kolizja(napastnik);
	}
}
