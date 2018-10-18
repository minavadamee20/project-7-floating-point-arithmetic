#pragma once
#ifndef prob3_h
#define prob3_h
#include <iostream>
#include <iomanip>
float  drinks, sandwichAmount, drinkPrice, sandwichPrice, totalAmount, smultiplier = 2.25, wmultipler = 1.75, jmultiplier = 2.80, smallmultiplier = 3.45, bigmultiplier = 5.25;
char drinktype_;
float size_;
int loopcounter, numCustomers;
void numberofCustomers() {
	std::cout << "Enter the number of customers: ";
	std::cin >> numCustomers;
}

void prompt3() {
	std::cout << "\t-----------------------------7-11 Convenient Store-----------------------------" << std::endl;
	std::cout << "\tDrinks" << std::endl;
	std::cout << "\t\tSoda(S)........................................................$2.25" << std::endl;
	std::cout << "\t\tWater(W).......................................................$1.75" << std::endl;
	std::cout << "\t\tJuice(J).......................................................$2.80" << std::endl;
	std::cout << "\tSandwiches" << std::endl;
	std::cout << "\t\t10 inches......................................................$3.45" << std::endl;
	std::cout << "\t\t12 inches......................................................$5.25" << std::endl;
}

void getDrinks() {
	std::cout << "How many drinks: ";
	std::cin >> drinks;
}

void drinkType() {
	std::cout << "What kind of drinks (S = Soda, W = Water, J = Juice): ";
	std::cin >> drinktype_;
}

void sAmount() {
	std::cout << "How many Sandwiches: ";
	std::cin >> sandwichAmount;
}

void sandwichSize() {
	std::cout << "What size of sandwich (10/12 inches): ";
	std::cin >> size_;
}

void displayTotal() {
	std::cout << std::fixed << std::setprecision(2) << "\t\t Your total bill = $" << totalAmount << std::endl << std::endl;
}


void prob3() {
	_asm {
		call numberofCustomers;
		call prompt3;
		
		mov loopcounter, 0;
		
	loop1:
		mov eax, numCustomers;
		cmp loopcounter, eax;
		Je finished;
		call getDrinks;
		call drinkType;
		cmp drinktype_, 'S';
		Je soda;
		cmp drinktype_, 'W';
		Je water;
		cmp drinktype_, 'J';
		Je juice;
	soda:
		fld drinks;
		fld smultiplier;
		fmul;
		fstp drinkPrice;
		Jmp sandwichStart;
	water:
		fld drinks;
		fld wmultipler;
		fmul;
		fstp drinkPrice;
		Jmp sandwichStart;
	juice:
		
		fld drinks;
		fld jmultiplier;
		fmul;
		fstp drinkPrice;
		Jmp sandwichStart;
	sandwichStart:
		call sAmount;
		call sandwichSize;
		cmp size_, 10;
		Jge size10;
		Jmp size12;
	size10:
		fld sandwichAmount;
		fld smallmultiplier;
		fmul;
		fstp sandwichPrice;
		Jmp calculate;
	size12:
		fld sandwichAmount;
		fld bigmultiplier;
		fstp sandwichPrice;
		Jmp calculate;
	calculate:
		fld drinkPrice;
		fld sandwichPrice;
		fadd;
		fstp totalAmount;
		inc loopcounter;
		call displayTotal;
		Jmp loop1;

	finished:

	}
	
}
#endif // !prob3_h
