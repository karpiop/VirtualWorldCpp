#include "Roslina.h"
#include <algorithm>
#include "Swiat.h"
#include "Trawa.h"
#include "WilczeJagody.h"
#include "Guarana.h"
#include "Mlecz.h"
#include <iostream>

void Roslina::akcja() {
	if (polozenieY + 1 < swiat->getWysokosc() && swiat->jestPustePole(polozenieX, polozenieY + 1)
		|| polozenieY - 1 >= 0 && swiat->jestPustePole(polozenieX, polozenieY - 1)
		|| polozenieX + 1 < swiat->getSzerokosc() && swiat->jestPustePole(polozenieX + 1, polozenieY)
		|| polozenieX - 1 >= 0 && swiat->jestPustePole(polozenieX - 1, polozenieY)) {
		int r = rand() % 100;
		if (r < 5 && wiek) {
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
			} while (!(x >= 0 && x<swiat->getSzerokosc() && y >= 0 && y<swiat->getWysokosc() && swiat->jestPustePole(x, y)));
			if (dynamic_cast<Trawa*>(this) != NULL) {
				swiat->dodajOrganizm((Organizm*)new Trawa(x, y, swiat));
			}
			if (dynamic_cast<Guarana*>(this) != NULL) {
				swiat->dodajOrganizm((Organizm*)new Guarana(x, y, swiat));
			}
			if (dynamic_cast<Mlecz*>(this) != NULL) {
				swiat->dodajOrganizm((Organizm*)new Mlecz(x, y, swiat));
			}
			if (dynamic_cast<WilczeJagody*>(this) != NULL) {
				swiat->dodajOrganizm((Organizm*)new WilczeJagody(x, y, swiat));
			}
		}
	}
	wiek++;
}

void Roslina::kolizja(Organizm * o) {
	std::string log;
	log += "tura " + std::to_string(swiat->getWiek()) + ":\t";
	log += o->getGatunek();
	log += " zjada ";
	log += this->getGatunek();
	swiat->dodajLog(log);
	swiat->usunOrganizm(this);
}
