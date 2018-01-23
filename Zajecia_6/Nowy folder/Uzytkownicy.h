#pragma once
#include "Uzytkownik.h"

#include <map>
using namespace std;
typedef char chr;
typedef string str;
class Uzytkownicy {
	friend void MENU1();
	Uzytkownik <string> aktualny;
public:
	bool czyzal;
	str aktualneimie;
	str aktualnenazwisko;
	map <str, Uzytkownik <string> > uz;
	Uzytkownicy() {
		Uzytkownik <string> dziekanat;
		dziekanat.haslo = "dziekanat";
		dziekanat.login = "dziekanat";
		dziekanat.ranga = "dziekanat";
		dziekanat.aktywny = 0;
		dziekanat.imie = "DZIEKANAT";
		uz["dziekanat"] = dziekanat;
	}
	void Czyjest();
	void ZmienDane();
	void Dodaj();
	void LOG();
	void Wyloguj();
	void DodajZPliku();
	void ZapiszDoPliku();
};

//#endif
