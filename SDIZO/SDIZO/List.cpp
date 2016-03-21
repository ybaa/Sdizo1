#include "List.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct myList
{
	int value;
	myList *previous;
	myList *next;

};

List::List()
{
	srand(time(NULL));
	//set first and last element at NULL
	head = NULL;
	last = NULL;
	ElementsCounter = 0;

	int howMany;

	fstream myFile;
	myFile.open("dataToRead.txt");
	myFile >> howMany;

	int helpValue;
	for (int i = 0; i < howMany; i++){
		
		myList *tmp = new myList;	//create temporary pointer
		myFile >> helpValue;
		tmp->value = helpValue;

		if (head == NULL){
			tmp->next = NULL;
			tmp->previous = NULL;
			head = tmp;
			last = head;
		}
		else{
			tmp->next = head;
			tmp->previous = NULL;
			head->previous = tmp;
			head = tmp;
		}
		ElementsCounter++;



	}
	myFile.close();


}



List::~List()
{
	myList *tmp = head;
	myList *tmp2 = head;
	
	for (int i = 0; i <ElementsCounter; i++){
		tmp->previous = NULL;
		tmp = tmp->next;
		tmp2->next = NULL;
		tmp2->value = NULL;
		tmp2 = tmp;
	}
	ElementsCounter = 0;
}

void List::addRandomValues(){
	myList *tmp = new myList;	//create temporary pointer
	int helpValue = (rand() % 199) + (-99);
	tmp->value = helpValue;

	if (head == NULL){
		tmp->next = NULL;
		tmp->previous = NULL;
		head = tmp;
		last = head;
	}
	else{
		tmp->next = head;
		tmp->previous = NULL;
		head->previous = tmp;
		head = tmp;
	}
	ElementsCounter++;
}


void List::addElementToTheBeginning(){
	myList *tmp = new myList;	//create temporary pointer
	//cout << "podaj wartosc: ";
	//cin >> tmp->value;
	tmp->value = (rand() % 199) + (-99);

	if (head == NULL){
		tmp->next = NULL;
		tmp->previous = NULL;
		head = tmp;
		last = head;
	}
	else{
		tmp->next = head;
		tmp->previous = NULL;
		head->previous = tmp;
		head = tmp;
	}
	ElementsCounter++;

}

void List::addElementToTheEnd(){
	myList *tmp = new myList;	//create temporary pointer
	//cout << "podaj wartosc: ";
	//cin >> tmp->value;
	tmp->value = (rand() % 199) + (-99);

	if (head == NULL){
		tmp->next = NULL;
		tmp->previous = NULL;
		//head = tmp;
		// last = head;
		last = tmp;
		head = last;
	}
	else{
		tmp->previous = last;
		tmp->next = NULL;
		last->next = tmp;
		last = tmp;
	}
	ElementsCounter++;

}

void List::showContent(){
	myList *tmp = new myList;
	tmp = head;
	for (int i = 0; i < ElementsCounter; i++) {
		cout <<setw(4)<< tmp->value ;
		tmp = tmp->next;
	}
}

void List::showInverseContent(){
	myList *tmp = new myList;
	tmp = last;
	for (int i = 0; i < ElementsCounter; i++){
		cout << setw(4) << tmp->value;
		tmp = tmp->previous;
	}
}



void List::addElementSomewhere(){
	myList *tmp = new myList;	//create temporary pointer
	myList *tmp2 = new myList;
	//cout << "podaj wartosc: ";
	int helpValue = (rand() % 199) + (-99);
	//cin >> helpValue;
	tmp->value = helpValue;
	

	tmp2 = head;

	if (head == NULL){
		tmp->next = NULL;
		tmp->previous = NULL;
		head = tmp;
		last = head;
		ElementsCounter++;
	}
	else {
		
		int place = (rand() % ElementsCounter) + 1;
		//do{
		//	cout << "W ktore miejsce dodac element: ";
		//	cin >> place;
		//} while (place < 1 || place > ElementsCounter + 1);


		if (place == 1){
	
			tmp->next = head;
			tmp->previous = NULL;
			head->previous = tmp;
			head = tmp;
			ElementsCounter++;
		}
		else if (place == ElementsCounter+1){
			tmp->previous = last;
			tmp->next = NULL;
			last->next = tmp;
			last = tmp;
			last->value = helpValue;
			ElementsCounter++;
		}
		else {
			//set pointer where the element should be added, set previous and next of neighborough elements to it
			for (int i = 0; i < place-1 ; i++){
				tmp2 = tmp2->next;
			}
			
			tmp ->next = tmp2;
			tmp2 = tmp2->previous;
			tmp->previous = tmp2;
			tmp2->next = tmp;
			tmp2 = tmp->next;
			tmp2->previous = tmp;
			ElementsCounter++;
		}
	}
}

void List::removeLastElement(){	//just set pointer of neighbouring elements properly
	myList *tmp = new myList;
	tmp = last;
	last = tmp->previous;
	tmp->value = NULL;
	last->next = NULL;
	
	ElementsCounter--;
}

void List::removeFirstElement(){ //just set pointer of neighbouring elements properly
	myList *tmp = new myList;
	tmp = head;
	tmp->value = NULL;
	head = tmp->next;
	tmp->previous = NULL;
	ElementsCounter--;
}

void List::removeSomeElement(){
	myList *tmp = new myList;
	myList *tmp2 = new myList;
	int which = (rand() % ElementsCounter) + 1;
	/*do{
		cout << "Ktory element usunac: ";
		cin >> which;
	} while (which < 0 || which > ElementsCounter);*/
	tmp = head;
	for (int i = 0; i < which-1; i++){	//set it in the correct position
		tmp = tmp->next;
	}
	
	tmp2 = tmp->next;
	for (int i = which; i < ElementsCounter; i++){	//change all values to the end
		
			tmp2 = tmp->next;
			//int help = tmp2->value;
			//tmp->value = help;
			tmp->value = tmp2->value;
			tmp = tmp->next;
		
	}

	removeLastElement();
	
}

void List::findElement(){
	myList *tmp = head;
	int which;
	do{
		cout << "Ktory element chcesz wyswietlic: ";
		cin >> which;
	} while (which < 0 || which > ElementsCounter);

	for (int i = 0; i < which-1; i++){
		tmp = tmp->next;
	}
	cout << tmp->value << endl;
}

void List::findElementValue(){
	myList *tmp = head;
	//cout << "Podaj wartosc jaka chcesz znalezc: ";
	int toFind = (rand() % 199) + (-99);
	//cin >> toFind;
	bool isFound = false;

	for (int i = 0; i < ElementsCounter; i++){
		if (tmp->value == toFind){
			//cout << "[" << i << "] " << tmp->value << endl;
			isFound = true;
		}
		tmp = tmp->next;
	}

	//if (isFound == false)
		//cout << "Nie ma takiego elementu";
}


int List::getElementsCounter(){
	return ElementsCounter;
}
