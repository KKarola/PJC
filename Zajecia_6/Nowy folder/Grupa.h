#pragma once
#include "Student.h"
#include "Przedmiot.h"
#include <vector>
using namespace std;
class Grupa
{
public:
	vector <Student> ListaStudentow;
	vector <Przedmiot> ListaPrzedmiotow;
	int Licznosc;
	string NazwaGrupy;
	void DodajStudenta(Student a);
	void DodajPrzedmiot(Przedmiot a);
	void Wypisz();
	void UsunStudenta(Student a);
};

