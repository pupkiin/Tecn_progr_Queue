#pragma once
//#define Header_H
// родительский класс очередь
#include <string>


class Queue
{
public:
	void Show_queue(std::string* mass, int x) {
		this->x = x;
		for (int i = 0; i < x; i++) {
			std::cout << i + 1 << " | " << mass[i] << std::endl;
		}
		std::cout << std::endl;
	}
	 
	void Add_element(std::string element, std::string* mass, int x) {
		this->element = element;
		this->x = x;
		mass[this->x - 1] = this->element;
	}

	void Get_element(std::string element, int y) {
		this->element = element;
		std::cout << y << " | " << this->element << std::endl;
		std::cout << std::endl;
	}

	void Merger(std::string* mass, std::string* Tmass, int x) { // слияние
		for (int i = 0; i < x/2; i++) {
			mass[i] = Tmass[i];
		}
		for (int i = x / 2; i < x; i++) {
			mass[i] = Tmass[i - x / 2];
		}
	}

	void Exit() {
		return;
	}
private:
	std::string element;
	int numberOfElement;
	int x = 0;
};

