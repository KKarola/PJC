#pragma once 
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Przedmiot.h"
using namespace std;
class Student //template <typename T> Student
{
public:
	string imie;
	string nazwisko;
	string adres;
	map <string, vector<short int> > ListaOcen;
	void ZmienDane();
	void DodajOcene(Przedmiot a);
	void PodgladOcen(); 
	bool zdaje;
	int punkty;
	Student() {
		zdaje = 0;
		punkty = 0;
	}
};






