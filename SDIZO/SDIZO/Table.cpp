#include "Table.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <fstream>


using namespace std;

Table::Table(){
	//get number of elements from file
	fstream myFile;
	myFile.open("dataToRead.txt");
	myFile >> numberOfElements;
	
	table = (int*)malloc(sizeof(int)*numberOfElements);

	srand(time(NULL));	//it will be necessery later, I use it now because it has to be used once at the beginning
	
	//fill the table with the rest of values in file
	int variable;
	for (int i = 0; i < numberOfElements; i++){
		myFile >> variable;
		table[i] = variable;
	}
	myFile.close();

	
}

void Table::showContent(){
	int neededSpaceForOneNumber = 4;
	for (int i = 0; i < numberOfElements; i++){
		cout << setw(neededSpaceForOneNumber) << table[i];
	}
}

void Table::addElementToTheBeginning(){
	numberOfElements++;
	table = (int*)realloc(table, sizeof(int)*(numberOfElements));
	for (int i = 1; i < numberOfElements; i++){			//move all elements and left place for the 1st one
		table[numberOfElements - i] = table[numberOfElements - i - 1];
	}

	int value;
	do{
		cout << "Podaj wartosc: ";
		cin >> value;
	} while (value < -99 || value > 99);

	table[0] = value;
}

void Table::addElementToTheEnd(){
	numberOfElements++;
	table = (int*)realloc(table, sizeof(int)*(numberOfElements));

	int value;
	do{
		cout << "Podaj wartosc: ";
		cin >> value;
	} while (value < -99 || value > 99);

	table[numberOfElements - 1] = value;
}

void Table::addElementSomewhere(){
	int place;
	do{
		cout << "Podaj miejsce: ";
		cin >> place;
	} while (place < 0 || place > numberOfElements);	

	if (place == 0)
		addElementToTheBeginning();
	else if (place == numberOfElements)
		addElementToTheEnd();
	else{
		numberOfElements++;
		table = (int*)realloc(table, sizeof(int)*(numberOfElements));
		for (int i = 1; i < numberOfElements - place ; i++){		//move all elements from place
			table[numberOfElements - i] = table[numberOfElements - i - 1];
		}

		int value;
		do{
			cout << "Podaj wartosc: ";
			cin >> value;
		} while (value < -99 || value > 99);
		table[place] = value;
		 
	}
}

void Table::removeElementFromTheEnd(){
	table[numberOfElements - 1] = NULL;
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
	int place; //index of table for the new variable
	do{
		cout << "Podaj miejsce: ";
		cin >> place;
	} while (place < 0 || place > numberOfElements);

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
	int value;
	cout << "Podaj wartosc elementu: ";
	cin >> value;
	bool isIn = false;

	for (int i = 0; i < numberOfElements; i++){
		if (table[i] == value){
			cout << "table[" << i << "] = " << value << endl;
			isIn = true;
		}
	}

	if (isIn == false)
		cout << "Nie ma takiego elementu w tablicy" << endl;
}

void Table::resize(){
	cout << "Podaj nowa liczbe elementow tablicy: ";
	int oldNumberOfElements = numberOfElements;	//old number is necessery to fill the rest of the table
	cin >> numberOfElements;
	table = (int*)realloc(table, sizeof(int)*numberOfElements);

	if (numberOfElements > oldNumberOfElements){
		//srand(time(NULL));		//fill the rest of the table with random two-digit numbers
		for (int i = oldNumberOfElements; i < numberOfElements; i++){
			table[i] = (rand() % 199) + (-99);
		}
	}
	if (numberOfElements < oldNumberOfElements){
		int howManyElements = oldNumberOfElements - numberOfElements;
		for (int i = 0; i <howManyElements; i++){
			table = (int*)realloc(table, sizeof(int)*(numberOfElements));
		}
	}
}

int Table::getNumberOfElements(){
	return numberOfElements;
}

Table::~Table(){
	free(table);
}
