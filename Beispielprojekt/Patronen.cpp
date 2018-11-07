#include "stdafx.h"
#include "Includes.h"
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
#include "Vektor2d.h"
#include <time.h>
using namespace std;

//Definitionen

int munition;
const int pos_sichtbar = 2;

int z_pos_p[10];


int main() {
	if (munition > 0) { // wenn Munition >0 munition = Anzahl sichtbare (z_pos_p=2) Patronen
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

		//hier noch irgendwas um weitere Schüsse zu verhindern
	}
}