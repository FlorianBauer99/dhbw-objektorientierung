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
	Gosu::Image fadenkreuz, florian, gandhi, herz, hintergrund, hoecke, kfc, obama, patrone, patronenkiste, putin, seehofer, trump;
	GameWindow()
		: Window(1600, 900)
		,fadenkreuz("Fadenkreuz.png")
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
		set_caption("Promi Moorhuhn");

	}
	int i = 0;
	double mouse_x = 0;
	double mouse_y = 0;
	
	void draw() override
	{
		
		hintergrund.draw_rot(800, 450, 0.0, 0.0,
			0.5, 0.5
		);
			hoecke.draw_rot(800, 450, 0.0, 0.0,
				0.5, 0.5
			);
			fadenkreuz.draw_rot(mouse_x, mouse_y, 0.0, 0.0,
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

