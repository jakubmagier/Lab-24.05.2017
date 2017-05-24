#pragma once

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Produkt
{
public:
	Produkt() {
		numer_katalogowy = rand();
		producent = "Producent domyslny";
	}
	Produkt(int numer_katalogowy) : numer_katalogowy(numer_katalogowy) { }
	virtual string zwrocKategorie() = 0;
	virtual ~Produkt() { }
	virtual void ustawProducenta(string nowy_producent) = 0;
	virtual string zwrocProducenta() = 0;
	virtual float zwrocCene() = 0;
	virtual void ustawCene(float nowa_cena) = 0;
	int numer_katalogowy;

protected:
	string nazwa;
	string producent;
	float cena;
};

