#pragma once

#include "Produkt.h"
#include "RTV.h"

class KameraCyfrowa: public RTV
{
public:
	KameraCyfrowa() { nazwa = "Kamera"; }
	KameraCyfrowa(int numer_katalogowy) : RTV(numer_katalogowy) { }	string zwrocKategorie() 
	{
		return string("Kamera cyfrowa");
	}
	void ustawProducenta(string nowy_producent);
	void ustawCene(float nowa_cena);

	string zwrocProducenta()
	{
		return string(producent);
	}

	float zwrocCene()
	{
		return float(cena);
	}

protected:
	double ilosc_dostepnej_pamieci;
	double megapiksele;
};