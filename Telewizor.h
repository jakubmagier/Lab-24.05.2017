#pragma once

#include "Produkt.h"
#include "RTV.h"
#include <vector>
#include <string>
#include <iostream>

enum TechnologiaMatrycy { LED, LCD, PLASMA };

class Telewizor: public RTV
{
public:
	Telewizor() {
		dostepne_rozdzielczosci.push_back("1280x720");
		dostepne_rozdzielczosci.push_back("800x600");
		nazwa = "Telewizor";
	}
	Telewizor(int numer_katalogowy) : RTV(numer_katalogowy) { }
	void ustawProducenta(string nowy_producent);
	void ustawCene(float nowa_cena);
	string zwrocKategorie() 
	{
		return string("Telewizor");
	}

	float zwrocCene()
	{
		return float(cena);
	}

	string zwrocProducenta()
	{
		return string(producent);
	}

	~Telewizor()
	{
	}

protected:
	TechnologiaMatrycy technologia_matrycy;
	double wielkosc_matrycy;
	vector<string> dostepne_rozdzielczosci;
};
