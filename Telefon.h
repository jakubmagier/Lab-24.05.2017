#pragma once

#include "Produkt.h"
#include "RTV.h"

enum RodzajTelefonu { Klapka, Smartfon, Tradycyjny };

class Telefon: public RTV
{
public:
	Telefon() { nazwa = "Telefon"; }
	Telefon(int numer_katalogowy) : RTV(numer_katalogowy) { }
	
	void ustawProducenta(string nowy_producent);
	void ustawCene(float nowa_cena);
	string zwrocKategorie() 
	{
		return string("Telefon");
	}

	float zwrocCene()
	{
		return float(cena);
	}

	string zwrocProducenta()
	{
		return string(producent);
	}

protected:
	double wielkosc_matrycy;
	double liczba_procesorow;
	RodzajTelefonu rodzaj; 
};