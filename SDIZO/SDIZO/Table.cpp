#include "Table.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

Table::Table(){
	do{
		cout << "Podaj liczbe elementow tablicy: ";
		cin >> numberOfElements;
	} while (numberOfElements <= 0);
	table = (int*)malloc(sizeof(int)*numberOfElements);
	//table = new int[numberOfElements];

	srand(time(NULL));		//fill the table with random two-digit numbers
	for (int i = 0; i < numberOfElements; i++){
		table[i] = (rand() % 199) + (-99);
	}
	
}

Table::~Table(){
	free(table);
	//delete[] table;
}

void Table::showContent(){
	//int neededSpaceForOneNumber = 80 / numberOfElements;	//count how much space is needed to show numbers in one line with nice spacing
	int neededSpaceForOneNumber = 4;
	for (int i = 0; i < numberOfElements; i++){
		cout << setw(neededSpaceForOneNumber) << table[i];
	}
}

void Table::resize(){
	cout << "Podaj nowa liczbe elementow tablicy: ";
	int oldNumberOfElements = numberOfElements;	//old number is necessery to fill the rest of the table
	cin >> numberOfElements;
	table = (int*)realloc(table, sizeof(int)*numberOfElements);

	if (numberOfElements > oldNumberOfElements){
		srand(time(NULL));		//fill the rest of the table with random two-digit numbers
			for (int i = oldNumberOfElements; i < numberOfElements; i++){
			table[i] = (rand() % 199) + (-99);
		}
	}
}

void Table::addElementToTheBeginning(){
	numberOfElements++;
	table = (int*)realloc(table, sizeof(int)*(numberOfElements));
	for (int i = 1; i < numberOfElements; i++){			//move all elements and left place for the 1st one
		table[numberOfElements - i] = table[numberOfElements - i - 1];
	}
	table[0] = (rand() % 200) + (-99);
}

void Table::addElementToTheEnd(){
	numberOfElements++;
	table = (int*)realloc(table, sizeof(int)*(numberOfElements));
	table[numberOfElements - 1] = (rand() % 199) + (-99);
}

void Table::addElementSomewhere(){
	int place = (rand() % (numberOfElements - 1) + 0);	//number of index of table for the new variable

	if (place == 0)
		addElementToTheBeginning();
	if (place == numberOfElements)
		addElementToTheEnd();
	else{
		numberOfElements++;
		table = (int*)realloc(table, sizeof(int)*(numberOfElements));
		for (int i = 1; i < numberOfElements - place ; i++){		//move all elements from place
			table[numberOfElements - i] = table[numberOfElements - i - 1];
		}
		table[place] = (rand() % 199) + (-99);
	}
}

void Table::removeElementFromTheEnd(){
	numberOfElements--;
	table = (int*)realloc(table, sizeof(int)*(numberOfElements));
}

void Table::removeElementFromTheBeginning(){
	for (int i = 0; i < numberOfElements - 1; i++){
		table[i] = table[i + 1];
	}
	removeElementFromTheEnd();
}

void Table::removeElementFromSomewhere(){
	int place = (rand() % (numberOfElements - 1) + 0);	//number of index of table for the new variable

	if (place == 0)
		removeElementFromTheBeginning();
	if (place == numberOfElements)
		removeElementFromTheEnd();
	else{
		for (int i = place; i < numberOfElements - 1; i++){
			table[i] = table[i + 1];
		}
		removeElementFromTheEnd();
	}
}

void Table::findElement(){
	int index;
	
	do{
		cout << "Podaj indeks elementu, ktory chcesz wyswietlic: ";
		cin >> index;
	} while (index < 0 || index >= numberOfElements);
	
	cout << table[index];
}


void Table::setNumberOfElements(int localNumberOfElements){
	numberOfElements = localNumberOfElements;
}

int Table::getNumberOfElements(){
	return numberOfElements;
}