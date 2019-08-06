#include "Chitatel.h"
/**
Formal showing information of reader
*/
void Chitatel::show_self()
{
	setlocale(LC_ALL, "C");
	std::cout << this->ID << " ";//����� �� ����� ID �������� � �������
	printf("%30s\t", this->name); //����� ����� ��������+���������. ������� 30 ��������
	std::cout << this->phone 
		<<std::endl;//������� �� ����� ������	
}

unsigned int Chitatel::getID()
{
	return ID;
}

Chitatel::Chitatel()
{
}
/**
Creating new reader
Param: i - reader's ID
*/
Chitatel::Chitatel(unsigned int i)
{
	setlocale(LC_ALL, "RUS");//����������� �����
	std::cout << "\n������� ��� ��������: ";//����� ����������� ������
	do
		std::cin.getline(this->name, N_name);//���� ������
	while (this->name[0] == 0);//���������� ��������� ����� ���������
	std::cout << "������� ������� ��������: ";
	do
		std::cin.getline(this->phone, N_phone);
	while (this->phone[0] == 0);
	this->ID = i;
	std::cout << std::endl;//������� �� ����� ������
}

Chitatel::~Chitatel()
{
}
