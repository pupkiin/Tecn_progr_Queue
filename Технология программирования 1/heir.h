#pragma once
#include <iostream>
#include <cstring>
#include "Header.h"
// 17 - Нахождение первого элемента, большего среднего арифметического
class Queue;

class QueueHeir: public Queue 
{
public:

	void Find_element(std::string *mass, int x) 
	{
		for (int i = 0; i < x; i++) {
			numberOfLetters += mass[i].length();
			numberOfElements++;
		}
		sredn = numberOfLetters / numberOfElements;

		for (int i = 0; i < x; i++) {
			if (mass[i].length() > sredn)
			{
				std::cout << i << " | " << mass[i] << std::endl;
				std::cout << std::endl;
				break;
			}
		}
	}

private:
	int numberOfElements = 0;
	int numberOfLetters = 0;
	float sredn = 0;
};