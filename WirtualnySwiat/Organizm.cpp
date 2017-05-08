#include "Organizm.h"
#include "Swiat.h"
#include <iostream>
#include <Windows.h>



Organizm::~Organizm() {
	//std::cout << "Destruktor organizmow\n";
}

void Organizm::rysowanie() {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {(SHORT)polozenieX, (SHORT)polozenieY + 2});
	std::cout << gatunek;
}

int Organizm::getSila() {
	return sila; 
}

int Organizm::getInicjatywa() { 
	return inicjatywa; 
}

int Organizm::getPolozenieX() { 
	return polozenieX; 
}

int Organizm::getPolozenieY() { 
	return polozenieY; 
}

int Organizm::getWiek() { 
	return wiek; 
}

void Organizm::setSila(int sila) {
	this->sila = sila;
}

char Organizm::getGatunek() {
	return gatunek;
}
