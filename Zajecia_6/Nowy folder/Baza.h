#pragma once
#include "Przedmiot.h"
#include "Student.h"
#include "Uzytkownik.h"
#include "MENU.h"
#include "Grupa.h"
#include <queue>
using namespace std;
class Baza
{
public:
	bool czyzal;
	long long IlePunktowDoZdania;
	Baza() {
		IlePunktowDoZdania = 50;
	}
	Uzytkownik <string> zalogowany;
	map <string, Student> BazaStudentow;
	map <string, Przedmiot> BazaPrzedmiotow;
	map <string, Wykladowca> BazaWykladowcow;
	map <string, Grupa> BazaGrup;
	queue <string> Ogloszenia;

	void MenuWykladowcow();
	void MenuPrzedmiotow();
	void DodajZPliku(); //tutaj zrobic wczytywanie z pliku, zecydowac jakie wartosci
	void MenuStudentow();
	void DodajOgloszenie();
	void PrzeczytajOgloszenia();
	void DodajOcene();
	void PrzyznajPunkty();
	void MenuGrup();
	void SprawdzPunkty();
	void ZapiszDoPliku();
	void START();
};

