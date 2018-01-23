
#include "stdafx.h"
#include "Student.h"
#include "Przedmiot.h"

void Student::DodajOcene(Przedmiot a) {
	cout << "Podaj ocene w skali (2-5): ";
	short int wybor;
	cin >> wybor;
	if (wybor > 5 || wybor < 2) {
		cout << "Nieprawidlowa ocena - poza skala!" << endl;
		cout << "Aby kontynuowaæ, wprowadz dowolne slowo, na przyklad OK:\n";
		string c;
		cin >> c;
	}
	else {
		ListaOcen[a.Nazwa].push_back(wybor);
		cout << "Ocene dodano. \nAby kontynuowaæ, wprowadz dowolne slowo, na przyklad OK:\n";
		string c;
		cin >> c;
	}
}
void Student::PodgladOcen() {
	for (auto&& i : ListaOcen) {
		//cout << i.first;
		// klucz to rzecz.first
		// wartosc to rzecz.second
		if (ListaOcen.count(i.first) == 0) {
			cout << i.first << " BRAK OCEN \n";
		}
		else {
			vector <short int> V;
			V = ListaOcen[i.first];
			cout << i.first << ":\n";
			for (int j = 0; j < (int)V.size(); j++) {
				cout << V[j] << " ";
			}
			cout << "\n";
		}
	}
	cout << endl;
	cout << "Aby kontynuowaæ, wprowadz dowolne slowo, na przyklad OK:\n";
	string c;
	cin >> c;
}