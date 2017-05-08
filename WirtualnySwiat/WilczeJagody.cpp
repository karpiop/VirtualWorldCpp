#include "WilczeJagody.h"
#include <iostream>
#include "Swiat.h"

WilczeJagody::WilczeJagody(int x, int y, Swiat * swiat) {
	sila = 99;
	inicjatywa = 0;
	polozenieX = x;
	polozenieY = y;
	this->swiat = swiat;
	gatunek = 'J';
}

WilczeJagody::~WilczeJagody() {
	std::cout << "Destruktor wilczych jagod\n";
}

void WilczeJagody::kolizja(Organizm * o) {
	std::string log = "tura " + std::to_string(swiat->getWiek()) + ":\t";
	log += o->getGatunek();
	log += " zjada J oba gina\n";
	swiat->dodajLog(log);
	swiat->usunOrganizm(o);
	swiat->usunOrganizm(this);
}
