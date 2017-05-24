// SklepInternetowy.cpp : Defines the entry point for the console application.
//

#include "Produkt.h"
#include "Telefon.h"
#include "KameraCyfrowa.h"
#include "Telewizor.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

string nowy_producent;
float nowa_cena;

void pokazMenu()
{
	cout << "Menu programu:" << endl;
	cout << "1. Dodaj telewizor." << endl;
	cout << "2. Dodaj telefon." << endl;
	cout << "3. Dodaj kamere cyfrowa" << endl;
	cout << "4. Wyswietl zawartosc bazy." << endl;
	cout << "5. Posortuj wg ceny (rosnaco)." << endl;
	cout << "6. Szukaj produktu o producencie." << endl << endl;
	cout << "7. Wyjscie." << endl << endl;
}

vector<string> zwrocNazwyProduktowOProducencie(string szukany_producent, vector<Produkt*> produkty)
{
	vector<string> nazwy;
	string nazwa;
	for (int i = 0; i < produkty.size(); i++)
	{
		if(produkty[i]->zwrocProducenta() == szukany_producent)
		{
			nazwa = produkty[i]->zwrocKategorie();
			nazwy.push_back(nazwa);
		}
	}
	if(nazwy.size() == 0)
		throw string("Brak produktu o takim producencie");
	else
	{
		for(int i=0; i<nazwy.size(); i++)
		{
		cout << nazwy[i] << endl;
		}
	}
	return nazwy;
}

bool funkcjaSortowania(Produkt *p1, Produkt *p2)
{
	return(p1->zwrocCene() < p2->zwrocCene());
}
int main(int argc, char* argv[])
{
	vector<Produkt*> produkty;
	int wybor = 0;
	Produkt *nowy;

	srand(0);
	cin.exceptions(istream::failbit | istream::badbit);

	while (wybor!=7)
	{
		pokazMenu();
		
		cin >> wybor;
		cin.ignore(1000, '\n');
		cin.clear();

		switch (wybor)
		{
		case 1: 
			nowy = new Telewizor();
			cout << "Podaj producenta:"<< endl;
			cin >> nowy_producent;
			nowy->ustawProducenta(nowy_producent);
			cout << "Podaj cene:" << endl;
			cin >> nowa_cena;
			nowy->ustawCene(nowa_cena);
			produkty.push_back(nowy);
			cout << endl << "Dodano telewizor" << endl << endl;
			break;
		case 2: 
			nowy = new Telefon();
			cout << "Podaj producenta:" << endl;
			cin >> nowy_producent;
			nowy->ustawProducenta(nowy_producent);
			cout << "Podaj cene:" << endl;
			cin >> nowa_cena;
			nowy->ustawCene(nowa_cena);
			produkty.push_back(nowy);
			cout << endl << "Dodano telefon" << endl << endl;
			break;
		case 3: 
			nowy = new KameraCyfrowa();
			cout << "Podaj producenta:" << endl;
			cin >> nowy_producent;
			nowy->ustawProducenta(nowy_producent);
			cout << "Podaj cene:" << endl;
			cin >> nowa_cena;
			nowy->ustawCene(nowa_cena);
			produkty.push_back(nowy);
			cout << endl << "Dodano kamere" << endl << endl;
			break;
		case 4:
			for (size_t i=0; i<produkty.size(); i++)
			{
				cout << produkty[i]->zwrocKategorie() << " : " << produkty[i]->numer_katalogowy << endl;
				cout << "Producent: " << produkty[i]->zwrocProducenta() << endl;
				cout << "Cena: " << produkty[i]->zwrocCene() << endl;
			}
			break;
		case 5:
			sort(produkty.begin(), produkty.end(), funkcjaSortowania);
			cout << "Posortowano!!!" << endl;
			break;
		case 6:
			string podany_producent;
			cout << "Podaj producenta: " << endl;
			cin >> podany_producent;
			try
			{
				zwrocNazwyProduktowOProducencie(podany_producent, produkty);
			}
			catch (string blad)
			{
				cout << blad << endl;
			}
			break;
		}
	}

	for (vector<Produkt*>::iterator it=produkty.begin(); it!=produkty.end(); it++)
		delete *it;

	return 0;
}

