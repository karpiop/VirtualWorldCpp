#include "Swiat.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <conio.h>

int main() {
	Swiat sw(20,20, 3);
	sw.rysujSwiat();
	char znak;
	while (true) {
		while (znak=getch()) {
			if (znak == -32) {
				znak = getch();
				sw.ruszCzlowieka(znak);
			}
			if (znak == 13)
				break;
			else if (znak == 'q')
				return 0;
			else if (znak == ' ')
				sw.aktywujMocCzlowieka();
			else if (znak == 's')
				sw.zapisz();
			else if (znak == 'l')
				sw.wczytaj();
		}
		sw.wykonajTure();
		sw.rysujSwiat();
	}
	return 0;
}