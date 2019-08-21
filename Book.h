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
	/**
	Show information about this book
	*/
	void show_self();
	unsigned int get_con();
	void set_con(unsigned int ID);
	unsigned int get_ID();
	Book();
	Book(unsigned int id);
	~Book();
};

