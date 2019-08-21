#include "People.h"

void People::update_size()
{
	size = vector_chit.size();
}

int People::check_ID(unsigned int id)
{
	int j = 0;
	while (vector_chit[j].get_ID() != id && j < this->size)
	{
		j++;
	}

	return j != this->size ? j : -1;
}
/**
Show information about reader with concrete ID
*/
void People::search_ID()
{
	unsigned int id;
	setlocale(LC_ALL, "RUS");
	std::cout << "Введи ID читателя: ";
	std::cin >> id;
	int j = check_ID(id);
	j != -1 ? vector_chit[j].show_self() : failure();
	setlocale(LC_ALL, "RUS");
	std::cout << std::endl;
}

void People::delete_per()
{
	setlocale(LC_ALL, "RUS");
	std::cout << "Введите ID читателя, которого хотите удалить: ";
	unsigned int id;
	std::cin >> id;

	int j = check_ID(id);
	if (j != -1)
	{
		vector_chit.erase(vector_chit.begin() + j);
	}
	else
	{
		failure();
	}
	this->update_size();
}

void People::add()
{
	Chitatel* chit = new Chitatel(ID++);
	vector_chit.push_back(*chit);
	this->update_size();
	write_file();
}

void People::show_all()
{
	setlocale(LC_ALL, "RUS");
	std::cout << "\nID\t\t\tИмя\t\tТелефон\n\n"; //Оформление вывода данных
	for (unsigned int i = 0; i < this->size; i++)
	{
		vector_chit[i].show_self();
	}
}

/**
Person was not found
*/
void People::failure()
{
	setlocale(LC_ALL, "RUS");
	std::cout << "Читателя с таким ID ещё нет" << std::endl;
}

unsigned int People::read_file()
{
	return 0;
}

void People::write_file()
{
	//
}

People::People()
{
	ID = 1;
	size = 0;
}


People::~People()
{
}
