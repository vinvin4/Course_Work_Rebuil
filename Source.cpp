#include <conio.h>
#include <string>
#include <fstream>
#include "People.h"
#include "Bibl.h"
#define M 9//����������, ������������ ��� ���������� ����
#define Up_Click 72//��� ������� "�����"
#define Down_Click 80//��� ������� "����"
#define Enter_Click 13//��� ������� "Enter"
#define Usual_keyboard 224
#define Extra_Keyboard 0
//������ � ���������� ��������
short key = 0; //����������-������� ��� ������ � ��������������
char map[M]; //������-����� ��� ������ � ��������������
bool graph = true; //���� ��� ������ ���������� �������
////////////////
void information()
{
	setlocale(LC_ALL, "RUS");
	std::cout << "��� �������������� ����, ������������!\n\n"
		<< "������ � ���������� �������������� ����� ��������� �� ����� �� ���������, \n�.�. ����������� ��� ��������������\n"
		<< "�������� ������ ���������� ����� ������� �������� ������� (>). \n������� ���������� ������ ��� ��� ���������� ����-������ � �������\n"
		<< "������ ����������� � �����, ������ ���������� ���� �� ������. \n��� ���������� ������� ���� ������ ���������� � �������������\n"
		<< "�������� ������. ����� �����!\n";
}
///////////////
int main()
{	
	People* people = new People();
	Bibl* library = new Bibl();

	bool fl = true;//����������-����, ���������� �� ������ �����-����
	//�������� ���� ������ ��� ������������
	while (fl == true)//���� ������ ����� ��������, ���� ���� ������
	{
		setlocale(LC_ALL, "RUS");
		while (graph == true)
		{
			system("cls");
			for (int k = 0; k < M; k++)
				map[k] = '.';
			map[key] = '>';//���������� ��������� ��� ������ ������ ����
			std::cout <<map[0]<<" �������� ����� ��������������\n"
				<<map[1]<< " �������� ������ ��������\n"
				<<map[2]<< " �������� ���� ���������\n"
				<<map[3]<< " ����� �������� �� ID\n"
				<<map[4]<< " �������� �������� �� ID\n"
				<<map[5]<< " �������� ����� � �����\n"
				<<map[6]<< " �������� ������ ����\n"
				<<map[7]<< " ������� �����\n"
				<<map[8]<< " �������� ����/������ �����\n";
			switch (_getch())
			{
			case Usual_keyboard://� ������, ���� ������������ ������� �� ����������� ����������...
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
			case Extra_Keyboard://� ������, ���� ������������ ������� �� �������������� ����������
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
			graph = false;//�������� ���� ��� ������ � ��������
			break;
			}
			}
		}	
		graph = true;//��������� ���� ��� ������� ������ � ����
		switch (key)//�������� ������; �������� ������ �� ����
		{
		case 0://����� ���������� ������������ ��� ���������� ������ ���������
		{
			information();
			break;
		}
		case 1://���������� ��������
		{
			people->add();
			break;
		}
		case 2://�������� ���� ���������
		{
			people->show_all();
			break;
		}
		case 3://����� �������� �� ID
		{
			people->search_ID();
			break;
		}
		case 4://������� ��������
		{
			people->delete_per();
			break;
		}
		case 5://�������� �����
		{
			library->add();
			break;
		}
		case 6://�������� ��� ��������� �����
		{
			library->show_all();
			break;
		}
		case 7://�������� �����
		{
			library->delete_per();
			break;
		}
		case 8://������� �������� � �����
		{
			library->new_reader();
			break;
		}
		}
		setlocale(LC_ALL, "RUS");
		key = 0;
		while (graph == true)				
		{
			std::cout << "���������� ������ � �����������?" << std::endl;//����������� ���������� ������ � ����� ������
			for (int k = 0; k < 2; k++)//������������ ����
				map[k] = '.';
			map[key] = '>';//���������� ��������� ��� ������ ������ ����
			std::cout << map[0] << " ��\n"
				<< map[1] << " ���\n";
			switch (_getch())
			{
			case Usual_keyboard://� ������, ���� ������������ ������� �� ����������� ����������...
			{
				switch (_getch())
				{
				case Up_Click:
				{
					if (key==1) { key--; }//���� ������� ������� �� ����� �������, ������� ������ �� ���� �����
					break;
				}
				case Down_Click:
				{
					if (key==0) { key++; }//���� ������� ������� �� ����� ������, �������� ������ �� ���� �����
					break;
				}
				}
				break;
			}
			case Extra_Keyboard://� ������, ���� ������������ ������� �� �������������� ����������
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
				graph = false;//�������� ���� ��� ������ � ��������
				break;
			}			 
			}
			system("cls"); //���� ������ ����� ������ ������� - ������� ����� ��� ������ � ��������
		}
		graph = true;//��������� ���� ��� ������� ������ � ����
		if (key==1)//���� ������� ����� - ���� ����������. ���� �������. ����� ������ �����������
			fl = false;//���� ����������
	}
	return 0;
}