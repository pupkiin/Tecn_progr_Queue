#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
// Создать родительский класс "Очередь" с функциями инициализации очереди, добавления элемента в очередь и извлечения элемента из очереди.
// Создать метод создания копии очереди. Результатом должен стать новый экземпляр класса “Очередь”, 
// состоящий из элементов(копий элементов) исходной очереди.Порядок следования элементов должен быть сохранен.
// Создать функцию слияния двух очередей. Результатом должна быть очередь,
// состоящая элементов первой очереди и второй очереди.Порядок следования элементов должен быть сохранен.
// На основе родительского класса "Очередь" создать дочерний класс "Очередь1" с
// функциями нахождения и отображения на экране требуемого в соответствии с вариантомзадания значения(см.таблицу ниже).

// 17 - Нахождение первого элемента, большего среднего арифметического

#include "Header.h"
#include "heir.h"

void Choice(std::string*, int, int, QueueHeir);
void ShowCommands();

int main() {
	setlocale(LC_ALL, "Russian");
	
	int number = 0; // переменная выбора действия
	QueueHeir group1 = QueueHeir(); // новый обьект класса

	// массив элементов
	int x = 0; // начальное кол во элементов
	std::string* mass = new std::string[x];
	
	Choice(mass, number, x, group1);
}


void Choice(std::string *mass, int number, int x, QueueHeir group1) {
	
	ShowCommands();
	std::cout << "=> ";
	std::cin >> number; // выбираем действие

	if (number == 1) { // ФОРМАЛИЗАЦИЯ - СЛОВА ПИШЕМ ЧЕРЕЗ НИЖНЕЕ ПОДЧЕРКИВАНИЕ (БЕЗ ПРОБЕЛОВ)
		std::string someElement; // новый элемент очереди
		std::cout << "Метод добавления элемента" << std::endl;
		std::cout << "Введите название (на английском)" << std::endl;
		std::cin >> someElement;
		
		if (x > 0) 
		{
			std::string* Tmass = new std::string[x];
			for (int i = 0; i < x; i++) {
				Tmass[i] = mass[i]; // заполняем временный массив
			}
			delete []mass;

			x++; // увеличиваем количество элементов массива
			std::string* mass = new std::string[x]; // переопределили массив
			for (int i = 0; i < x - 1; i++) {
				mass[i] = Tmass[i]; // заполняем временный массив 
			}
			delete []Tmass;

			group1.Add_element(someElement, mass, x); // передаем элемент, массив и колво элементов
			
			Choice(mass, number, x, group1); // снова вызываем чтобы выбрать действие
		}
		else {
			x++;
			std::string* mass = new std::string[x];
			group1.Add_element(someElement, mass, x); // передаем элемент, массив и колво элементов
			
			Choice(mass, number, x, group1); // снова вызываем чтобы выбрать действие
		}
		
	}
	if (number == 2) // извлечение 1 элемента из очереди 
	{
		int y = 1;
		std::string deleted;
		/*std::cout << "Введите номер элемента = ";
		std::cin >> y;*/
		if (y < 1) 
		{
			std::cout << "[INFO]: Ошибка!" << std::endl;
			Choice(mass, number, x, group1);
		}
		else
		{
			if (y > x)
			{
				std::cout << "[INFO]: Ошибка!" << std::endl;
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

				Choice(mass, number, x, group1); // снова вызываем чтобы выбрать действие
			}
		}
	}
	if (number == 3) // показ очереdи
	{
		group1.Show_queue(mass, x); // вызываем метод показа очереди у обьекта
		Choice(mass, number, x, group1); // снова запускаем функцию
	}
	if (number == 4) // Нахождение первого элемента, большего среднего арифметического
	{
		group1.Find_element(mass, x);
		Choice(mass, number, x, group1); // снова вызываем чтобы выбрать действие
	}
	if (number == 5) // создание копии очереди
	{
		std::string res;
		std::string* Tmass = new std::string[x]; // создаем еще один такой же массив 
		for (int i = 0; i < x; i++) {
			Tmass[i] = mass[i];
		}
		std::cout << "[INFO]: Вы создали копию очереди, желаете объединить? Y/N: ";
		std::cin >> res;
		if ((res == "Y") || (res == "y") || (res == "Д") || (res == "д"))
		{
			x += x;
			std::string* mass = new std::string[x];
			group1.Merger(mass, Tmass, x);
			delete []Tmass;
			Choice(mass, number, x, group1); // снова вызываем чтобы выбрать действие
		}
		else 
		{
			delete []Tmass;
			Choice(mass, number, x, group1); // снова вызываем чтобы выбрать действие
		}

	}
	if (number == 6)
	{
		delete []mass;
		group1.Exit();
	}
	else{
		std::cout << "[INFO]: Выберите одно из предложенных действий!" << std::endl;
		Choice(mass, number, x, group1); // снова вызываем чтобы выбрать действие
	}
}

void ShowCommands() {
	std::cout << "Выберите действие:" << std::endl;
	std::cout << "*******************************************************************************************************" << std::endl;
	std::cout << "Добавление элемента очереди - 1" << std::endl;
	std::cout << "Извлечение элемента очереди - 2" << std::endl;
	std::cout << "Вывод очереди на экран - 3" << std::endl;
	std::cout << "Вычисление требуемого значения - 4" << std::endl;
	std::cout << "Создание копии очереди, Слияние оригинальной очереди с копией и вывод результата на экран - 5" << std::endl;
	std::cout << "Выход из программы - 6" << std::endl;
	std::cout << "*******************************************************************************************************" << std::endl;
}