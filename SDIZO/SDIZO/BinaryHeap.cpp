#include "BinaryHeap.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <math.h>
#include <fstream>


using namespace std;

BinaryHeap::BinaryHeap()
{

	ElementsCounter = 14;
	srand(time(NULL));
	myHeap = (int*)malloc(sizeof(int)*ElementsCounter);

	fstream myFile;
	myFile.open("dataToRead.txt");
	int variable, parent, index;
	myFile >> variable;
	myHeap[0] = variable;
	
	for (int i = 1; i < ElementsCounter; i++){
		myFile >> variable;
		myHeap[i] = variable;
		index = i;
		parent = floor((index - 1) / 2);
		while (myHeap[index] > myHeap[parent]){
			swap(myHeap[index], myHeap[parent]);
			index = parent;
			parent = floor((index - 1) / 2);

		}
	
	}
	myFile.close();
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


void BinaryHeap::removeRoot(){
	myHeap[0] = myHeap[ElementsCounter - 1];
	myHeap[ElementsCounter - 1] = NULL;
	ElementsCounter--;
	myHeap = (int*)realloc(myHeap, sizeof(int)*ElementsCounter);

	//showContent();
	//cout << endl;

	int index = 0;
	int leftChild = 2 * index + 1;
	int rightChild = 2 * index + 2;
	cout << myHeap[index] << "   " << myHeap[leftChild] << "   " << myHeap[rightChild] << endl;
	while ((myHeap[index] < myHeap[leftChild] && leftChild<ElementsCounter) || (myHeap[index] < myHeap[rightChild] && rightChild<ElementsCounter)){
		if (myHeap[rightChild] > myHeap[leftChild] && rightChild < ElementsCounter){
			swap(myHeap[index], myHeap[rightChild]);
			index = rightChild;
		}
		else if (myHeap[leftChild] > myHeap[rightChild] && (rightChild < ElementsCounter || leftChild == ElementsCounter-1)){
			swap(myHeap[index], myHeap[leftChild]);
			index = leftChild;
		}
		else{
			break;
		}

		//showContent();
		//cout << endl;
		leftChild = (2 * index) + 1;
		rightChild =( 2 * index )+ 2;
		cout << myHeap[index] << "   " << myHeap[leftChild] << "   " << myHeap[rightChild] << endl;

	}

}

void BinaryHeap::draw(){
	
	int help = 1;
	int x = 1;
	int counter = 1;
	int power = 2;
	
	cout << setw(40) << myHeap[0] << endl;
	while (help < ElementsCounter){
		if (power == 8)
			cout << "    ";
		while (counter <= power){
			cout << setw(80 / (power +x)) << myHeap[help];
			help++;
			counter++;
			if (help >= ElementsCounter)
				break;
		}
		counter = 1;
		cout << endl;
		power *= 2;
	
	}
}


void BinaryHeap::showContent(){
	int neededSpaceForOneNumber = 4;
	for (int i = 0; i < ElementsCounter; i++){
		cout << setw(neededSpaceForOneNumber) << myHeap[i];
	}
}

void BinaryHeap::findElement(){
	int value;
	cout << "Podaj wartosc: ";
	cin >> value;
	bool isInHeap = false;
	for (int i = 0; i < ElementsCounter; i++){
		if (myHeap[i] == value)
			isInHeap = true;
		
	}
	
	if (isInHeap == true)
		cout << "Element istnieje w kopcu" << endl;
	else
		cout << "Brak takiego elementu" << endl;
}

BinaryHeap::~BinaryHeap()
{
	free(myHeap);
}
