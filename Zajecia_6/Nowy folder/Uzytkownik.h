#pragma once
#include <string>
#include <iostream>
using namespace std;

typedef string str;

template <typename T> class Uzytkownik {
	friend class Uzytkownicy;
	friend class Baza;
public:
	T imie;
	T nazwisko;
	T haslo;
public:
	bool aktywny;
	T ranga;
	T login;
	template <typename G> G GetImie() { return this->imie; }
	template <typename G> G GetNazwisko() { return this->nazwisko; }
	template <typename G> G GetHaslo() { return this->haslo; }
	template <typename G> G GetLogin() { return this->login; }

};


	