#ifndef Czlowiek_H
#define Czlowiek_H
#include "Zwierze.h"

class Czlowiek : public Zwierze {
public:
	Czlowiek(int x, int y, Swiat* swiat);
	~Czlowiek();
	void akcja();
	void kolizja(Organizm* napastnik);
	void ustawKierunek(char kierunek);
	void aktywujMoc();
private:
	int niesmiertelnosc;
	char kierunek;
};
#endif