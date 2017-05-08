#ifndef Swiat_H
#define Swiat_H
#include "KontenerOrganizmow.h"
#include <string>
#include <list>

class Swiat {
public:
	Swiat(int sz, int w, int poIle);
	Swiat(const Swiat & swiat);
	~Swiat();
	void wykonajTure();
	void rysujSwiat();
	void dodajOrganizm(Organizm* o);
	void usunOrganizm(Organizm* o);
	int getSzerokosc();
	int getWysokosc();
	bool jestPustePole(int x, int y);
	void ruszCzlowieka(char kierunek);
	void aktywujMocCzlowieka();
	Organizm* getOrganizmPoPolozeniu(int x, int y);
	void dodajLog(std::string str);
	long long getWiek();
	void zapisz();
	void wczytaj();
	Swiat & Swiat::operator =(const Swiat & prawy);
private:
	KontenerOrganizmow* k;
	std::list <std::string> logi;
	int szerokosc;
	int wysokosc;
	long long wiek;
};
#endif