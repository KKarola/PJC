#include "stdafx.h"
#include "Baza.h"
#include "Student.h"
#include "Przedmiot.h"
#include <iostream>
#include <string>
#include <fstream>
void Baza::MenuWykladowcow() {
	system("cls");
	cout << "1. Dodaj wykladowce\n";
	cout << "2. Edytuj wykladowce\n";
	cout << "3. Wypisz wszystkich wykladowcow aktualnie wykladajacych na uczelni\n";
	int wybor;
	cin >> wybor;
	if (wybor == 1) {
		system("cls");
		Wykladowca a;
		cout << "Wpisz imie, nazwisko wykladowcy:\n";
		cin >> a.imie >> a.nazwisko;
		BazaWykladowcow[a.nazwisko] = a;
		cout << "Aby kontynuowac, wpisz dowolne slowo, np OK\n";
		string c;
		cin >> c;
		system("cls");
	}
	if (wybor == 2) {
		cout << "Ktorego wykladowce chcesz edytowac? Podaj prosze jego nazwisko:\n";
		string naz;
		cin >> naz;
		Wykladowca nowy;
		if (!BazaWykladowcow.count(naz)) {
			cout << "ERROR! Aby kontynuowac, wpisz dowolne slowo, np OK\n";
			string c;
			cin >> c;
			return;
		}
		nowy = BazaWykladowcow[naz];
		BazaWykladowcow.erase(naz);
		system("cls");
		cout << "1. Zmien imie wykladowcy.\n";
		cout << "2. Zmien nazwisko wykladowcy.\n";
		cout << "3. Zwolnij wykladowce.\n";
		int wybor2;
		cin >> wybor2;
		system("cls");
		if (wybor2 == 1) {
			cout << "Podaj nowe imie:\n";
			cin >> nowy.imie;
			BazaWykladowcow[nowy.nazwisko] = nowy;
			cout << "Pomyslnie edytowano wykladowce, aby kontynuowac, wpisz dowolne slowo, np OK\n";
			string c;
			cin >> c;
			return;
		}
		else if (wybor2 == 2) {
			cout << "Podaj nowe nazwisko:\n";
			cin >> nowy.nazwisko;
			BazaWykladowcow[nowy.nazwisko] = nowy;
			cout << "Pomyslnie edytowano wykladowce, aby kontynuowac, wpisz dowolne slowo, np OK\n";
			string c;
			cin >> c;
			return;
		}
		else if (wybor2 == 3) {
			cout << "Pomyslnie zwolniono wykladowce, aby kontynuowac, wpisz dowolne slowo, np OK\n";
			string c;
			cin >> c;
			return;
		}
		cout << "ERROR!" << endl;
	}
	if (wybor == 3) {
		cout << "==========================================\n";
		for (auto&& i : BazaWykladowcow) {
			cout << i.second.imie << " " << i.second.nazwisko << "\n";
		}
		cout << "==========================================\n";
		cout << "Aby kontynuowac, wpisz dowolne slowo, np OK\n";
		string c;
		cin >> c;
		return;

	}
}
void Baza::MenuPrzedmiotow() {
	system("cls");
	cout << "1. Dodaj przedmiot\n";
	cout << "2. Edytuj przedmiot\n";
	int wybor;
	cin >> wybor;
	if (wybor == 1) {
		cout << "Podaj nazwe przedmiotu, imie prowadzacego, nazwisko prowadzacego i ile punktow ECTS jest przydzielonych do przedmiotu (oddziel enterami)\n";
		Przedmiot a;
		cin >> a.Nazwa >> a.Prowadzacy.imie >> a.Prowadzacy.nazwisko >> a.PunktyECTS;
		if (BazaWykladowcow.count(a.Prowadzacy.nazwisko) == 0) {
			cout << "ERROR!Aby kontynuowac, wpisz dowolne slowo, np OK\n";
			string c;
			cin >> c;
			system("cls");
			return;

		}
		BazaPrzedmiotow[a.Nazwa] = a;
		cout << "Dodano przedmiot. Aby kontynuowac, wpisz dowolne slowo, np OK\n";
		string c;
		cin >> c;
		system("cls");
	}
	if (wybor == 2) {
		cout << "Podaj nazwe przedmiotu, ktory chcesz edytowac\n";
		Przedmiot a;
		cin >> a.Nazwa;
		if (!BazaPrzedmiotow.count(a.Nazwa)) {
			cout << "ERROR! Aby kontynuowac, wpisz dowolne slowo\n";
			string c;
			cin >> c;
			return;
		}
		a = BazaPrzedmiotow[a.Nazwa];
		BazaPrzedmiotow.erase(a.Nazwa);
		system("cls");
		cout << "1. Zmien nazwe przedmiotu.\n";
		cout << "2. Zmien liczbe punktow ECTS za przedmiot\n";
		int wybor2;
		cin >> wybor2;
		system("cls");
		if (wybor2 == 1) {
			cout << "Podaj nowa nazwe przedmiotu.\n";
			cin >> a.Nazwa;
		}
		else if (wybor2 == 2) {
			cout << "Podaj nowa liczbe punktow ECTS (liczba calkowita zapisana cyframi arabskimi)\n";
			cin >> a.PunktyECTS;
		}
		BazaPrzedmiotow[a.Nazwa] = a;
		cout << "Przedmiot zostal edytowany, aby kontynuowac wpisz dowolne slowo, np OK\n";
		string x;
		cin >> x;
		system("cls");
	}

}
void Baza::ZapiszDoPliku() {
	//zapisanie baz 
	ofstream NazwyGrup("Grupy.txt", std::ios::trunc);
	for (auto&& i : BazaGrup) {
		NazwyGrup << BazaGrup[i.first].NazwaGrupy << " "; // nazwa
		NazwyGrup << BazaGrup[i.first].ListaStudentow.size() << " "; //liczba studentow
		for (int j = 0; j < (int)BazaGrup[i.first].ListaStudentow.size(); j++) {
			NazwyGrup << BazaGrup[i.first].ListaStudentow[j].nazwisko << " "; //wpisz studentow
		}
		NazwyGrup << BazaGrup[i.first].ListaPrzedmiotow.size() << " ";//liczba przedmiotow
		for (int j = 0; j < BazaGrup[i.first].ListaPrzedmiotow.size(); j++) {
			NazwyGrup << BazaGrup[i.first].ListaPrzedmiotow[j].Nazwa << " "; //wpisz przedmioty
		}
	}
	ofstream pliczek("Studenci2.txt", std::ios::trunc);
	ofstream Oceny("Ocenki.txt", std::ios::trunc);
	for (auto&& i : BazaStudentow) {
		// klucz to rzecz.first
		// wartosc to rzecz.second
		pliczek << BazaStudentow[i.first].imie << " " << BazaStudentow[i.first].nazwisko << " ";
		pliczek << BazaStudentow[i.first].adres << " " << BazaStudentow[i.first].punkty << "\n";
		Oceny << i.first << " " << BazaStudentow[i.first].ListaOcen.size() << "\n";
		for (auto&& j : BazaStudentow[i.first].ListaOcen) {
			Oceny << j.first << " " << BazaStudentow[i.first].ListaOcen[j.first].size() << " ";
			for (int k = 0; k < BazaStudentow[i.first].ListaOcen[j.first].size(); k++) {
				Oceny << BazaStudentow[i.first].ListaOcen[j.first][k] << " ";
			}
			Oceny << "\n";
		}
	}
	ofstream pliczek2("Przedmioty.txt", std::ios::app);
	for (auto&& i : BazaPrzedmiotow) {
		pliczek2 << BazaPrzedmiotow[i.first].Nazwa << " " << BazaPrzedmiotow[i.first].Prowadzacy.imie << " " << BazaPrzedmiotow[i.first].Prowadzacy.nazwisko << " " << BazaPrzedmiotow[i.first].PunktyECTS << " ";
	}
	ofstream pliczek3("Wykladowcy.txt", std::ios::app);
	for (auto&& i : BazaWykladowcow) {
		pliczek3 << i.second.imie << " " << i.second.nazwisko << " ";
	}
}
void Baza::DodajZPliku() {
	//wczytanie studentow
	string imie1, nazwisko1, adres1;
	int punkty1;
	ifstream pliczek("Studenci2.txt");
	ifstream ocenki("Ocenki.txt");
	while (pliczek >> imie1 >> nazwisko1 >> adres1 >> punkty1) {
		Student a;
		a.imie = imie1;
		a.nazwisko = nazwisko1;
		a.adres = adres1;
		a.punkty = punkty1;
		BazaStudentow[nazwisko1] = a;
		int ile_przedmiotow;
		string przedmiot, nazwisko;
		ocenki >> nazwisko >> ile_przedmiotow;
		//cout << nazwisko << " " << ile_przedmiotow << endl;
		for (int i = 0; i < ile_przedmiotow; i++)
		{
			int ile_ocen;
			ocenki >> przedmiot >> ile_ocen;
			//		cout << przedmiot << " " << ile_ocen << endl;
			for (int j = 0; j < ile_ocen; j++)
			{
				int ocena;
				ocenki >> ocena;
				BazaStudentow[nazwisko].ListaOcen[przedmiot].push_back(ocena);
				//		cout << ocena << " ";
			}
			//cout << endl;
		}
	}
	//wczytanie przedmiotow
	ifstream pliczek2("Przedmioty.txt");
	string nazwa1, prowadzacyimie, prowadzacynazwisko;
	int punkty;
	while (pliczek2 >> nazwa1 >> prowadzacyimie >> prowadzacynazwisko >> punkty) {
		Przedmiot b;
		Wykladowca c;
		b.Nazwa = nazwa1;
		c.imie = prowadzacyimie;
		c.nazwisko = prowadzacynazwisko;
		b.Prowadzacy = c;
		b.PunktyECTS = punkty;
		BazaPrzedmiotow[nazwa1] = b;
	}
	//wczytanie ogloszen
	ifstream pliczek3("Ogloszenia.txt");
	while (pliczek3 >> nazwa1) {
		Ogloszenia.push(nazwa1);
	}
	ifstream pliczekg("Grupy.txt");
	while (pliczekg >> nazwa1) {
		Grupa g;
		g.Licznosc = 0;
		BazaGrup[nazwa1] = g;
	}
	ifstream pliczek4("GrupyStudenci.txt");
	string imies, nazwiskos, nazwagrupy;
	while (pliczek4 >> imies >> nazwiskos >> nazwagrupy) {
		Student pom1;
		pom1.imie = imies;
		pom1.nazwisko = nazwiskos;
		BazaGrup[nazwagrupy].ListaStudentow.push_back(pom1);
		BazaGrup[nazwagrupy].Licznosc++;
	}
	string nazwap, nazwiskop;
	int punktyp;
	ifstream pliczek5("GrupyPrzedmioty.txt");
	while (pliczek5 >> nazwap >> nazwiskop >> punktyp >> nazwagrupy) {
		Przedmiot pom2;
		pom2.Nazwa = nazwap;
		pom2.Prowadzacy.nazwisko = nazwiskop;
		pom2.PunktyECTS = punktyp;
		BazaGrup[nazwagrupy].ListaPrzedmiotow.push_back(pom2);
	}
	ifstream pliczek6("Wykladowcy.txt");
	string imiew, nazwiskow;
	while (pliczek6 >> imiew >> nazwiskow) {
		Wykladowca w1;
		w1.imie = imiew;
		w1.nazwisko = nazwiskow;
		BazaWykladowcow[nazwiskow] = w1;
	}
	cout << "Pomyslnie zaimportowano dane. Aby kontynuowac, wpisz dowolne slowo, np OK\n";
	string c;
	cin >> c;

}
void Baza::SprawdzPunkty() {
	cout << "Podaj nazwisko studenta: ";
	string nazwiskos;
	cin >> nazwiskos;
	if (BazaStudentow.count(nazwiskos) == 0) {
		cout << "ERROR" << endl;
		cout << "Aby potwierdzic wpisz OK" << "\n";
		string a;
		cin >> a;
		return;
	}
	if (BazaStudentow[nazwiskos].punkty >= IlePunktowDoZdania) {
		cout << "Zaliczone.\n";
	}
	else {
		cout << "W trakcie zaliczania. Brakuje " << IlePunktowDoZdania - BazaStudentow[nazwiskos].punkty << endl;
	}
	cout << "Aby potwierdzic wpisz OK" << "\n";
	string a;
	cin >> a;
}
void Baza::MenuGrup() {
	system("cls");
	cout << "Wybierz operacje, jakiej chcesz dokonac:\n";
	cout << "1. Stworz nowa grupe\n";
	cout << "2. Dodaj przedmiot do grupy\n";
	cout << "3. Dodaj studenta do grupy\n";
	cout << "4. Wypisz szczegoly grupy\n";
	cout << "5. Edytuj grupe\n";
	int wybor;
	cin >> wybor;
	if (wybor == 1) {
		system("cls");
		Grupa a;
		cout << "Podaj nazwe grupy\n";
		string nazwagrupy;
		cin >> nazwagrupy;
		a.NazwaGrupy = nazwagrupy;
		BazaGrup[nazwagrupy] = a;
		cout << "Utworzono nowa grupe. Aby kontynuowac, wpisz OK" << endl;
		string c;
		cin >> c;

	}
	if (wybor == 2) {
		string nazwagrupy, nazwaprzedmiotu;
		cout << "Podaj nazwe grupy\n";
		cin >> nazwagrupy;
		cout << "Podaj nazwe przedmiotu\n";
		cin >> nazwaprzedmiotu;
		if (!BazaGrup.count(nazwagrupy) || !BazaPrzedmiotow.count(nazwaprzedmiotu)) {
			cout << "ERROR!\n";
			cout << "Aby kontynuowac, wpisz dowolne slowo, np OK\n";
			string c;
			cin >> c;
			return;
		}
		BazaGrup[nazwagrupy].DodajPrzedmiot(BazaPrzedmiotow[nazwaprzedmiotu]);
	}
	if (wybor == 3) {
		system("cls");
		string nazwagrupy, nazwiskostudenta;
		cout << "Podaj nazwe grupy\n";
		cin >> nazwagrupy;
		cout << "Podaj nazwisko studenta\n";
		cin >> nazwiskostudenta;
		if (!BazaGrup.count(nazwagrupy) || !BazaStudentow.count(nazwiskostudenta)) {
			cout << "ERROR!\n";
			cout << "Aby kontynuowac, wpisz dowolne slowo, np OK\n";
			string c;
			cin >> c;
			return;
		}
		BazaGrup[nazwagrupy].DodajStudenta(BazaStudentow[nazwiskostudenta]);
		BazaGrup[nazwagrupy].Licznosc++;
	}
	if (wybor == 4) {
		string nazwagrupy;
		cout << "Podaj nazwe grupy\n";
		cin >> nazwagrupy;
		if (!BazaGrup.count(nazwagrupy)) {
			cout << "ERROR!\n";
			cout << "Aby kontynuowac, wprowadz dowolne slowo, na przyklad OK:\n";
			string c;
			cin >> c;
			return;
		}
		BazaGrup[nazwagrupy].Wypisz();
	}
	if (wybor == 5) {
		cout << "Jesli chcesz zmienic nazwe grupy, wpisz 1\n";
		cout << "Jesli chcesz usunac grupe, wpisz 2\n";
		cout << "Jesli chcesz usunac studenta z grupy, wpisz 3\n";
		int p;
		cin >> p;
		system("cls");
		if (p == 1) {
			cout << "Podaj nazwe grupy, ktora chcesz edytowac:\n";
			string n;
			cin >> n;
			if (!BazaGrup.count(n)) {
				cout << "ERROR!\n";
				cout << "Aby kontynuowac, wprowadz dowolne slowo, na przyklad OK:\n";
				string c;
				cin >> c;
				return;
			}
			Grupa nowa;
			nowa = BazaGrup[n];
			BazaGrup.erase(n);
			cout << "Podaj nowa nazwe grupy:\n";
			cin >> n;
			nowa.NazwaGrupy = n;
			BazaGrup[n] = nowa;
			cout << "Grupe edytowano. Aby kontynuowac, wprowadz dowolne slowo, na przyklad OK:\n";
			string c;
			cin >> c;
			return;
		}
		else if (p == 2) {
			cout << "Podaj nazwe grupy:\n";
			string n;
			cin >> n;
			if (!BazaGrup.count(n)) {
				cout << "ERROR!\n";
				cout << "Aby kontynuowac, wprowadz dowolne slowo, na przyklad OK:\n";
				string c;
				cin >> c;
				return;
			}
			BazaGrup.erase(n);
			cout << "Grupe usunieto. Aby kontynuowac, Aby kontynuowac, wprowadz dowolne slowo, na przyklad OK:\n";
			string c;
			cin >> c;
			return;

		}
		else if (p == 3) {
			cout << "Podaj nazwisko studenta:\n";
			Student a;
			cin >> a.nazwisko;
			if (!BazaStudentow.count(a.nazwisko)) {
				cout << "ERROR!\n";
				cout << "Aby kontynuowac, wprowadz dowolne slowo, na przyklad OK:\n";
				string c;
				cin >> c;
				return;
			}
			cout << "Podaj nazwe grupy:\n";
			string ng;
			cin >> ng;
			if (!BazaGrup.count(ng)) {
				cout << "ERROR!\n";
				cout << "Aby kontynuowac, wprowadz dowolne slowo, na przyklad OK:\n";
				string c;
				cin >> c;
				return;
			}
			BazaGrup[ng].UsunStudenta(a);
		}
		else {
			cout << "ERROR!\n";
			cout << "Aby kontynuowac, wprowadz dowolne slowo, na przyklad OK:\n";
			string c;
			cin >> c;
			return;
		}
	}

}
void Baza::MenuStudentow() {
	system("cls");
	cout << "1. Dodaj studenta\n";
	cout << "2. Edytuj studenta\n";
	cout << "3. Usun Studenta\n";
	int wybor;
	cin >> wybor;
	system("cls");
	if (wybor == 1) {
		cout << "Podaj imie:\n";
		Student a1;
		cin >> a1.imie;
		cout << "Podaj nazwisko:\n";
		cin >> a1.nazwisko;
		cout << "Podaj adres (pojedyncze slowo wyrazajace ulice zamieszkania):\n";
		//getline(cin, a.adres);
		cin >> a1.adres;
		BazaStudentow[a1.nazwisko] = a1;
		cout << "Pomyslnie dodano studenta. Aby kontynuowac, wprowadz dowolne slowo, np OK\n";
		string c1;
		cin >> c1;
	}
	if (wybor == 2) {
		cout << "Podaj nazwisko studenta, ktorego chcesz edytowac\n";
		Student a2;
		cin >> a2.nazwisko;
		if (!BazaStudentow.count(a2.nazwisko)) {
			cout << "ERROR! Aby kontynuowac, wpisz dowolne slowo, np OK:\n";
			string q;
			cin >> q;
			return;
		}
		a2 = BazaStudentow[a2.nazwisko];
		BazaStudentow.erase(a2.nazwisko);
		cout << "1. Zmiana ulicy zamieszkania.\n";
		cout << "2. Zmiana nazwiska.\n";
		cout << "3. Zmiana imienia\n";
		int wybor2;
		cin >> wybor2;
		system("cls");
		if (wybor2 == 1) {
			cout << "Podaj nowa ulice zamieszkania:\n";
			cin >> a2.adres;
		}
		if (wybor2 == 2) {
			cout << "Podaj nowe nazwisko:\n";
			cin >> a2.nazwisko;
		}
		if (wybor2 == 3) {
			cout << "Podaj nowe imie:\n";
			cin >> a2.imie;
		}
		BazaStudentow[a2.nazwisko] = a2;
		cout << "Pomyslnie edytowano. Aby kontynuowac, wprowadz dowolne slowo, np OK\n";
		string c2;
		cin >> c2;
	}
	if (wybor == 3) {
		cout << "Podaj nazwisko studenta, ktorego chcesz usunac\n";
		Student a3;
		cin >> a3.nazwisko;
		if (!BazaStudentow.count(a3.nazwisko)) {
			cout << "ERROR! Aby kontynuowac, wprowadz dowolne slowo, np OK\n";
			string c3;
			cin >> c3;
			return;
		}
		BazaStudentow.erase(a3.nazwisko);
		cout << "Pomyslnie usunieto. Aby kontynuowac, wprowadz dowolne slowo, np OK\n";
		string c4;
		cin >> c4;
	}
}
void Baza::DodajOgloszenie() {
	string nowe;
	cout << "Podaj tresc ogloszenia: ";
	//getline(cin, nowe); 
	//odkomowac potem!
	cin >> nowe;
	Ogloszenia.push(nowe);
	ofstream pliczek("Ogloszenia.txt", std::ios::app);
	pliczek << nowe << "\n";
	cout << "Dodano Ogloszenie. \nAby kontynuowac, wprowadz dowolne slowo, na przyklad OK:\n";
	string c;
	cin >> c;
	system("cls");
}
void Baza::PrzeczytajOgloszenia() {
	int wlk = Ogloszenia.size();
	while (wlk > 0) {
		string OgloszenieAktualne;
		OgloszenieAktualne = Ogloszenia.front();
		Ogloszenia.push(OgloszenieAktualne);
		Ogloszenia.pop();
		wlk--;
		cout << OgloszenieAktualne << endl;
	}
	string p;
	cout << "Aby wyjsc z menu ogloszen, wpisz OK" << endl;
	cin >> p;
	//system("cls");
}
void Baza::PrzyznajPunkty() {
	system("cls");
	string nazwiskostudenta, nazwaprzedmiotu;
	cout << "Podaj nazwisko studenta i przedmiot (oddziel enterami)\n";
	cin >> nazwiskostudenta >> nazwaprzedmiotu;
	if (!BazaStudentow.count(nazwiskostudenta) || !BazaPrzedmiotow.count(nazwaprzedmiotu)) {
		cout << "ERROR!\n";
		cout << "Aby kontynuowac, wprowadz dowolne slowo, na przyklad OK:\n";
		string c;
		cin >> c;
		return;
	}
	BazaStudentow[nazwiskostudenta].punkty += BazaPrzedmiotow[nazwaprzedmiotu].PunktyECTS;
	cout << "Punkty przyznano.\nAby kontynuowac, wprowadz dowolne slowo, na przyklad OK:\n";
	string c;
	cin >> c;
}
void Baza::DodajOcene() {
	system("cls");
	cout << "Podaj prosze nazwisko studenta, nazwe przedmiotu\n";
	string nazwisko, nazwaprzedmiotu;
	//	int ocena;
	cin >> nazwisko >> nazwaprzedmiotu;
	if (!BazaStudentow.count(nazwisko) || !BazaPrzedmiotow.count(nazwaprzedmiotu)) {
		cout << "ERROR!\n";
		cout << "Aby kontynuowac, wprowadz dowolne slowo, na przyklad OK:\n";
		string c;
		cin >> c;
		return;
	}
	BazaStudentow[nazwisko].DodajOcene(BazaPrzedmiotow[nazwaprzedmiotu]);
	//system("cls");
}
void Baza::START() {
	Menu_Domyslne M3;
	Menu_Studenta M1;
	system("cls");
	if (zalogowany.ranga == "student") {
		cout << "RANGA STUDENT\n";
		int wybor = M1.Wypisz();
		//Student AktualnyStudent;
		//AktualnyStudent = BazaStudentow[zalogowany.login];
		if (wybor == 1) {
			(BazaStudentow[zalogowany.nazwisko]).PodgladOcen();
		}
		if (wybor == 2) {
			if (BazaStudentow[zalogowany.nazwisko].punkty >= IlePunktowDoZdania) {
				cout << "Zaliczone.\n";
			}
			else {
				cout << "W trakcie zaliczania. Brakuje " << IlePunktowDoZdania - BazaStudentow[zalogowany.nazwisko].punkty << endl;
			}
			cout << "Aby potwierdzic wpisz OK" << "\n";
			string a;
			cin >> a;
			system("cls");
		}
		if (wybor == 3) {
			DodajOgloszenie();
		}
		if (wybor == 4) {
			PrzeczytajOgloszenia();
		}
		if (wybor == 5) {
			czyzal = 0;
			return;
		}
	}

	else if (zalogowany.ranga == "dziekanat") {
		cout << "UPRAWNIENIA DZIEKANATU\n";
		int wybor = M3.Wypisz();
		if (wybor == 1) {
			MenuStudentow();
		}
		if (wybor == 2) {
			MenuPrzedmiotow();
		}
		if (wybor == 3) {
			DodajOgloszenie();
		}
		if (wybor == 4) {
			PrzeczytajOgloszenia();
		}
		if (wybor == 5) {
			DodajZPliku();
		}
		if (wybor == 6) {
			DodajOcene();
		}
		if (wybor == 7) {
			PrzyznajPunkty();
		}
		if (wybor == 8) {
			MenuGrup();
		}
		if (wybor == 9) {
			SprawdzPunkty();
		}
		if (wybor == 10) { //zapis wszystkiego do plikow txt
			ZapiszDoPliku();
		}
		if (wybor == 12) {
			czyzal = 0;
			return;
		}
		if (wybor == 11) {
			MenuWykladowcow();
		}
	}
}

