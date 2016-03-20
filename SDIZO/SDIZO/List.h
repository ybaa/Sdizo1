#pragma once
class List
{
	struct myList
	{
		int value;
		myList *previous;
		myList *next;

	};

	struct myList *head;
	struct myList *last;
	int ElementsCounter;


public:
	List();
	~List();
	void addElementToTheBeginning();
	void addElementToTheEnd();
	void addElementSomewhere();
	void removeLastElement();
	void removeFirstElement();
	void removeSomeElement();
	void findElement();
	void findElementValue();
	void addRandomValues();
	void showContent();
	void showInverseContent();
	int getElementsCounter();
	void add(); // old version of adding in the middle
};

