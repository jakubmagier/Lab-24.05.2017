#pragma once
#include "Produkt.h"

class AGD: public Produkt
{
public:
	AGD() {}
	AGD(int numer_katalogowy) : Produkt(numer_katalogowy)
	{ }
	string zwrocKategorie() = 0;
protected:
	double roczne_zuzycie_energii;
};