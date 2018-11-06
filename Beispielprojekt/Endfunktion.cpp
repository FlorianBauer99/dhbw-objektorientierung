#include "stdafx.h"
#include "Includes.h"
#include "Endfunktion.h"
//Wenn Munition oder Leben leer ist, so wird false zurückgegeben--> Vorletzte abfrage vorm Ende. Darauffolgend muss das erscheinen eines Endscreens sein!
bool weiterspielen(int munition, int leben) {
	if (munition == 0 || leben == 0) {
		return false;
	}
	else {
		return true;
	}
};