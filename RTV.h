#pragma once

#include "Produkt.h"

class RTV: public Produkt
{
public:
	RTV() {}
	RTV(int numer_katalogowy) : Produkt(numer_katalogowy) { }
	string zwrocKategorie() = 0;
protected:
	double napiecie_zasilania; 
};
