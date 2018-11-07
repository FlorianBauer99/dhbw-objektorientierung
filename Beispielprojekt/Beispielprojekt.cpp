//Moorhuhn
#include "stdafx.h"
#include "Includes.h"
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
#include "Vektor2d.h"
#include <time.h>

#include "Zufallsfunktion.h"
using namespace std;
// Simulationsgeschwindigkeit
const double DT = 100.0;
const int Breite_Screen = 1600;
const int Hoehe_screen = 900;

class GameWindow : public Gosu::Window
{
public:
	Gosu::Image fadenkreuz, florian, gandhi, herz, hintergrund, hoecke, kfc, obama, patrone, patronenkiste, putin, seehofer, trump;
	GameWindow()
		: Window(Breite_Screen, Hoehe_screen) //initialisiert das Spielfenster mit Breite*Hoehe
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
		
	{
		set_caption("Promi Moorhuhn"); //ändert den Title des geöffneten Spielfensters

	}
	//Definition benötigter Variabeln

	//sonstiges
	int i = 0;
	int Patronenabstand = 30;
	int Herzabstand = 60;
	//Mausposition (wird hier hinein geschrieben)
	double mouse_x = 0;
	double mouse_y = 0;
	//Position verschiedenener Objekte
	double fadenkreuz_x = 0;
	double fadenkreuz_y = 0;

	double hintergrund_x = Breite_Screen / 2.0;
	double hintergrund_y = Hoehe_screen / 2.0;
	
	//Patronen- und Lebensanzeige
	const int pos_sichtbar = 4;
	int z_pos_p[11];
	int munition=10;
	int leben = 5;
	int z_pos_h[6];
	
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

		hintergrund.draw_rot(hintergrund_x, hintergrund_y, 1.0, 0.0, 0.5, 0.5);
		
		fadenkreuz.draw_rot(fadenkreuz_x, fadenkreuz_y, 3.0, 0.0, 0.5, 0.5);

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

		herz.draw_rot(35 + (Herzabstand * 0), 32, z_pos_p[1], 0.5, 0.5);
		herz.draw_rot(35 + (Herzabstand * 1), 32, z_pos_p[2], 0.5, 0.5);
		herz.draw_rot(35 + (Herzabstand * 2), 32, z_pos_p[3], 0.5, 0.5);
		herz.draw_rot(35 + (Herzabstand * 3), 32, z_pos_p[4], 0.5, 0.5);
		herz.draw_rot(35 + (Herzabstand * 4), 32, z_pos_p[5], 0.5, 0.5);
	}
	
	
	// Wird 60x pro Sekunde aufgerufen
	void update() override
	{
		//Vorübungen, nicht nötig, nur als Info
		i = (i + 3) % 800;
		mouse_x = input().mouse_x();
		mouse_y = input().mouse_y();
		if (input().down(Gosu::ButtonName::KB_W)) {
			mouse_x = mouse_x + mouse_y;
		}

		//Fadenkreuz bleibt in bestimmtem Bereich, aktuell genau im Screen, später eventuell freier Bereich am unteren Rand für Spielinfos?
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
		if (fadenkreuz_y > Hoehe_screen) { //dann muss hier und eine Zeile drunter bei Hoehe_Screen noch ein konstanter Wert für den Bereich für Spielinfos abgezogen werden
			fadenkreuz_y = Hoehe_screen;
		}

		//Munition
		if (munition > 10) {
			munition = 10;
		}
		if (munition > 0) { // wenn Munition >0 munition = Anzahl sichtbare (z_pos_p=3) Patronen
			for (int i = 1; i <= munition; i++)
			{
				z_pos_p[i] = pos_sichtbar;
			}
		}
		else // wenn munition =0
		{
			for (int i = 1; i <= 10; i++)
			{
				z_pos_p[i] = 0;
			}

			//hier noch irgendwas um weitere Schüsse zu verhindern!
		}

		//Herzen
		if (leben > 5) {
			leben = 5;
		}
		if (leben > 0) { // wenn leben >0 leben = Anzahl sichtbare (z_pos_h=3) Patronen
			for (int i = 1; i <= leben; i++)
			{
				z_pos_h[i] = pos_sichtbar;
			}
		}
		else // wenn leben =0
		{
			for (int i = 1; i <= 5; i++)
			{
				z_pos_h[i] = 0;
			}

			//hier noch irgendwas um weitere Schüsse zu verhindern!
		}
	}
};

// C++ Hauptprogramm
int main()
{
	GameWindow window;
	window.show();
}