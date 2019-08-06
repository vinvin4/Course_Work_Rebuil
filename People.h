#pragma once
#include "Chitatel.h"
#include <fstream>
#include <vector>
#include <conio.h>

class People 
{
private:
	std::vector <Chitatel> vector_chit;
	int size;
	void updateSize();
	int check_ID(unsigned int);
	unsigned int ID;//Counter of new ID
	void failure();
	unsigned int read_file();
	void write_file();
public:	
	void search_ID();
	void delete_per();

	void add();
	void show_all();

	People();
	~People();
};

