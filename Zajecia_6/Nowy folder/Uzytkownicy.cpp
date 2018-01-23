#include "stdafx.h"
#include "Uzytkownicy.h"
#include "Uzytkownik.h"
#include <iostream>
#include <fstream>

using namespace std;

void Uzytkownicy::DodajZPliku() {
	ifstream pliczek("UzytkownicyBaza.txt");
	string login, haslo, imie, nazwisko;
	while (pliczek >> login >> haslo >> imie >> nazwisko) {
		Uzytkownik <string> pom;
		pom.login = login;
		pom.haslo = haslo;
		pom.imie = imie;
		pom.nazwisko = nazwisko;
		pom.ranga = "student";
		uz[login] = pom;
	}
}
void Uzytkownicy::ZapiszDoPliku() {
	ofstream pliczek("UzytkownicyBaza.txt", std::ios::trunc);
	string login, haslo, imie, nazwisko;
	for (auto&& j : uz)
	{
		if (j.first != "dziekanat")
			pliczek << j.first << " " << j.second.haslo << " " << j.second.imie << " " << j.second.nazwisko << "\n";
	}
}

void Uzytkownicy::LOG() {
	cout << "PODAJ LOGIN I HASLO" << endl;
	str log, haslo2;
	cin >> log >> haslo2;
	Uzytkownik <string> pom;
	if (uz[log].login == "" || uz[log].haslo == "") {
		cout << "Nie istnieje takie konto o takim loginie." << endl;
	}
	else {
		if (uz[log].haslo == haslo2) {
			pom = uz[log];
			cout << "Witaj, " << pom.imie << " " << pom.nazwisko << endl;
			uz[log].aktywny = 1;
			aktualny = uz[log];
			czyzal = 1;
			aktualneimie = pom.imie;
			aktualnenazwisko = pom.nazwisko;
		}
		else {
			cout << "Bledne haslo." << endl;
			cout << "Aby kontynuowac, wprowadz dowolne slowo, na przyklad OK:\n";
			string c;
			cin >> c;
			system("cls");
		}
	}
}
void Uzytkownicy::Dodaj() {
	system("cls");
	Uzytkownik <string> pom;
	cout << "WITAJ NOWY UZYTKOWNIKU!" << endl;
	cout << "PODAJ SWOJE DANE OSOBOWE " << endl;
	cout << "TWOJE IMIE :";
	cin >> pom.imie;
	cout << endl << "TWOJE NAZWISKO :";
	cin >> pom.nazwisko;
	cout << endl << " LOGIN : ";
	bool pop = 1;
	pom.ranga = "student";
	while (pop == 1) {
		cin >> pom.login;
		if (uz[pom.login].login == "") {
			pop = 0;
		}
		else {
			cout << "Login zajety, podaj nowy. " << endl;
		}
	}

	cout << endl << " HASLO :";
	cin >> pom.haslo;
	
	uz[pom.login] = pom;
	cout << "Utworzono nowe konto. Aby kontynuowac, wprowadz dowolne slowo, na przyklad OK:\n";
	string c;
	cin >> c;
	system("cls");
}

void Uzytkownicy::Wyloguj() {
	czyzal = 0;
	uz[aktualny.login].aktywny = 0;
	cout << "ZOSTALES POMYSLNIE WYLOGOWANY" << endl;
	cout << "Aby kontynuowac, wprowadz dowolne slowo, na przyklad OK:\n";
	string c;
	cin >> c;
	system("cls");
}