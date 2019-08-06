#include "Book.h"

void Book::show_self()
{
	setlocale(LC_ALL, "C");
	std::cout << this->ID << "\t"
		<< this->con << " ";
	printf("%30s  ", this->caption);
	std::cout << this->authoor << std::endl;
}

unsigned int Book::getCon()
{
	return con;
}

void Book::setCon(unsigned int ID)
{
	con = ID;
}

unsigned int Book::getID()
{
	return ID;
}

Book::Book()
{
	
}

Book::Book(unsigned int id)
{
	setlocale(LC_ALL, "RUS");
	std::cout << "\n¬ведите название книги: ";
	do
		std::cin.getline(this->caption, Lenght);
	while (this->caption[0] == 0);
	std::cout << "¬ведите фамилию автора книги: ";
	do
		std::cin.getline(this->authoor, Lenght);
	while (this->caption[0] == 0);
	this->con = 0;
	this->ID =id;
}

Book::~Book()
{
}
