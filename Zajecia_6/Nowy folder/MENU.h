#pragma once
#include <iostream>
#include "Student.h"
#include  "Uzytkownicy.h"
using namespace std;

class Menu_Nieznane 
{
public:
	virtual int Wypisz() = 0;
};

class Menu_Domyslne : public Menu_Nieznane 
{
public:
	virtual int Wypisz() override;
};


class Menu_Studenta : public Menu_Nieznane 
{
public:
	virtual int Wypisz() override;
};








