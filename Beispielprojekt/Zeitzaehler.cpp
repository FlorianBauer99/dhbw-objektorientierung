#include "Includes.h"
#include "Zeitzaehler.h"
//Neuer Zyklus muss in Main mit if/case Abfrage gemacht werden--> wenn Score>X, dann jeweiliger Wartezyklus... Insgesamt 3 Level
int neuerzyklus1(int zyklus) {
	int wartezeit = 60;
	if (zyklus == 0) {
		zyklus = wartezeit;
		return zyklus;
	}
	else {
		return zyklus;
	}
}

int neuerzyklus2(int zyklus) {
	int wartezeit = 40;
	if (zyklus == 0) {
		zyklus = wartezeit;
		return zyklus;
	}
	else {
		return zyklus;
	}
}

int neuerzyklus3(int zyklus) {
	int wartezeit = 20;
	if (zyklus == 0) {
		zyklus = wartezeit;
		return zyklus;
	}
	else {
		return zyklus;
	}
}
//Verringert Wartezeit um 1 bis Zyklus 0 ist(muss man davor abgreifen...)--> nächster Zyklus
int wartezeitbild(int zyklus) {
	zyklus = zyklus - 1;
	return zyklus;
}