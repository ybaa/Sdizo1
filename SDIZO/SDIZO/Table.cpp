#include "Table.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

Table::Table(){
	cout << "Podaj liczbe elementow tablicy: ";
	cin >> numberOfElements;
	table = new int[numberOfElements];

	srand(time(NULL));
	for (int i = 0; i < numberOfElements; i++){
		table[i] = (rand() % 99) + 0;
	}
	

}


Table::~Table(){
	delete[] table;
}

void Table::showContent(){
	int neededSpaceForOneNumber = 80 / numberOfElements;
	for (int i = 0; i < numberOfElements; i++){
		cout << setw(neededSpaceForOneNumber) << table[i];
	}
}


void Table::setNumberOfElements(int localNumberOfElements){
	numberOfElements = localNumberOfElements;
}

int Table::getNumberOfElements(){
	return numberOfElements;
}