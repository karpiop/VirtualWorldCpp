#include "Lis.h"
#include <iostream>
#include "Swiat.h"

Lis::Lis(int x, int y, Swiat* swiat) {
	sila = 3;
	inicjatywa = 7;
	polozenieX = poprzedniePolozenieX = x;
	polozenieY = poprzedniePolozenieY = y;
	this->swiat = swiat;
	gatunek = 'L';
}

Lis::~Lis() {
	std::cout << "Destruktor lisa\n";
}

void Lis::akcja() {
	int x, y;
	bool mozeSieRuszyc = false;
	for (int i = 0; i < 4; i++) {
		x = polozenieX;
		y = polozenieY;
		switch (i) {
		case 0:
			x++;
			break;
		case 1:
			x--;
			break;
		case 2:
			y++;
			break;
		case 3:
			y--;
			break;
		}
		if ((x >= 0 && x < swiat->getSzerokosc() && y >= 0 && y < swiat->getWysokosc() && (swiat->getOrganizmPoPolozeniu(x, y) == nullptr || swiat->getOrganizmPoPolozeniu(x, y)->getSila() <= sila))) {
			mozeSieRuszyc = true;
			break;
		}
	}
	wiek++;
	if (!(mozeSieRuszyc))
		return;
	poprzedniePolozenieX = polozenieX;
	poprzedniePolozenieY = polozenieY;
	do {
		x = polozenieX;
		y = polozenieY;
		if (rand() % 2) {
			x += rand() % 2 * 2 - 1;
		}
		else {
			y += rand() % 2 * 2 - 1;
		}
	} while (!(x >= 0 && x < swiat->getSzerokosc() && y >= 0 && y < swiat->getWysokosc() && (swiat->getOrganizmPoPolozeniu(x, y) == nullptr || swiat->getOrganizmPoPolozeniu(x, y)->getSila() <= sila)));
	polozenieX = x;
	polozenieY = y;
}