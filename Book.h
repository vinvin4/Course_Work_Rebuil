#pragma once
#define Lenght 40
#include <iostream>
#include <locale.h>

class Book
{
private:
	char caption[Lenght];
	char authoor[Lenght];
	unsigned int con;
	unsigned int ID;
public:
	void show_self();
	unsigned int getCon();
	void setCon(unsigned int ID);
	unsigned int getID();
	Book();
	Book(unsigned int id);
	~Book();
};

