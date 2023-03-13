#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
// ������� ������������ ����� "�������" � ��������� ������������� �������, ���������� �������� � ������� � ���������� �������� �� �������.
// ������� ����� �������� ����� �������. ����������� ������ ����� ����� ��������� ������ ���������, 
// ��������� �� ���������(����� ���������) �������� �������.������� ���������� ��������� ������ ���� ��������.
// ������� ������� ������� ���� ��������. ����������� ������ ���� �������,
// ��������� ��������� ������ ������� � ������ �������.������� ���������� ��������� ������ ���� ��������.
// �� ������ ������������� ������ "�������" ������� �������� ����� "�������1" �
// ��������� ���������� � ����������� �� ������ ���������� � ������������ � ���������������� ��������(��.������� ����).

// 17 - ���������� ������� ��������, �������� �������� ���������������

#include "Header.h"
#include "heir.h"

void Choice(std::string*, int, int, QueueHeir);
void ShowCommands();

int main() {
	setlocale(LC_ALL, "Russian");
	
	int number = 0; // ���������� ������ ��������
	QueueHeir group1 = QueueHeir(); // ����� ������ ������

	// ������ ���������
	int x = 0; // ��������� ��� �� ���������
	std::string* mass = new std::string[x];
	
	Choice(mass, number, x, group1);
}


void Choice(std::string *mass, int number, int x, QueueHeir group1) {
	
	ShowCommands();
	std::cout << "=> ";
	std::cin >> number; // �������� ��������

	if (number == 1) { // ������������ - ����� ����� ����� ������ ������������� (��� ��������)
		std::string someElement; // ����� ������� �������
		std::cout << "����� ���������� ��������" << std::endl;
		std::cout << "������� �������� (�� ����������)" << std::endl;
		std::cin >> someElement;
		
		if (x > 0) 
		{
			std::string* Tmass = new std::string[x];
			for (int i = 0; i < x; i++) {
				Tmass[i] = mass[i]; // ��������� ��������� ������
			}
			delete []mass;

			x++; // ����������� ���������� ��������� �������
			std::string* mass = new std::string[x]; // �������������� ������
			for (int i = 0; i < x - 1; i++) {
				mass[i] = Tmass[i]; // ��������� ��������� ������ 
			}
			delete []Tmass;

			group1.Add_element(someElement, mass, x); // �������� �������, ������ � ����� ���������
			
			Choice(mass, number, x, group1); // ����� �������� ����� ������� ��������
		}
		else {
			x++;
			std::string* mass = new std::string[x];
			group1.Add_element(someElement, mass, x); // �������� �������, ������ � ����� ���������
			
			Choice(mass, number, x, group1); // ����� �������� ����� ������� ��������
		}
		
	}
	if (number == 2) // ���������� 1 �������� �� ������� 
	{
		int y = 1;
		std::string deleted;
		/*std::cout << "������� ����� �������� = ";
		std::cin >> y;*/
		if (y < 1) 
		{
			std::cout << "[INFO]: ������!" << std::endl;
			Choice(mass, number, x, group1);
		}
		else
		{
			if (y > x)
			{
				std::cout << "[INFO]: ������!" << std::endl;
				Choice(mass, number, x, group1);
			}
			else 
			{
				deleted = mass[y - 1];
				y--;
				for (int i = y; i < x - 1; ++i)
				{
					mass[i] = mass[i + 1];
				}
				--x;
				y++;
				group1.Get_element(deleted, y);

				Choice(mass, number, x, group1); // ����� �������� ����� ������� ��������
			}
		}
	}
	if (number == 3) // ����� �����d�
	{
		group1.Show_queue(mass, x); // �������� ����� ������ ������� � �������
		Choice(mass, number, x, group1); // ����� ��������� �������
	}
	if (number == 4) // ���������� ������� ��������, �������� �������� ���������������
	{
		group1.Find_element(mass, x);
		Choice(mass, number, x, group1); // ����� �������� ����� ������� ��������
	}
	if (number == 5) // �������� ����� �������
	{
		std::string res;
		std::string* Tmass = new std::string[x]; // ������� ��� ���� ����� �� ������ 
		for (int i = 0; i < x; i++) {
			Tmass[i] = mass[i];
		}
		std::cout << "[INFO]: �� ������� ����� �������, ������� ����������? Y/N: ";
		std::cin >> res;
		if ((res == "Y") || (res == "y") || (res == "�") || (res == "�"))
		{
			x += x;
			std::string* mass = new std::string[x];
			group1.Merger(mass, Tmass, x);
			delete []Tmass;
			Choice(mass, number, x, group1); // ����� �������� ����� ������� ��������
		}
		else 
		{
			delete []Tmass;
			Choice(mass, number, x, group1); // ����� �������� ����� ������� ��������
		}

	}
	if (number == 6)
	{
		delete []mass;
		group1.Exit();
	}
	else{
		std::cout << "[INFO]: �������� ���� �� ������������ ��������!" << std::endl;
		Choice(mass, number, x, group1); // ����� �������� ����� ������� ��������
	}
}

void ShowCommands() {
	std::cout << "�������� ��������:" << std::endl;
	std::cout << "*******************************************************************************************************" << std::endl;
	std::cout << "���������� �������� ������� - 1" << std::endl;
	std::cout << "���������� �������� ������� - 2" << std::endl;
	std::cout << "����� ������� �� ����� - 3" << std::endl;
	std::cout << "���������� ���������� �������� - 4" << std::endl;
	std::cout << "�������� ����� �������, ������� ������������ ������� � ������ � ����� ���������� �� ����� - 5" << std::endl;
	std::cout << "����� �� ��������� - 6" << std::endl;
	std::cout << "*******************************************************************************************************" << std::endl;
}