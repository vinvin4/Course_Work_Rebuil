#include <conio.h>
#include <string>
#include <fstream>
#include "People.h"
#include "Bibl.h"
#define M 9//Variable for menu-UI
#define Up_Click 72
#define Down_Click 80
#define Enter_Click 13
#define Usual_keyboard 224
#define Extra_Keyboard 0
///Working with UI
short key = 0; 
char map[M]; 
bool graph = true; 
/**
Print general information for user
*/
void information()
{
	setlocale(LC_ALL, "RUS");
	std::cout << "Рад приветствовать тебя, пользователь!\n\n"
		<< "Работа с программой осуществляется через стрелки на любой из клавиатур, \nт.е. стандартной или дополнительной\n"
		<< "Очищение экрана происходит после каждого движения курсора (>). \nСоветую записывать важную для Вас информацию куда-нибудь в блокнот\n"
		<< "Данные сохраняются в файлы, утечки информации быть не должно. \nДля расширения функций Базы данных обратитесь к производителю\n"
		<< "Приятной работы. Желаю удачи!\n";
}
///////////////
int main()
{	
	People* people = new People();
	Bibl* library = new Bibl();

	bool fl = true;

	while (fl == true)//Database will work, while fl==true
	{
		setlocale(LC_ALL, "RUS");
		while (graph == true)
		{
			system("cls");
			for (int k = 0; k < M; k++)
				map[k] = '.';
			map[key] = '>';
			std::cout <<map[0]<<" Прочесть перед использованием\n"
				<<map[1]<< " Добавить нового читателя\n"
				<<map[2]<< " Показать всех читателей\n"
				<<map[3]<< " Поиск читателя по ID\n"
				<<map[4]<< " Удаление читателя по ID\n"
				<<map[5]<< " Добавить книгу в архив\n"
				<<map[6]<< " Показать список книг\n"
				<<map[7]<< " Удалить книгу\n"
				<<map[8]<< " Читатель взял/вернул книгу\n";
			switch (_getch())
			{
			case Usual_keyboard: //Button codded by two values.
			{
				switch (_getch())
				{
				case Up_Click:
				{
					if (key > 0) { key--; }
					break;
				}
				case Down_Click:
				{
					if (key < M-1) { key++; }
					break;
				}
				}
			break;
			}
			case Extra_Keyboard:
			{
				switch (_getch())
				{
				case Up_Click:
				{
					if (key > 0) { key--; }
					break;
				}
				case Down_Click:
				{
					if (key < M-1) { key++; }
				break;
				}
				}
			break;
			}
			case Enter_Click:
			{
			graph = false;//Опускаем флаг для работы с графикой
			break;
			}
			}
		}	
		graph = true;
		switch (key)//
		{
		case 0://Print info
		{
			information();
			break;
		}
		case 1://Add reader
		{
			people->add();
			break;
		}
		case 2://Show all readers
		{
			people->show_all();
			break;
		}
		case 3://Finding reader by ID
		{
			people->search_ID();
			break;
		}
		case 4://Delete reader
		{
			people->delete_per();
			break;
		}
		case 5://Add book
		{
			library->add();
			break;
		}
		case 6://Show all book
		{
			library->show_all();
			break;
		}
		case 7://Delete book
		{
			library->delete_per();
			break;
		}
		case 8://Connect reader and book
		{
			library->new_reader();
			break;
		}
		}
		setlocale(LC_ALL, "RUS");
		key = 0;
		while (graph == true)				
		{
			std::cout << "Продолжить работу с библиотекой?" << std::endl;
			for (int k = 0; k < 2; k++)
				map[k] = '.';
			map[key] = '>';
			std::cout << map[0] << " Да\n"
				<< map[1] << " Нет\n";
			switch (_getch())
			{
			case Usual_keyboard://В случае, если используются стрелки на стандартной клавиатуре...
			{
				switch (_getch())
				{
				case Up_Click:
				{
					if (key==1) { key--; }//Если позиция стрелки не самая верхняя, поднять курсор на один пункт
					break;
				}
				case Down_Click:
				{
					if (key==0) { key++; }//Если позиция стрелки не самая нижняя, опустить курсор на один пункт
					break;
				}
				}
				break;
			}
			case Extra_Keyboard://В случае, если используются стрелки на дополнительной клавиатуре
			{
				switch (_getch())
				{
				case Up_Click:
				{
					if (key==1) { key--; }
					break;
				}
				case Down_Click:
				{
					if (key==0) { key++; }
					break;
				}
				}
				break;
			}
			case Enter_Click:
			{
				graph = false;//Опускаем флаг для работы с графикой
				break;
			}			 
			}
			system("cls"); 
		}
		graph = true;
		if (key == 1)
			fl = false;
	}
	return 0;
}