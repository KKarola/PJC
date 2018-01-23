// dziekanat.cpp : Defines the entry point for the console application.
//
//tutaj bedzie glowny kod z MENU dla poszczegolnych rang i login i haslo dla Dziekanatu - ranga admin, moze nadawac rangi - domyslnie przy tworzeniu profilu ranga
//bedzie student - taki system Ci pasuje? Daj znac
#include "stdafx.h"
#include "Baza.h"
#include "Uzytkownicy.h"
#include "plik.h"
//login

Uzytkownicy BazaUzytkownikow;
Baza Dokumenty;
bool czyzal;
void MENU1() {
	if (BazaUzytkownikow.czyzal == 1) {
		cout << "WITAJ, " << BazaUzytkownikow.aktualneimie << "! " << endl;
		Dokumenty.zalogowany = BazaUzytkownikow.aktualny;
		Dokumenty.czyzal = 1;
		while (Dokumenty.czyzal == 1) {
			Dokumenty.START();
		}
		BazaUzytkownikow.Wyloguj();
		BazaUzytkownikow.czyzal = 0;
		system("cls");
	}
		cout << "DOSTEPNE AKCJE:" << endl;
		cout << "1. ZALOGUJ SIE NA ISTNIEJACE KONTO " << endl;
		cout << "2. ZAREJESTRUJ NOWE STUDENCKIE KONTO" << endl;
		//cout << "3. EDYTUJ KONTO" << endl;
		cout << "3. OPUSC APLIKACJE" << endl;
		cout << "4. DODAJ Z PLIKU" << endl;
		cout << "5. ZAPISZ DO PLIKU" << endl;
}
int main()
{
	while (1) {
		cout << " WITAJ W DZIEKANACIE " << endl;
		cout << " JAKA AKCJE CHCIALBYS PODJAC? WYBIERZ ODPOWIEDNI NUMER" << endl;
		MENU1();
		int wybor;
		cin >> wybor;
		system("cls");
		if (wybor == 1) {
			BazaUzytkownikow.LOG();
		}
		else if (wybor == 2) {
			BazaUzytkownikow.Dodaj();
			system("cls");
			cout << " UDALO SIE UTWORZYC KONTO" << endl;
		}
		else if (wybor == 3) {
			return 0;
		}
		else if (wybor == 4) {
			BazaUzytkownikow.DodajZPliku();
		}
		else if (wybor == 5) {
			BazaUzytkownikow.ZapiszDoPliku();
		}
	}
    return 0;
}

