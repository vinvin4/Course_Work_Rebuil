#include "Chitatel.h"
/**
Formal showing information of reader
*/
void Chitatel::show_self()
{
	setlocale(LC_ALL, "C");
	std::cout << this->ID << " ";//Вывод на экран ID читателя и пробела
	printf("%30s\t", this->name); //Вывод имени читателя+табуляция. Минимум 30 символов
	std::cout << this->phone 
		<<std::endl;//Переход на новую строку	
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
	setlocale(LC_ALL, "RUS");//Локализация языка
	std::cout << "\nВведите имя читателя: ";//Вывод константной строки
	do
		std::cin.getline(this->name, N_name);//Ввод строки
	while (this->name[0] == 0);//Исключение возможных багов программы
	std::cout << "Введите телефон читателя: ";
	do
		std::cin.getline(this->phone, N_phone);
	while (this->phone[0] == 0);
	this->ID = i;
	std::cout << std::endl;//Переход на новую строку
}

Chitatel::~Chitatel()
{
}
