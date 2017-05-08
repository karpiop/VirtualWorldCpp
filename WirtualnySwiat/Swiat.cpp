#include "Swiat.h"
#include <iostream>
#include <ctime>
#include <Windows.h>
#include <fstream>
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

Swiat::Swiat(int sz, int w, int poIle) {
	srand((unsigned int)time(NULL));
	szerokosc = sz;
	wysokosc = w;
	k = new KontenerOrganizmow(poIle, this, sz, w);
	wiek = 0;
	wykonajTure();
}

Swiat::Swiat(const Swiat & swiat) {
	k = new KontenerOrganizmow(*(swiat.k));
	logi = swiat.logi;
	szerokosc = swiat.szerokosc;
	wysokosc = swiat.wysokosc;
	wiek = swiat.wiek;
}

Swiat::~Swiat() {
	delete k;
	std::cout << "DESTRUKTOR SWIATOW\n";
}

void Swiat::wykonajTure() {
	Organizm *o, *o2;
	for (int i = 0; i < k->getLiczbaOrganizmow(); i++) {
		o = k->getNastepnyOrganizm();
		o->akcja();
		o2 = k->getOrganizmByPositon(o->getPolozenieX(), o->getPolozenieY(), o);
		if (o2 != nullptr)
			o2->kolizja(o);
	}
	k->sortuj();
	wiek++;
}

void Swiat::rysujSwiat() {
	system("cls");
	Organizm* o;
	std::cout << "Pawel Karpinski 155085\n";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (SHORT)0, (SHORT)2 });
	for (int i = 0; i < wysokosc; i++) {
		for (int j = 0; j < szerokosc; j++) {
			std::cout << '-';
		}
		std::cout << "\n";
	}
	for (int i = 0; i < k->getLiczbaOrganizmow(); i++) {
		o = k->getNastepnyOrganizm();
		o->rysowanie();
	}
	int i = 2;
	for (auto it = logi.cbegin(); it != logi.cend(); it++) {
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (SHORT)szerokosc + 3, (SHORT)i++ });
		std::cout << *it;
	}
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (SHORT)0, (SHORT)wysokosc + 2});
}

void Swiat::dodajOrganizm(Organizm * o) {
	k->dodajOrganizm(o);
}

void Swiat::usunOrganizm(Organizm * o) {
	k->usunOrganizm(o);
}

int Swiat::getSzerokosc() {
	return szerokosc;
}

int Swiat::getWysokosc() {
	return wysokosc;
}

bool Swiat::jestPustePole(int x, int y)
{
	return (k->getOrganizmByPositon(x, y, NULL) == NULL);
}

void Swiat::ruszCzlowieka(char kierunek) {
	k->ruszCzlowieka(kierunek);
}

void Swiat::aktywujMocCzlowieka() {
	k->aktywujMocCzlowieka();
}

Organizm * Swiat::getOrganizmPoPolozeniu(int x, int y) {
	return k->getOrganizmByPositon(x, y, NULL);
}

void Swiat::dodajLog(std::string str) {
	logi.push_back(str);
	if (logi.size() > 20)
		logi.pop_front();
}

long long Swiat::getWiek() {
	return wiek;
}

void Swiat::zapisz() {
	std::fstream fs;
	fs.open("save.txt", std::fstream::out | std::fstream::trunc);
	if (fs.is_open()) {
		fs << szerokosc << " " << wysokosc << " " << wiek << " " << k->getLiczbaOrganizmow() << "\n";
		for (int i = 0; i < k->getLiczbaOrganizmow(); i++) {
			Organizm * o;
			o = k->getNastepnyOrganizm();
			fs << o->getGatunek() << " " << o->getPolozenieX() << " " << o->getPolozenieY() << "\n";
		}
		fs.close();
		std::string log;
		log += "tura ";
		log += std::to_string(wiek);
		log += ": zapisano";
		dodajLog(log);
		rysujSwiat();
	}
}

void Swiat::wczytaj() {
	std::fstream fs;
	try {
		fs.open("save.txt", std::fstream::in);
		int liczbaOrganizmow;
		char gatunek;
		int x, y;
		Organizm * o;
		int szer, wys, w, lo;
		fs >> szer >> wys >> w >> lo;
		if (szer < 0 || wys < 0)
			throw((std::string)"podano ujemna wysokosc");
		if (w < 0)
			throw((std::string)"podano ujemny wiek");
		if (lo < 0)
			throw((std::string)"podano ujemna liczbe organizmow");
		szerokosc = szer;
		wysokosc = wys;
		wiek = w;
		liczbaOrganizmow = lo;
		while (k->getLiczbaOrganizmow())
			k->usunOrganizm(k->getNastepnyOrganizm());
		for (int i = 0; i < liczbaOrganizmow; i++) {
			fs >> gatunek >> x >> y;
			if (!(x >= 0 && x < szerokosc && y >= 0 && y < wysokosc))
				throw((std::string)"bledne wspolrzedne");
			switch (gatunek) {
			case 'A':
				o = new Antylopa(x, y, this);
				break;
			case 'C':
				o = new Czlowiek(x, y, this);
				break;
			case 'G':
				o = new Guarana(x, y, this);
				break;
			case 'L':
				o = new Lis(x, y, this);
				break;
			case 'M':
				o = new Mlecz(x, y, this);
				break;
			case 'O':
				o = new Owca(x, y, this);
				break;
			case 'T':
				o = new Trawa(x, y, this);
				break;
			case 'J':
				o = new WilczeJagody(x, y, this);
				break;
			case 'W':
				o = new Wilk(x, y, this);
				break;
			case 'Z':
				o = new Zolw(x, y, this);
				break;
			default:
				throw((std::string)"To nie jest zwierze");
				continue;
			}
			k->dodajOrganizm(o);
		}
		fs.close();
		dodajLog("Wczytano pomyslnie ");
	}
	catch (std::string wyjatek) {
		wyjatek = "Blad odczytu: " + wyjatek;
		dodajLog(wyjatek);
		fs.close();
	}
	rysujSwiat();
}

Swiat & Swiat::operator=(const Swiat & swiat) {
	delete k;
	k = new KontenerOrganizmow(*(swiat.k));
	logi = swiat.logi;
	szerokosc = swiat.szerokosc;
	wysokosc = swiat.wysokosc;
	wiek = swiat.wiek;
	return *this;
}
