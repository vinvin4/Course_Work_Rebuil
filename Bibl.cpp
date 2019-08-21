#include "Bibl.h"
/**
Update vector's size
*/
void Bibl::update_size()
{
	size = bibl.size();
}
/**
New book in vector
*/
void Bibl::add()
{
	Book* book = new Book(ID++);
	bibl.push_back(*book);
	update_size();
}
/**
Show list of books
*/
void Bibl::show_all()
{
	setlocale(LC_ALL, "RUS");
	std::cout << "ID\tCon \t\tЌазвание\tјвтор \n\n";
	for (int i = 0; i < this->size; i++)
	{
		bibl[i].show_self();
	}
	std::cout << std::endl;
}
/**
Cheching existing book with Param:ID
Return: Position in list
*/
int Bibl::check_ID(unsigned int id)
{
	int j = 0;
	while (bibl[j].get_ID() != id && j < this->size)
	{
		j++;
	}

	if (j != this->size)
	{
		return j;
	}
	else
	{
		return -1;
	}
}
/**
FInding book by ID
*/
void Bibl::search_ID()
{
	unsigned int id;
	setlocale(LC_ALL, "RUS");
	std::cout << "¬веди ID книги: ";
	std::cin >> id;
	int j = check_ID(id);
	if (j != -1)
	{
		bibl[j].show_self();
	}
	else
	{
		failure();
	}
	setlocale(LC_ALL, "RUS");
	std::cout << std::endl;
}
/**
Delete book by ID
*/
void Bibl::delete_per()
{
	setlocale(LC_ALL, "RUS");
	std::cout << "¬ведите ID книги, которую хотите удалить: ";
	unsigned int id;
	std::cin >> id;

	int j = check_ID(id);
	if (j != -1)
	{
		bibl.erase(bibl.begin() + j);
	}
	else
	{
		failure();
	}
	this->update_size();
}
/**
Connecting book with reader
*/
void Bibl::new_reader()
{
	unsigned int id;
	setlocale(LC_ALL, "RUS");
	std::cout << "¬веди ID книги: ";
	std::cin >> id;
	int j = check_ID(id);
	if (j != -1)
	{
		std::cout << "¬веди ID читател€: ";
		std::cin >> id;
		bibl[j].set_con(id);
	}
	else
	{
		failure();
	}
	std::cout << std::endl;
}
/**
Message for users. Book by ID was not found
*/
void Bibl::failure()
{
	setlocale(LC_ALL, "RUS");
	std::cout << " ниги с таким ID ещЄ нет" << std::endl;
}

Bibl::Bibl()
{
	this->update_size();
	ID = 1;
}

Bibl::~Bibl()
{
}