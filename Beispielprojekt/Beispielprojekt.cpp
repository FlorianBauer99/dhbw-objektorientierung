#include "stdafx.h"

#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

#include <vector>
#include <string>
#include <iostream>

#include "Planet.h"
#include "Vektor2d.h"
#include <time.h>
using namespace std;
// Simulationsgeschwindigkeit
const double DT = 100.0;

class GameWindow : public Gosu::Window
{
public:
	Gosu::Image bild;
	GameWindow()
		: Window(800, 600)
		,bild("rakete.png")
		
	{
		set_caption("Gosu Tutorial Game mit Git");

	}
	int i = 0;
	double mouse_x = 0;
	double mouse_y = 0;
	
	void draw() override
	{
		graphics().draw_line(
			10, 20, Gosu::Color::RED,
			200, 100, Gosu::Color::GREEN,
			0.0
		);
		graphics().draw_triangle(
			10, 20, Gosu::Color::RED,
			i, 100, Gosu::Color::GREEN,
			mouse_x, mouse_y, Gosu::Color::BLUE,
			0.0
		);
		bild.draw_rot(mouse_x, mouse_y, 0.0,
			0.0,
			0, 5.0, 5
			);
	}
	

	// Wird 60x pro Sekunde aufgerufen
	void update() override
	{
		i = (i + 3) % 800;
		mouse_x = input().mouse_x();
		mouse_y = input().mouse_y();
		if (input().down(Gosu::ButtonName::KB_W)) {
			mouse_x = mouse_x + mouse_y;
		}
	}
};

// C++ Hauptprogramm
int main()
{
	int a=5;
	//GameWindow window;
	//window.show();
	int Zufallsvariable;
	int ug = 1;//untere Grenze des Zahlenbereichs
	int og = 100;//obere Grenze des Zahlenbereichs
	int Zahlenbereich = og - ug+1;
	srand(time(NULL));
	for (int i = 0; i<100; i++) {
		Zufallsvariable = rand() % Zahlenbereich + ug;
		//Zufallsvariable ist jetzt zwischen 1 und 100
		cout << Zufallsvariable << endl;
	}

	system("pause");
	
	int b;
}


//Änderung
