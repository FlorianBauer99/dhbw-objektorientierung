#include "stdafx.h"
#include "Includes.h"

 int Bild_Zufallszahl; //F�r die Anzeigefunktion, von 1 bis 140!

 int Erscheinungsbild_Nr; //F�r das Aufrufen der Bilder

 int x_Koordinate_Zufallswert_Bild; //F�r x Koordinate der Bilder

 int y_Koordinate_Zufallswert_Bild; //F�r y Koordinate der Bilder

  int hitbox = 50;//Abstand zum Bildmittelpunkt in dem ein Treffer gez�hlt wird
  double abstand_b_m;//Abstand zwischen Bildmitte und Mauszeiger bzw. Fadenkreuz


int Schleifenzaehler = 60; //Z�hler f�rn Zyklus

int Score=0; //Spielstand des Nutzers

int munition = 10;

int leben = 5;

bool endscreen_anzeigen=false;