#include "Includes.h"
#include "Counter.h"
//Lebenscounter Fügt bei getroffenen Herz eines hinzu, wenn falsche Person, zieht er eines ab, wenn richtige tut er nichts.
int lebenscounter(int leben, bool herztreffer, bool falschertreffer) {
	if (herztreffer == true) {
		leben = leben + 1;
		return leben;
	}
	else if(falschertreffer==true) {
		leben = leben - 1;
		return leben;
	}
	else {
		return leben;
	}
}
//Wenn eine Kiste getroffen wurde, so wird die Munitionszahl auf munition_max erhöht. Ansonsten wird eines abgezogen. Aufruf bei jedem Mausklicken und beim Treffen einer Kiste.
int munitionscounter(int munition, bool Treffer) {
	int munition_max = 10;
	if (Treffer == true) {
		munition = munition_max;
		return munition;
	}
	else {
		munition = munition - 1;
		return munition;
	}
}
//wenn ein Treffer, dann Score um 1 einhöht. Nur bei guten Treffer anzuwenden
int scorecounter(int score) {
	score = score + 1;
	return score;
}