#pragma once
#include <vector>
#include <iostream>
#include "Book.h"

class Bibl
{
private:
	std::vector<Book> bibl;
	int size;
	void updateSize();
	unsigned int ID; //Counter of new ID
	void failure();
	int check_ID(unsigned int id);

public:
	void add();
	void show_all();	
	void search_ID();
	void delete_per();
	void new_reader();
	
	Bibl();
	~Bibl();
};

