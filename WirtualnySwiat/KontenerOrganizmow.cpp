#include "KontenerOrganizmow.h"
#include <iostream>
#include <algorithm>
#include "Wilk.h"
#include "Owca.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Czlowiek.h"
#include "Guarana.h"
#include "WilczeJagody.h"
#include "Lis.h"
#include "Zolw.h"
#include "Antylopa.h"

KontenerOrganizmow::KontenerOrganizmow(int poIle, Swiat* swiat, int sz, int wy) {
	zaalokowanaPamiec = sz*wy;
	organizmy = new Organizm*[zaalokowanaPamiec];
	for (int i = 0; i < sz*wy; i++) {
		organizmy[i] = nullptr;
	}
	liczbaOrganizmow = 9 * poIle + 1;
	aktualnyOrganizm = liczbaOrganizmow -1;
	for (int i = 0; i < poIle; i++) {
		organizmy[i] = new Wilk(rand() % sz, rand() % wy, swiat);
		organizmy[i + poIle] = new Owca(rand() % sz, rand() % wy, swiat);
		organizmy[i + 2 * poIle] = new Trawa(rand() % sz, rand() % wy, swiat);
		organizmy[i + 3 * poIle] = new Mlecz(rand() % sz, rand() % wy, swiat);
		organizmy[i + 4 * poIle] = new Guarana(rand() % sz, rand() % wy, swiat);
		organizmy[i + 5 * poIle] = new WilczeJagody(rand() % sz, rand() % wy, swiat);
		organizmy[i + 6 * poIle] = new Lis(rand() % sz, rand() % wy, swiat);
		organizmy[i + 7 * poIle] = new Zolw(rand() % sz, rand() % wy, swiat);
		organizmy[i + 8 * poIle] = new Antylopa(rand() % sz, rand() % wy, swiat);
	}
	organizmy[liczbaOrganizmow - 1] = new Czlowiek(rand() % sz, rand() % wy, swiat);
	sortuj();
}

KontenerOrganizmow::KontenerOrganizmow(const KontenerOrganizmow & ko) {
	aktualnyOrganizm = ko.aktualnyOrganizm;
	liczbaOrganizmow = ko.liczbaOrganizmow;
	zaalokowanaPamiec = ko.zaalokowanaPamiec;
	organizmy = new Organizm*[ko.zaalokowanaPamiec];
	for (int i = 0; i < liczbaOrganizmow; i++) {
		switch (ko.organizmy[i]->getGatunek()) {
		case 'A':
			organizmy[i] = new Antylopa(*((Antylopa*)(ko.organizmy[i])));
			break;
		case 'C':
			organizmy[i] = new Czlowiek(*((Czlowiek*)(ko.organizmy[i])));
			break;
		case 'G':
			organizmy[i] = new Guarana(*((Guarana*)(ko.organizmy[i])));
			break;
		case 'L':
			organizmy[i] = new Lis(*((Lis*)(ko.organizmy[i])));
			break;
		case 'M':
			organizmy[i] = new Mlecz(*((Mlecz*)(ko.organizmy[i])));
			break;
		case 'O':
			organizmy[i] = new Owca(*((Owca*)(ko.organizmy[i])));
			break;
		case 'T':
			organizmy[i] = new Trawa(*((Trawa*)(ko.organizmy[i])));
			break;
		case 'J':
			organizmy[i] = new WilczeJagody(*((WilczeJagody*)(ko.organizmy[i])));
			break;
		case 'W':
			organizmy[i] = new Wilk(*((Wilk*)(ko.organizmy[i])));
			break;
		case 'Z':
			organizmy[i] = new Zolw(*((Zolw*)(ko.organizmy[i])));
			break;
		default:
			break;
		}
	}
}

KontenerOrganizmow::~KontenerOrganizmow() {
	for (int i = 0; i < liczbaOrganizmow; i++) {
		delete organizmy[i];
	}
	delete organizmy;
	std::cout << "Destruktor kontenera\n";
}

Organizm * KontenerOrganizmow::getNastepnyOrganizm() {
	return organizmy[++aktualnyOrganizm %= liczbaOrganizmow];
}

