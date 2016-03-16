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

	int howMany;
	do{
		cout << "Ile elementow ma miec lista: ";
		cin >> howMany;
	} while (howMany < 0);
	for (int i = 0; i < howMany; i++){
		addRandomValues();
	}
}



List::~List()
{
	myList *tmp = head;
	myList *tmp2 = head;
	
	for (int i = 0; i <ElementsCounter; i++){
		tmp->previous = NULL;
		tmp = tmp->next;
		tmp2->next = NULL;
		tmp2 = tmp;
	}
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

void List::add(){
	//previous version of adding element in the middle
	myList *tmp = new myList;	//create temporary pointer
	cout << "podaj wartosc: ";
	int helpValue;
	cin >> helpValue;
	tmp->value = helpValue;


	if (head == NULL){
		tmp->next = NULL;
		tmp->previous = NULL;
		head = tmp;
		last = head;
		ElementsCounter++;
	}
	else{
		//int place = (rand() % (ElementsCounter - 2) + 1); // without beginning and the end
		int place;
		do{
			cout << "W ktore miejsce dodac element: ";
			cin >> place;
		} while (place < 0 || place > ElementsCounter + 1);

			if (place == 1){
				//	addElementToTheBeginning();


				tmp->next = head;
				tmp->previous = NULL;
				head->previous = tmp;
				head = tmp;
				ElementsCounter++;
			}
			else{


				//add new element to the end and move all values to make place for new element in the middle
				//tmp = last;
				tmp->previous = last;
				tmp->next = NULL;
				last->next = tmp;
				last = tmp;
				last->value = helpValue;
				ElementsCounter++;

				tmp = last;
				myList *tmp2 = new myList;
				//tmp2 = last;
				tmp2 = tmp->previous;
				//tmp = last;
				for (int i = place; i < ElementsCounter; i++){
					//tmp2 = tmp->previous;
					//tmp = tmp2;
					int help = tmp2->value;
					//tmp->value = help;
					tmp->value = help;
					tmp = tmp2;
					tmp2 = tmp->previous;

					//if it is a place where the value should be added, just place the value there
					if (i == ElementsCounter - 1){
						tmp->value = helpValue;
						tmp = tmp2;
						tmp2 = tmp->previous;
					}

				}


			}
		
	}
} 

void List::addElementSomewhere(){
	myList *tmp = new myList;	//create temporary pointer
	myList *tmp2 = new myList;
	cout << "podaj wartosc: ";
	int helpValue;
	cin >> helpValue;
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
		//int place = (rand() % (ElementsCounter - 2) + 1); // without beginning and the end
		int place;
		do{
			cout << "W ktore miejsce dodac element: ";
			cin >> place;
		} while (place < 0 || place > ElementsCounter + 1);

		if (place == 1){
			//	addElementToTheBeginning();


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
		else{
			//set pointer where the element should be added, set previous and next of neighborough elements to it
			for (int i = 0; i < place-1 ; i++){
				tmp2 = tmp2->next;
			}
			
			tmp ->next = tmp2;
			tmp2 = tmp2->previous;
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
	int which;
	do{
		cout << "Ktory element usunac: ";
		cin >> which;
	} while (which < 0 || which > ElementsCounter);
	tmp = head;
	for (int i = 0; i < which-1; i++){	//set it in the correct position
		tmp = tmp->next;
	}
	
	tmp2 = tmp->next;
	for (int i = which; i < ElementsCounter; i++){	//change all values to the end
		
			tmp2 = tmp->next;
			int help = tmp2->value;
			tmp->value = help;
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
	cout << tmp->value;
}

void List::findElementValue(){
	myList *tmp = head;
	cout << "Podaj wartosc jaka chcesz znalezc: ";
	int toFind;
	cin >> toFind;

	for (int i = 0; i < ElementsCounter; i++){
		if (tmp->value == toFind)
			cout << "[" << i << "] " << tmp->value;
		
		tmp = tmp->next;
	}
}


int List::getElementsCounter(){
	return ElementsCounter;
}
