#include "Table.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

Table::Table(){
	cout << "Podaj liczbe elementow tablicy: ";
	cin >> numberOfElements;
	table = (int*)malloc(sizeof(int)*numberOfElements);
	//table = new int[numberOfElements];

	srand(time(NULL));		//fill the table with random two-digit numbers
	for (int i = 0; i < numberOfElements; i++){
		table[i] = (rand() % 200) + (-99);
	}
	
}

Table::~Table(){
	free(table);
	//delete[] table;
}

void Table::showContent(){
	int neededSpaceForOneNumber = 80 / numberOfElements;	//count how much space is needed to show numbers in one line with nice spacing
	for (int i = 0; i < numberOfElements; i++){
		cout << setw(neededSpaceForOneNumber) << table[i];
	}
}

void Table::resize(){
	cout << "Podaj nowa liczbe elementow tablicy: ";
	int oldNumberOfElements = numberOfElements;	//old number is necessery to fill the rest of the table
	cin >> numberOfElements;
	table = (int*)realloc(table, sizeof(int)*numberOfElements);

	if (numberOfElements < oldNumberOfElements){
		srand(time(NULL));		//fill the rest of the table with random two-digit numbers
			for (int i = oldNumberOfElements; i < numberOfElements; i++){
			table[i] = (rand() % 200) + (-99);
		}
	}
}

void Table::setNumberOfElements(int localNumberOfElements){
	numberOfElements = localNumberOfElements;
}

int Table::getNumberOfElements(){
	return numberOfElements;
}