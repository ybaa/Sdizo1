#include "BinaryHeap.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <math.h>

using namespace std;

BinaryHeap::BinaryHeap()
{
	do{
		cout << "Podaj liczbe elementow kopca: ";
		cin >> ElementsCounter;
	} while (ElementsCounter <= 0);
	srand(time(NULL));
	myHeap = (int*)malloc(sizeof(int)*ElementsCounter);
	//table = new int[numberOfElements];

	int parent,index;
	myHeap[0] = (rand() % 199) + (-99);
	//srand(time(NULL));		//fill the table with random two-digit numbers
	for (int i = 1; i < ElementsCounter; i++){
		myHeap[i] = (rand() % 199) + (-99);
		index = i;
		parent = floor((index - 1) / 2);
		while (myHeap[index] > myHeap[parent]){
			swap(myHeap[index], myHeap[parent]);
			index = parent;
			parent = floor((index - 1) / 2);
		}
	}
	
	
}

void BinaryHeap::addElement(){
	int value = (rand() % 199) + (-99);
	ElementsCounter++;
	myHeap = (int*)realloc(myHeap, sizeof(int)*ElementsCounter);
	int index = ElementsCounter-1;
	int parent = floor((index - 1) / 2);
	myHeap[ElementsCounter - 1] = value;
	while (myHeap[index] > myHeap[parent]){
		swap(myHeap[index], myHeap[parent]);
		index = parent;
		parent = floor((index - 1) / 2);
	}
}


void BinaryHeap::draw(){
	



}


void BinaryHeap::showContent(){
	int neededSpaceForOneNumber = 4;
	for (int i = 0; i < ElementsCounter; i++){
		cout << setw(neededSpaceForOneNumber) << myHeap[i];
	}
}

BinaryHeap::~BinaryHeap()
{
	free(myHeap);
}
