#include "People.h"
/**
Update vector's size
*/
void People::updateSize()
{
	size = vector_chit.size();
}

int People::check_ID(unsigned int id)
{
	int j = 0;
	while (vector_chit[j].getID() != id && j < this->size)
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
	std::cout << "����� ID ��������: ";
	std::cin >> id;
	int j = check_ID(id);
	j != -1 ? vector_chit[j].show_self() : failure();
	setlocale(LC_ALL, "RUS");
	std::cout << std::endl;
}

void People::delete_per()
{
	setlocale(LC_ALL, "RUS");
	std::cout << "������� ID ��������, �������� ������ �������: ";
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
	this->updateSize();
}

void People::add()
{
	Chitatel* chit = new Chitatel(ID++);
	vector_chit.push_back(*chit);
	this->updateSize();
	write_file();
}

void People::show_all()
{
	setlocale(LC_ALL, "RUS");
	std::cout << "\nID\t\t\t���\t\t�������\n\n"; //���������� ������ ������
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
	std::cout << "�������� � ����� ID ��� ���" << std::endl;
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
