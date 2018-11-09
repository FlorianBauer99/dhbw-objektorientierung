//Moorhuhn
#include "stdafx.h"
#include "Includes.h"
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
#include "Vektor2d.h"
#include <time.h>
#include "Counter.h"
#include "Anzeigefunktion.h"
#include "Endfunktion.h"
#include "ImplementierungBilder.h"
#include "Munition.h"
#include "Positionsvergleich.h"
#include "ResetEndscreen.h"
#include "Zeitzaehler.h"
#include "Zufallsfunktion.h"
#include <windows.h>
using namespace std;
// Simulationsgeschwindigkeit
const double DT = 100.0;
const int Breite_Screen = 1600;
const int Hoehe_Screen = 900;



class GameWindow : public Gosu::Window
{
public:

	Gosu::Image endscreen, fadenkreuz, florian, gandhi, herz, hintergrund, hoecke, kfc, obama, patrone, patronenkiste, putin, seehofer, trump;
	GameWindow()
		: Window(Breite_Screen, Hoehe_Screen) //initialisiert das Spielfenster mit Breite*Hoehe
		,endscreen("Endscreen.png")
		,fadenkreuz("Fadenkreuz.png")//läd alle Bilder aus dem Speicherordner
		,florian("Florian.png")
		,gandhi ("Gandhi.png")
		,herz("Herz.png")
		,hintergrund("Hintergrund.png")
		,hoecke("Hoecke.png")
		,kfc("KFC.png")
		,obama("Obama.png")
		,patrone("Patrone.png")
		,patronenkiste("Patronenkiste.png")
		,putin("Putin.png")
		,seehofer("Seehofer.png")
		,trump("Trump.png")

		,Ausgabe_Score(170)
		,Ausgabe_Score_ingame(70)
		
	{
		set_caption("Promi Moorhuhn"); //ändert den Title des geöffneten Spielfensters

	}

	Gosu::Font Ausgabe_Score, Ausgabe_Score_ingame;


	//Definition benötigter Variabeln
	//Bildformatgrößen über der Klasse, da diese bereits im GameWindow benötigt werden

	//sonstiges
	int i = 0;
	//Abstände für Bilder
	int Patronenabstand = 30;
	int Herzabstand = 60;
	int Kopfabstand_B = 50;
	int Kopfabstand_H = 75;
	//Mausposition (wird hier hinein geschrieben)
	double mouse_x = 0;
	double mouse_y = 0;
	bool mouse_click = 0;//1, wenn Maustaste gedrückt wird (toggeln der Taste von nicht gedrückt auf gedrückt)
	bool mouse_click_now = 0; //wurde die Maus diesen Durchlaufzyklus gedrückt
	bool mouse_click_before = 0; //wurde die Maus im Zyklus zuvor gedrückt?
	//Position verschiedenener Objekte
	double fadenkreuz_x = 0;
	double fadenkreuz_y = 0;

	double hintergrund_x = Breite_Screen / 2.0;  //gilt sowohl für den Hintergrund als auch den Endscreen
	double hintergrund_y = Hoehe_Screen / 2.0;
	
	//Patronen- und Lebensanzeige
	const int pos_sichtbar = 4;
	int z_pos_p[11];
	int z_pos_h[6];

	double z_pos_endscreen=5.0;

	string Score_ausgabe;
	string Score_ausgabe_ingame;
	