Organizm * KontenerOrganizmow::getOrganizmByPositon(int x, int y, Organizm *napastnik) {
	Organizm* o;
	for (int i = 0; i < liczbaOrganizmow; i++) {
		o = organizmy[i];
		if (o != napastnik && o->getPolozenieX() == x && o->getPolozenieY() == y) {
			return o;
		}
	}
	return NULL;
}

void KontenerOrganizmow::dodajOrganizm(Organizm * o) {
	organizmy[liczbaOrganizmow++] = o;
}

void KontenerOrganizmow::usunOrganizm(Organizm* o){
	for (int i = 0; i < liczbaOrganizmow; i++) {
		if (organizmy[i] == o) {
			delete organizmy[i];
			organizmy[i] = NULL;
			for (int j = i + 1; j < liczbaOrganizmow; j++) {
				std::swap(organizmy[j-1], organizmy[j]);
			}
			liczbaOrganizmow--;
			if (i <= aktualnyOrganizm)
				aktualnyOrganizm--;
			return;
		}
	}
}

int KontenerOrganizmow::getLiczbaOrganizmow(){
	return liczbaOrganizmow;
}

void KontenerOrganizmow::sortuj() {
	Organizm *a;
	Organizm *b;
	for (int i = 0; i < liczbaOrganizmow; i++) {
		int max = i;
		for (int j = i + 1; j < liczbaOrganizmow; j++) {
			a = organizmy[max];
			b = organizmy[j];
			if (b->getInicjatywa() > a->getInicjatywa()
				|| b->getInicjatywa() == a->getInicjatywa() && b->getWiek()>a->getWiek()) {
				max = j;
			}
			std::swap(organizmy[i], organizmy[max]);
		}
	}
}

void KontenerOrganizmow::ruszCzlowieka(char kierunek) {
	for (int i = 0; i < liczbaOrganizmow; i++) {
		if (dynamic_cast<Czlowiek*>(organizmy[i]) != NULL) {
			((Czlowiek*)organizmy[i])->ustawKierunek(kierunek);
			return;
		}
	}
}

void KontenerOrganizmow::aktywujMocCzlowieka(){
	for (int i = 0; i < liczbaOrganizmow; i++) {
		if (dynamic_cast<Czlowiek*>(organizmy[i]) != NULL) {
			((Czlowiek*)organizmy[i])->aktywujMoc();
			return;
		}
	}
}

KontenerOrganizmow & KontenerOrganizmow::operator=(const KontenerOrganizmow & ko) {
	while (liczbaOrganizmow)
		usunOrganizm(organizmy[0]);
	delete organizmy;
	aktualnyOrganizm = ko.aktualnyOrganizm;
	liczbaOrganizmow = ko.liczbaOrganizmow;
	zaalokowanaPamiec = ko.zaalokowanaPamiec;
	organizmy = new Organizm*[ko.zaalokowanaPamiec];
	for (int i = 0; i < liczbaOrganizmow; i++) {
		switch (ko.organizmy[i]->getGatunek()) {
		case 'A':
			organizmy[i] = new Antylopa(*((Antylopa*)(ko.organizmy[i])));
			break;
		case 'C':
			organizmy[i] = new Czlowiek(*((Czlowiek*)(ko.organizmy[i])));
			break;
		case 'G':
			organizmy[i] = new Guarana(*((Guarana*)(ko.organizmy[i])));
			break;
		case 'L':
			organizmy[i] = new Lis(*((Lis*)(ko.organizmy[i])));
			break;
		case 'M':
			organizmy[i] = new Mlecz(*((Mlecz*)(ko.organizmy[i])));
			break;
		case 'O':
			organizmy[i] = new Owca(*((Owca*)(ko.organizmy[i])));
			break;
		case 'T':
			organizmy[i] = new Trawa(*((Trawa*)(ko.organizmy[i])));
			break;
		case 'J':
			organizmy[i] = new WilczeJagody(*((WilczeJagody*)(ko.organizmy[i])));
			break;
		case 'W':
			organizmy[i] = new Wilk(*((Wilk*)(ko.organizmy[i])));
			break;
		case 'Z':
			organizmy[i] = new Zolw(*((Zolw*)(ko.organizmy[i])));
			break;
		default:
			break;
		}
	}
	return *this;
}

