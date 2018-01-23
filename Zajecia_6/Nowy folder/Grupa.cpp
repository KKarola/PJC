#include "stdafx.h"
#include "Grupa.h"
#include <fstream>

void Grupa::DodajPrzedmiot(Przedmiot a) {
	ListaPrzedmiotow.push_back(a);
	cout << "Pomyslnie dodano przedmiot do grupy. Aby kontynuowac, napisz OK" << endl;
	string c;
	cin >> c;
}

void Grupa::DodajStudenta(Student a) {
	ListaStudentow.push_back(a);
	cout << "Pomyslnie dodano studenta. Aby kontynuowac, napisz OK" << endl;
	string c;
	cin >> c;

}

void Grupa::Wypisz() {
	int wybor;
	system("cls");
	cout << "Jesli chcesz poznac liste studentow, wpisz 1." << endl;
	cout << "Jesli chcesz poznac liste przedmiotow, wpisz 2." << endl;
	cin >> wybor;
	if (wybor == 1) {
		cout << "=====================================================================" << endl;
		for (int i = 0; i < (int)ListaStudentow.size(); i++) {
			cout << ListaStudentow[i].imie << " " << ListaStudentow[i].nazwisko << endl;
		}
		cout << "=====================================================================" << endl;
		cout << "Aby kontynuowac, wprowadz dowolne slowo, na przyklad OK:\n";
		string c;
		cin >> c;

	}
	else if (wybor == 2) {
		cout << "=====================================================================" << endl;
		for (int i = 0; i < (int)ListaPrzedmiotow.size(); i++) {
			cout << ListaPrzedmiotow[i].Nazwa << endl;
		}
		cout << "=====================================================================" << endl;
		cout << "Aby kontynuowac, wprowadz dowolne slowo, na przyklad OK:\n";
		string c;
		cin >> c;
	}
	else {
		cout << "Niepoprawny wybor!" << endl;
		cout << "Aby kontynuowac, wprowadz dowolne slowo, na przyklad OK:\n";
		string c;
		cin >> c;
	}
}

void Grupa::UsunStudenta(Student a) {
	for (int i = 0; i < ListaStudentow.size(); i++) {
		if (ListaStudentow[i].nazwisko == a.nazwisko) {
			ListaStudentow[i] = ListaStudentow[ListaStudentow.size() - 1];
			ListaStudentow.pop_back();
			break;
		}
	}
	cout << "Usunieto studenta, aby kontynuowac, wpisz dowolne slowo, np OK\n";
	string c;
	cin >> c;
	return;
}