	void draw() override
	{
		//Zeichnet die verschiedenen Bilder Bild.draw_rot(xpos, ypos, zpos, Drehwinkel in Bogenmaß, pos der Mitte (Breite) des Bild relativ dazu, pos der Mitte (Hoehe) des Bildes relativ dazu
		//was sagt die zpos aus:
		//0: "ausgeblendet" , nicht für Köpfe verwendbar
		//1: Hintergrund
		//2: Köpfe sichtbar
		//3: Fadenkreuz sichtbar
		//4: Munition/Leben sichtbar
		//5: Endscreen

		if (endscreen_anzeigen) { 
			z_pos_endscreen = 5.0;
		}
		else {
			z_pos_endscreen = 0.0;
		}
		endscreen.draw_rot(hintergrund_x, hintergrund_y, z_pos_endscreen,0.0, 0.5, 0.5);

		Ausgabe_Score.draw(Score_ausgabe, 710, 343, z_pos_endscreen);

		Ausgabe_Score_ingame.draw(Score_ausgabe_ingame, 500, 790, 4.0);

		hintergrund.draw_rot(hintergrund_x, hintergrund_y, 1.0, 0.0, 0.5, 0.5);
		
		fadenkreuz.draw_rot(fadenkreuz_x, fadenkreuz_y, 3.0+2*endscreen_anzeigen, 0.0, 0.5, 0.5);

		patrone.draw_rot(1575 - (Patronenabstand * 0), 815, z_pos_p[1], 0.5, 0.5);
		patrone.draw_rot(1575 - (Patronenabstand * 1), 815, z_pos_p[2], 0.5, 0.5);
		patrone.draw_rot(1575 - (Patronenabstand * 2), 815, z_pos_p[3], 0.5, 0.5);
		patrone.draw_rot(1575 - (Patronenabstand * 3), 815, z_pos_p[4], 0.5, 0.5);
		patrone.draw_rot(1575 - (Patronenabstand * 4), 815, z_pos_p[5], 0.5, 0.5);
		patrone.draw_rot(1575 - (Patronenabstand * 5), 815, z_pos_p[6], 0.5, 0.5);
		patrone.draw_rot(1575 - (Patronenabstand * 6), 815, z_pos_p[7], 0.5, 0.5);
		patrone.draw_rot(1575 - (Patronenabstand * 7), 815, z_pos_p[8], 0.5, 0.5);
		patrone.draw_rot(1575 - (Patronenabstand * 8), 815, z_pos_p[9], 0.5, 0.5);
		patrone.draw_rot(1575 - (Patronenabstand * 9), 815, z_pos_p[10], 0.5, 0.5);

		herz.draw_rot(35 + (Herzabstand * 0), 32, z_pos_h[1], 0.5, 0.5);
		herz.draw_rot(35 + (Herzabstand * 1), 32, z_pos_h[2], 0.5, 0.5);
		herz.draw_rot(35 + (Herzabstand * 2), 32, z_pos_h[3], 0.5, 0.5);
		herz.draw_rot(35 + (Herzabstand * 3), 32, z_pos_h[4], 0.5, 0.5);
		herz.draw_rot(35 + (Herzabstand * 4), 32, z_pos_h[5], 0.5, 0.5);


		//Bild erscheinen lassen. In Update muss Bild_Zufallszahl immer gewechselt werden....
		switch (Erscheinungsbild_Nr) {
		case 1: {
			trump.draw_rot(x_Koordinate_Zufallswert_Bild, y_Koordinate_Zufallswert_Bild, 2.0, 0.0, 0.5, 0.5);
		} break;
		case 2: {
			putin.draw_rot(x_Koordinate_Zufallswert_Bild, y_Koordinate_Zufallswert_Bild, 2.0, 0.0, 0.5, 0.5); 
		} break;
		case 3: {
			florian.draw_rot(x_Koordinate_Zufallswert_Bild, y_Koordinate_Zufallswert_Bild, 2.0, 0.0, 0.5, 0.5); 
		} break;
		case 4: {
			seehofer.draw_rot(x_Koordinate_Zufallswert_Bild, y_Koordinate_Zufallswert_Bild, 2.0, 0.0, 0.5, 0.5); 
		} break;
		case 5: {
			hoecke.draw_rot(x_Koordinate_Zufallswert_Bild, y_Koordinate_Zufallswert_Bild, 2.0, 0.0, 0.5, 0.5); 
		} break;
		case 6: {
			gandhi.draw_rot(x_Koordinate_Zufallswert_Bild, y_Koordinate_Zufallswert_Bild, 2.0, 0.0, 0.5, 0.5); 
		} break;
		case 7: {
			obama.draw_rot(x_Koordinate_Zufallswert_Bild, y_Koordinate_Zufallswert_Bild, 2.0, 0.0, 0.5, 0.5); 
		} break;
		case 8: {
			kfc.draw_rot(x_Koordinate_Zufallswert_Bild, y_Koordinate_Zufallswert_Bild, 2.0, 0.0, 0.5, 0.5); 
		} break;
		case 9: {
			herz.draw_rot(x_Koordinate_Zufallswert_Bild, y_Koordinate_Zufallswert_Bild, 2.0, 0.0, 0.5, 0.5); 
		} break;
		case 10: {
			patronenkiste.draw_rot(x_Koordinate_Zufallswert_Bild, y_Koordinate_Zufallswert_Bild, 2.0, 0.0, 0.5, 0.5); 
		} break;
		}
	}
	
	
	// Wird 60x pro Sekunde aufgerufen
	void update() override
	{
		//Einlesen von Tastendrücken und Mausklicks
		mouse_x = input().mouse_x();
		mouse_y = input().mouse_y();
		mouse_click_before = mouse_click_now;
		mouse_click_now = input().down(Gosu::ButtonName::MS_LEFT);
		if (mouse_click_before==false && mouse_click_now==true) {
			mouse_click = true;
		}
		else {
			mouse_click = false;
		}

	
		string Score_ausgabe = to_string(Score);
		string Score_ausgabe_ingame = "Score: " + Score_ausgabe;
		

		fadenkreuz_x = mouse_x;
		if (fadenkreuz_x < 0) {
			fadenkreuz_x = 0;
		}
		if (fadenkreuz_x > Breite_Screen) {
			fadenkreuz_x = Breite_Screen;
		}
		fadenkreuz_y = mouse_y;
		if (fadenkreuz_y < 0) {
			fadenkreuz_y = 0;
		}
		if (fadenkreuz_y > Hoehe_Screen) { //dann muss hier und eine Zeile drunter bei Hoehe_Screen noch ein konstanter Wert für den Bereich für Spielinfos abgezogen werden
			fadenkreuz_y = Hoehe_Screen;
		}

		//Ende, kann gern durch Endscreen erweiter werden, zb durch beschreiben der Erscheindungsbild_Nr. Aber dann auch in der Draw mitändern!
		if (endscreen_anzeigen) {
			if ((mouse_click) && ((mouse_x > 394) && (mouse_x < 583) && (mouse_y > 620) && (mouse_y < 723))) {//Quit ausgewählt
				cout << "Quit angeklickt" << endl;
				Gosu::Window::close();
			}
			if ((mouse_click) && (((mouse_x > 1021) && (mouse_x < 1209)) && ((mouse_y > 621) && (mouse_y < 725)))) {//Restart ausgewählt
				cout << "Restart angeklickt" << endl;
				//endscreen_anzeigen = false;
				zuruecksetzen();
			}
		}
		else {
			

			/*//Vorübungen, nicht nötig, nur als Info
			i = (i + 3) % 800;
			if (input().down(Gosu::ButtonName::KB_W)) {
				mouse_x = mouse_x + mouse_y;
			}*/



			
			
			//Zeit bis neues Bild
			Schleifenzaehler = wartezeitbild(Schleifenzaehler);



			//Bilder anzeigen und Levelschwierigkeit
			if (Schleifenzaehler == 0) {
				cout << endl << "Ausgewaehltes Bild(Zufallswert)";
				Bild_Zufallszahl = random_ug_og(1, 140);
				Erscheinungsbild_Nr = bild_auswaehlen();
				cout << "X-Koordinate Bild: ";
				x_Koordinate_Zufallswert_Bild = random_ug_og(Kopfabstand_B, Breite_Screen - Kopfabstand_B);
				cout << "Y-Koordinate Bild: ";
				y_Koordinate_Zufallswert_Bild = random_ug_og(Kopfabstand_H, Hoehe_Screen - Kopfabstand_H);
				if (Score < 10) {
					Schleifenzaehler = neuerzyklus1(Schleifenzaehler);
				}
				else if (Score < 20) {
					Schleifenzaehler = neuerzyklus2(Schleifenzaehler);
				}
				if (Score >= 20) {
					Schleifenzaehler = neuerzyklus3(Schleifenzaehler);
				}
			}

			//Munitionscontrolling
			if (mouse_click) {
				munition = munitionscounter(munition, 0);
			}
			if (munition > 10) {
				munition = 10;
			}
			for (int i = 1; i <= 10; i++)//Zuerst alle ausblenden, dann die, die noch da sind, wieder einblenden, sonst sieht man alle oder keine aber keine zwischenwerte
			{
				z_pos_p[i] = 0;
			}
			if (munition > 0) { // wenn Munition >0 munition = Anzahl sichtbare (z_pos_p=3) Patronen
				for (int i = 1; i <= munition; i++)
				{
					z_pos_p[i] = pos_sichtbar;
				}
			}
			else // wenn munition =0//ist die überhaupt nötig, da Methode weiterspielen(Leben,Munition) dies bereits abdeckt?
			{
				for (int i = 1; i <= 10; i++)
				{
					z_pos_p[i] = 0;
				}

				endscreen_anzeigen = true;
			}

			//Herzencontrolling
			if (leben > 5) {
				leben = 5;
			}
			for (int i = 1; i <= 5; i++)//Zuerst alle ausblenden, dann die, die noch da sind, wieder einblenden, sonst sieht man alle oder keine aber keine zwischenwerte
			{
				z_pos_h[i] = 0;
			}
			if (leben > 0) { // wenn leben >0 leben = Anzahl sichtbare (z_pos_h=3) Leben
				for (int i = 1; i <= leben; i++)
				{
					z_pos_h[i] = pos_sichtbar;
				}
			}
			else // wenn leben =0 //ist die überhaupt nötig, da Methode weiterspielen(Leben,Munition) dies bereits abdeckt?
			{
				for (int i = 1; i <= 5; i++)
				{
					z_pos_h[i] = 0;
				}
				endscreen_anzeigen = true;
			}

			//was passiert bei diversen Treffern
			abstand_b_m = Gosu::distance(mouse_x, mouse_y, x_Koordinate_Zufallswert_Bild, y_Koordinate_Zufallswert_Bild); //Abstand Mauszeiger zu Bildmittelpunkt

			if ((mouse_click) && (abstand_b_m <= hitbox) && ((Erscheinungsbild_Nr == 1) || (Erscheinungsbild_Nr <= 5))) { //Treffer Böse
				Schleifenzaehler = 1;
				Score = scorecounter(Score);
				cout << "Treffer boese, Score: " << Score << endl;
			}
			if ((mouse_click) && (abstand_b_m <= hitbox) && ((Erscheinungsbild_Nr >= 6) && (Erscheinungsbild_Nr <= 8))) { //Treffer Gute
				cout << "Treffer gut" << endl;
				Schleifenzaehler = 1;
				leben = lebenscounter(leben, 0, 1);
			}
			if ((mouse_click) && (abstand_b_m <= hitbox) && (Erscheinungsbild_Nr == 9)) { //Treffer Leben
				cout << "Treffer Leben" << endl;
				Schleifenzaehler = 1;
				leben = lebenscounter(leben, 1, 0);
			}
			if ((mouse_click) && (abstand_b_m <= hitbox) && (Erscheinungsbild_Nr == 10)) { //Treffer Munition
				cout << "Treffer Kiste" << endl;
				Schleifenzaehler = 1;
				munition = munitionscounter(munition, 1);
			}


		}
		
	}
};

// C++ Hauptprogramm
int main()
{
	srand(time(NULL));
	cout << "Debuginfos:";
	GameWindow window;
	window.show();
	system("pause"); //dadurch kann man nach schließen des Spielfensters noch die Debuginfos in der Konsole auslesen
}