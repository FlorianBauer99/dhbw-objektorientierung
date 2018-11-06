#include "stdafx.h"

#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

#include <vector>
#include <string>
#include <iostream>


#include "Vektor2d.h"
#include <time.h>
using namespace std;
// Simulationsgeschwindigkeit
const double DT = 100.0;

class GameWindow : public Gosu::Window
{
public:
	Gosu::Image bild_hg,  bild_hoe, bild_fa;
	GameWindow()
		: Window(1600, 900)
		,bild_hg("Hintergrund.png")
		,bild_hoe("Hoecke.png")
		,bild_fa ("Fadenkreuz.png")
		
	{
		set_caption("Promi Moorhuhn");

	}
	int i = 0;
	double mouse_x = 0;
	double mouse_y = 0;
	
	void draw() override
	{
		
		bild_hg.draw_rot(800, 450, 0.0, 0.0,
			0.5, 0.5
		);
			bild_hoe.draw_rot(800, 450, 0.0, 0.0,
				0.5, 0.5
			);
			bild_fa.draw_rot(mouse_x, mouse_y, 0.0, 0.0,
				0.5, 0.5
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
	GameWindow window;
	window.show();
	

}

