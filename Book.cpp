#include "Book.h"

void Book::show_self()
{
	setlocale(LC_ALL, "C");
	std::cout << this->ID << "\t"
		<< this->con << " ";
	printf("%30s  ", this->caption);
	std::cout << this->authoor << std::endl;
}
//*Getter
unsigned int Book::get_con()
{
	return con;
}
//*Setter
void Book::set_con(unsigned int ID)
{
	con = ID;
}
//*Getter
unsigned int Book::get_ID()
{
	return ID;
}

Book::Book()
{
	
}

Book::Book(unsigned int id)
{
	setlocale(LC_ALL, "RUS");
	std::cout << "\n������� �������� �����: ";
	do
		std::cin.getline(this->caption, Lenght);
	while (this->caption[0] == 0);
	std::cout << "������� ������� ������ �����: ";
	do
		std::cin.getline(this->authoor, Lenght);
	while (this->caption[0] == 0);
	this->con = 0;
	this->ID =id;
}

Book::~Book()
{
}
