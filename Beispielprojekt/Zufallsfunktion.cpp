#include "stdafx.h"
#include "Includes.h"
#include "Zufallsfunktion.h"
#include <time.h>

int random_ug_og(int ug, int og) {
	if (ug < 0) {
		ug = 0;
	}
	if (og < ug) {
		og = ug+1;
	}
	srand(time(NULL));
	int Bereich = og - ug + 1;
	return rand() % Bereich + ug;
};
int random_og(int og) {
	return random_ug_og(0, og);
};