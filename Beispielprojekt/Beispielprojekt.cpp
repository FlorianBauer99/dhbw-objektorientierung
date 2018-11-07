//Moorhuhn
#include "stdafx.h"
#include "Includes.h"
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
#include "Vektor2d.h"
#include <time.h>
#include "Counter.h"
#include"Anzeigefunktion.h"
#include"Endfunktion.h"
#include"ImplementierungBilder.h"
#include"Munition.h"
#include"Positionsvergleich.h"
#include"ResetEndscreen.h"
#include"Zeitzaehler.h"
#include"Zufallsfunktion.h"
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

	
	

	//Mausposition (wird hier hinein geschrieben)
	double mouse_x = 0;
	double mouse_y = 0;
	//Position verschiedenener Objekte
	double fadenkreuz_x = 0;
	double fadenkreuz_y = 0;
	
	void draw() override
	{
		//Zeichnet die verschiedenen Bilder Bild.draw_rot(xpos, ypos, zpos, Drehwinkel in Bogenmaß, pos der Mitte (Breite) des Bild relativ dazu, pos der Mitte (Hoehe) des Bildes relativ dazu
		hintergrund.draw_rot(800, 450, 0.0, 0.0,
			0.5, 0.5
		);
		
		fadenkreuz.draw_rot(fadenkreuz_x, fadenkreuz_y, 0.0, 0.0,
			0.5, 0.5
		);

		//Bild erscheinen lassen. In Update muss Bild_Zufallszahl immer gewechselt werden....
		switch (Erscheinungsbild_Nr) {
		case 1: {
			trump.draw_rot(x_Koordinate_Zufallswert_Bild, y_Koordinate_Zufallswert_Bild, 0.0, 0.0,
				0.5, 0.5
			);
		} break;
		case 2: {
			putin.draw_rot(x_Koordinate_Zufallswert_Bild, y_Koordinate_Zufallswert_Bild, 0.0, 0.0,
				0.5, 0.5
			); 
		} break;
		case 3: {
			florian.draw_rot(x_Koordinate_Zufallswert_Bild, y_Koordinate_Zufallswert_Bild, 0.0, 0.0,
				0.5, 0.5
			); 
		} break;
		case 4: {
			seehofer.draw_rot(x_Koordinate_Zufallswert_Bild, y_Koordinate_Zufallswert_Bild, 0.0, 0.0,
				0.5, 0.5
			); 
		} break;
		case 5: {
			hoecke.draw_rot(x_Koordinate_Zufallswert_Bild, y_Koordinate_Zufallswert_Bild, 0.0, 0.0,
				0.5, 0.5
			); 
		} break;
		case 6: {
			gandhi.draw_rot(x_Koordinate_Zufallswert_Bild, y_Koordinate_Zufallswert_Bild, 0.0, 0.0,
				0.5, 0.5
			); 
		} break;
		case 7: {
			obama.draw_rot(x_Koordinate_Zufallswert_Bild, y_Koordinate_Zufallswert_Bild, 0.0, 0.0,
				0.5, 0.5
			); 
		} break;
		case 8: {
			kfc.draw_rot(x_Koordinate_Zufallswert_Bild, y_Koordinate_Zufallswert_Bild, 0.0, 0.0,
				0.5, 0.5
			); 
		} break;
		case 9: {
			herz.draw_rot(x_Koordinate_Zufallswert_Bild, y_Koordinate_Zufallswert_Bild, 0.0, 0.0,
				0.5, 0.5
			); 
		} break;
		case 10: {
			patronenkiste.draw_rot(x_Koordinate_Zufallswert_Bild, y_Koordinate_Zufallswert_Bild, 0.0, 0.0,
				0.5, 0.5
			); 
		} break;
		}
	}
	
	
	// Wird 60x pro Sekunde aufgerufen
	void update() override
	{

		mouse_x = input().mouse_x();
		mouse_y = input().mouse_y();
		/*//Vorübungen, nicht nötig, nur als Info
		i = (i + 3) % 800;
		if (input().down(Gosu::ButtonName::KB_W)) {
			mouse_x = mouse_x + mouse_y;
		}*/

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
		if (fadenkreuz_y > Hoehe_screen) { //dann muss hier und eine Zeile drunter bei Hoehe_Screen noch ein konstanter Wert für den Beriech für Spielinfos abgezogen werden
			fadenkreuz_y = Hoehe_screen;
		}

	}
};

// C++ Hauptprogramm
int main()
{
	GameWindow window;
	window.show();
}