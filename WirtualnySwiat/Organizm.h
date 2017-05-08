#ifndef Organizm_H
#define Organizm_H
class Swiat;
class Organizm {
public:
	~Organizm();
	virtual void akcja() = 0;
	virtual void kolizja(Organizm* napastnik) = 0;
	void rysowanie();
	int getSila();
	int getInicjatywa();
	int getPolozenieX();
	int getPolozenieY();
	//Swiat* getSwiat();
	int getWiek();
	void setSila(int sila);
	char getGatunek();
protected:
	int sila;
	int inicjatywa;
	int polozenieX;
	int polozenieY;
	Swiat* swiat;
	int wiek = 0;
	char gatunek;
};
#endif