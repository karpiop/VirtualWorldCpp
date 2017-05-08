#include "Czlowiek.h"
#include <iostream>
#include "Swiat.h"

Czlowiek::Czlowiek(int x, int y, Swiat * swiat) {
	sila = 5;
	inicjatywa = 4;
	polozenieX = poprzedniePolozenieX = x;
	polozenieY = poprzedniePolozenieY = y;
	niesmiertelnosc = 0;
	this->swiat = swiat;
	gatunek = 'C';
}

Czlowiek::~Czlowiek() {
	std::cout << "Destruktor czlowieka\n";
}

void Czlowiek::akcja() {
	poprzedniePolozenieX = polozenieX;
	poprzedniePolozenieY = polozenieY;
	switch (kierunek) {
	case 72://gora
		if (polozenieY > 0)
			polozenieY--;
		break;
	case 80://dol
		if (polozenieY + 1 < swiat->getWysokosc())
			polozenieY++;
		break;
	case 75://lewo
		if (polozenieX > 0)
			polozenieX--;
		break;
	case 77://prawo
		if (polozenieX + 1 < swiat->getSzerokosc())
			polozenieX++;
		break;
	}
	int x = polozenieX;
	int y = polozenieY;
	this->wroc();
	std::string log;
	log += "tura " + std::to_string(swiat->getWiek()) + ":\t";
	Organizm * o = swiat->getOrganizmPoPolozeniu(x, y);
	polozenieX = x;
	polozenieY = y;
	if (o != NULL && sila <= o->getSila() && niesmiertelnosc >= 5
		&& (polozenieX > 0 && swiat->jestPustePole(polozenieX - 1, polozenieY)
		|| polozenieX - 1 < swiat->getSzerokosc() && swiat->jestPustePole(polozenieX + 1, polozenieY)
		|| polozenieY > 0 && swiat->jestPustePole(polozenieX, polozenieY - 1)
		|| polozenieY - 1 < swiat->getWysokosc() && swiat->jestPustePole(polozenieX, polozenieY + 1)))
		kolizja(o);
	wiek++;
	if (niesmiertelnosc)
		niesmiertelnosc--;
}

void Czlowiek::kolizja(Organizm * o) {
	std::string log;
	log += "tura " + std::to_string(swiat->getWiek()) + ":\t";
	if (sila <= o->getSila() && niesmiertelnosc >= 5 
		&& (polozenieX > 0 && swiat->jestPustePole(polozenieX - 1, polozenieY)
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
		log += gatunek;
		log += " ucieka przed ";
		log += o->getGatunek();
		swiat->dodajLog(log);
	}
	else
		Zwierze::kolizja(o);
}

void Czlowiek::ustawKierunek(char k) {
	kierunek = k;
}

void Czlowiek::aktywujMoc() {
	if (niesmiertelnosc == 0) {
		niesmiertelnosc = 9;
		swiat->dodajLog("tura " + std::to_string(swiat->getWiek()) + ":\t" + "niesmiertelnosc aktywowana");
	}
	else {
		swiat->dodajLog("tura " + std::to_string(swiat->getWiek()) + ":\t" + "niesmiertelnosc niedostepna");
	}
	swiat->rysujSwiat();
}
