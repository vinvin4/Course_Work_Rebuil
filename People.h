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
/**
Update vector's size
*/
	void update_size();
	/**
	Search name with same ID
	param: unsigned int - needed ID
	Return: int - position in vector
	*/
	int check_ID(unsigned int);

	unsigned int ID;//Counter of new ID
	/*
	Print general information
	*/
	void failure();

	unsigned int read_file(); //Working...

	void write_file(); //Working...

public:	
	/*
	Show information about object with needed ID
	*/
	void search_ID();
	/*
	Delete some reader*/
	void delete_per();
	/*
	Add new reader*/
	void add();
	/*
	Show all readers*/
	void show_all();

	People();
	~People();
};

