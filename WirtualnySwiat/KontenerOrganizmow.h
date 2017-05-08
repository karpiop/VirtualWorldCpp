#ifndef KontenerOrganizmow_H
#define KontenerOrganizmow_H
#include "Organizm.h"

class KontenerOrganizmow {
public:
	KontenerOrganizmow(int poIle, Swiat* swiat, int sz, int wy);
	KontenerOrganizmow(const KontenerOrganizmow &ko);
	~KontenerOrganizmow();
	Organizm* getNastepnyOrganizm();
	Organizm* getOrganizmByPositon(int x, int y, Organizm* napastnik);
	void dodajOrganizm(Organizm *o);
	void usunOrganizm(Organizm *o);
	int getLiczbaOrganizmow();
	void sortuj();
	void ruszCzlowieka(char kierunek);
	void aktywujMocCzlowieka();
	KontenerOrganizmow & KontenerOrganizmow::operator =(const KontenerOrganizmow & prawy);
private:
	int aktualnyOrganizm;
	Organizm** organizmy;
	int liczbaOrganizmow;
	int zaalokowanaPamiec;
};
#endif