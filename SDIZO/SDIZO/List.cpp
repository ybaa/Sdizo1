#include "List.h"
#include <iostream>
#include <iomanip>

using namespace std;

struct myList
{
	int value;
	myList *previous;
	myList *next;

};

List::List()
{
	//set first and last element at NULL
	head = NULL;
	last = NULL;
	ElementsCounter = 0;
}



List::~List()
{
}

void List::addElementToTheBeginning(){
	myList *tmp = new myList;	//create temporary pointer
	cout << "podaj wartosc: ";
	cin >> tmp->value;

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
	cout << "podaj wartosc: ";
	cin >> tmp->value;

	if (head == NULL){
		tmp->next = NULL;
		tmp->previous = NULL;
		head = tmp;
		last = head;
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
	myList *tmp = head;
	while (tmp){
		cout <<setw(4)<< tmp->value ;
		tmp = tmp->next;
	}
}

void List::showInverseContent(){
	myList *tmp = last;
	while (tmp){
		cout << setw(4) << tmp->value;
		tmp = tmp->previous;
	}
}

void List::addElementSomewhere(){
	myList *tmp = new myList;	//create temporary pointer
	cout << "podaj wartosc: ";
	cin >> tmp->value;

	if (head == NULL){
		tmp->next = NULL;
		tmp->previous = NULL;
		head = tmp;
		last = head;
	}
	else{
		int place = (rand() % (ElementsCounter - 2) + 1); // without beginning and the end
		//-----------------------------------------------  I DONT KNOW HOW TO DO IT, REMEMBER TO GO BACK IN HERE-------------------------------
	}
}

void List::removeLastElement(){
	myList *tmp = new myList;
	tmp = last;
	last = tmp->previous;
	tmp->value = NULL;
	last->next = NULL;
	
	ElementsCounter--;
}


int List::getElementsCounter(){
	return ElementsCounter;
}
