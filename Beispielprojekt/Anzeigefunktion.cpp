#include "stdafx.h"
#include "Includes.h"
#include "Anzeigefunktion.h"


int bild_auswaehlen() {
	//Bilder aussuchen

	if (1 <= Bild_Zufallszahl && Bild_Zufallszahl <= 10) {
		return 1; //Trump
	}
	else if (11 <= Bild_Zufallszahl && Bild_Zufallszahl <= 20) {
		return 2; //Putin
	}
	else if (21 <= Bild_Zufallszahl && Bild_Zufallszahl <= 30) {
		return 3; //Florian Bauer
	}
	else if (31 <= Bild_Zufallszahl && Bild_Zufallszahl <= 40) {
		return 4; //Seehofer
	}
	else if (41 <= Bild_Zufallszahl && Bild_Zufallszahl <= 50) {
		return 5; //Hoecke
	}
	else if (51 <= Bild_Zufallszahl && Bild_Zufallszahl <= 60) {
		return 6; //Ghandi
	}
	else if (61 <= Bild_Zufallszahl && Bild_Zufallszahl <= 70) {
		return 7; //Obama
	}
	else if (71 <= Bild_Zufallszahl && Bild_Zufallszahl <= 80) {
		return 8; //KFC
	}
	else if (81 <= Bild_Zufallszahl && Bild_Zufallszahl <= 90) {
		return 9; //Herz
	}
	else if (91 <= Bild_Zufallszahl && Bild_Zufallszahl <= 140) {
		return 10; //Munition
	}
}