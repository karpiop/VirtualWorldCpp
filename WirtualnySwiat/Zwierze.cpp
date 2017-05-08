#include "Zwierze.h"
#include <cstdlib>
#include <algorithm>
#include "Owca.h"
#include "Wilk.h"
#include "Swiat.h"
#include "Lis.h"
#include "Zolw.h"
#include "Antylopa.h"
void Zwierze::akcja() {
	int x, y;
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
	} while (!(x >= 0 && x < swiat->getSzerokosc() && y >= 0 && y < swiat->getWysokosc()));
	polozenieX = x;
	polozenieY = y;
	wiek++;
}

void Zwierze::kolizja(Organizm * o) {
	if (gatunek == o->getGatunek()) {
		((Zwierze*)o)->wroc();
		std::pair <int, int> sasiedniePola[8];
		sasiedniePola[0] = std::make_pair(this->getPolozenieX(), std::min(this->getPolozenieY() + 1, swiat->getWysokosc() - 1));
		sasiedniePola[1] = std::make_pair(this->getPolozenieX(), std::max(this->getPolozenieY() - 1, 0));
		sasiedniePola[2] = std::make_pair(std::min(this->getPolozenieX() + 1, swiat->getSzerokosc() - 1), this->getPolozenieY());
		sasiedniePola[3] = std::make_pair(std::max(this->getPolozenieX() - 1, 0), this->getPolozenieY());
		sasiedniePola[4] = std::make_pair(o->getPolozenieX(), std::min(o->getPolozenieY() + 1, swiat->getWysokosc() - 1));
		sasiedniePola[5] = std::make_pair(o->getPolozenieX(), std::max(o->getPolozenieY() - 1, 0));
		sasiedniePola[6] = std::make_pair(std::min(o->getPolozenieX() + 1, swiat->getSzerokosc() - 1), o->getPolozenieY());
		sasiedniePola[7] = std::make_pair(std::max(o->getPolozenieX() - 1, 0), o->getPolozenieY());
		bool jestMiejsce = false;
		for (int i = 0; i < 8; i++) {
			if (swiat->jestPustePole(sasiedniePola[i].first, sasiedniePola[i].second)) {
				jestMiejsce = true;
				break;
			}
		}
		if (jestMiejsce && wiek>10 && o->getWiek()>10) {
			int r;
			do {
				r = rand() % 8;
			} while (!(swiat->jestPustePole(sasiedniePola[r].first, sasiedniePola[r].second)));
			Organizm * potomek;
			switch (gatunek) {
			case 'W':
				potomek = new Wilk(sasiedniePola[r].first, sasiedniePola[r].second, swiat);
				break;
			case 'A':
				potomek = new Antylopa(sasiedniePola[r].first, sasiedniePola[r].second, swiat);
				break;
			case 'O':
				potomek = new Owca(sasiedniePola[r].first, sasiedniePola[r].second, swiat);
				break;
			case 'L':
				potomek = new Lis(sasiedniePola[r].first, sasiedniePola[r].second, swiat);
				break;
			case 'Z':
				potomek = new Zolw(sasiedniePola[r].first, sasiedniePola[r].second, swiat);
				break;
			}
			swiat->dodajOrganizm(potomek);
		}
	}
	else {
		std::string log;
		log += "tura " + std::to_string(swiat->getWiek()) + ":\t";
		if (sila <= o->getSila()) {
			log += o->getGatunek();
			log += " zjada ";
			log += this->getGatunek();
			swiat->dodajLog(log);
			swiat->usunOrganizm(this);
		}
		else {
			log += this->getGatunek();
			log += " zjada ";
			log += o->getGatunek();
			swiat->dodajLog(log);
			swiat->usunOrganizm(o);
		}
	}
}

void Zwierze::wroc() {
	polozenieX = poprzedniePolozenieX;
	polozenieY = poprzedniePolozenieY;
}
