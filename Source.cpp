#include <conio.h>
#include <string>
#include <fstream>
#include "People.h"
#include "Bibl.h"
#define M 9//Переменная, используемая для оформления меню
#define Up_Click 72//Код клавиши "Вверх"
#define Down_Click 80//Код клавиши "Вниз"
#define Enter_Click 13//Код клавиши "Enter"
#define Usual_keyboard 224
#define Extra_Keyboard 0
//Работа с консольной графикой
short key = 0; //Переменная-счётчик для работы с псевдографикой
char map[M]; //Массив-карта для работы с псевдографикой
bool graph = true; //Флаг для работы консольной графики
////////////////
void information()
{
	setlocale(LC_ALL, "RUS");
	std::cout << "Рад приветствовать тебя, пользователь!\n\n"
		<< "Работа с программой осуществляется через стрелочки на любой из клавиатур, \nт.е. стандартной или дополнительной\n"
		<< "Очищение экрана происходит после каждого движения курсора (>). \nСоветую записывать важную для Вас информацию куда-нибудь в блокнот\n"
		<< "Данные сохраняются в файлы, утечки информации быть не должно. \nДля расширения функций Базы данных обратитесь к производителю\n"
		<< "Приятной работы. Желаю удачи!\n";
}
///////////////
int main()
{	
	People* people = new People();
	Bibl* library = new Bibl();

	bool fl = true;//Переменная-флаг, отвечающая за работу цикла-меню
	//Создание меню выбора для пользователя
	while (fl == true)//База данных будет работать, пока флаг поднят
	{
		setlocale(LC_ALL, "RUS");
		while (graph == true)
		{
			system("cls");
			for (int k = 0; k < M; k++)
				map[k] = '.';
			map[key] = '>';//Постановка указателя для выбора пункта меню
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
			case Usual_keyboard://В случае, если используются стрелки на стандартной клавиатуре...
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
			case Extra_Keyboard://В случае, если используются стрелки на дополнительной клавиатуре
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
		graph = true;//Поднимаем флаг для будущей работы с меню
		switch (key)//Оператор выбора; Значение берётся из меню
		{
		case 0://Вывод информации пользователю для корректной работы программы
		{
			information();
			break;
		}
		case 1://Добавление читателя
		{
			people->add();
			break;
		}
		case 2://Показать всех читателей
		{
			people->show_all();
			break;
		}
		case 3://Поиск читателя по ID
		{
			people->search_ID();
			break;
		}
		case 4://Удалить читателя
		{
			people->delete_per();
			break;
		}
		case 5://Добавить книгу
		{
			library->add();
			break;
		}
		case 6://Показать все имеющиеся книги
		{
			library->show_all();
			break;
		}
		case 7://Удаление книги
		{
			library->delete_per();
			break;
		}
		case 8://Связать читателя и книгу
		{
			library->new_reader();
			break;
		}
		}
		setlocale(LC_ALL, "RUS");
		key = 0;
		while (graph == true)				
		{
			std::cout << "Продолжить работу с библиотекой?" << std::endl;//Предложение прекратить работу с Базой данных
			for (int k = 0; k < 2; k++)//Резаполнение поля
				map[k] = '.';
			map[key] = '>';//Постановка указателя дял выбора пункта меню
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
			system("cls"); //Если нажата любая другая клавиша - стираем экран для работы с графикой
		}
		graph = true;//Поднимаем флаг для будущей работы с меню
		if (key==1)//Если получен отказ - флаг опускается. Цикл окончен. Иначе работа продолжится
			fl = false;//Флаг опускается
	}
	return 0;
}