#include "MENU.h"
#include "stdafx.h"
using namespace std;

int Menu_Domyslne :: Wypisz() {
	//menu dla dziekanatu
	int wybor;
	cout << "Wybierz opcje:\n";
	cout << "1. Menu Studentow.\n";
	cout << "2. Menu Przedmiotow\n";
	cout << "3. Dodaj Ogloszenie\n";
	cout << "4. Przeczytaj Ogloszenia\n";
	cout << "5. Odtworz z bazy danych .txt\n";
	cout << "6. Dodaj ocene studentowi.\n";
	cout << "7. Przyznaj punkty ECTS za przedmiot studentowi\n";
	cout << "8. Menu Grup Studenckich\n";
	cout << "9. Sprawdz, czy student ma wystarczajaca ilosc punktow ECTS\n";
	cout << "10. Zapisz do bazy danych .txt\n";
	cout << "11. Menu Wykladowcow\n";
	cout << "12. Wyloguj\n";
	cin >> wybor;
	if (wybor > 12 || wybor < 0) {
		cout << "ERROR!";
		return 0;
	}
	system("cls");
	return wybor;

}

int Menu_Studenta::Wypisz() {
	int wybor;
	cout << "Wybierz opcje:\n";
	cout << "1. Sprawdz oceny z przedmiotow.\n";
	cout << "2. Sprawdz liczbe punktow ECTS\n";
	cout << "3. Dodaj Ogloszenie\n";
	cout << "4. Przeczytaj Ogloszenia\n";
	cout << "5. Wyloguj\n";
	cin >> wybor;
	if (wybor > 5 || wybor < 0) {
		cout << "ERROR!";
		return 0;
	}
	system("cls");
	return wybor;
	system("cls");
}
