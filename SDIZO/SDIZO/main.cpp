
#include <stdio.h>
#include <iostream>
#include "Table.h"
#include "List.h"



int main()
{/*
	Table table;
	table.showContent();
	
	cout << endl;
	table.resize();
	table.showContent();

	cout << endl;
	table.resize();
	table.showContent();

	cout << endl;

	table.addElementToTheBeginning();
	table.showContent();
	int x;
	cin >> x;
	table.addElementToTheEnd();
	table.showContent();
	
	cout << endl;
	cin >> x;
	table.addElementSomewhere();
	table.showContent();
	
	cout << endl;
	
	table.removeElementFromTheEnd();
	table.showContent();

	cout << endl;

	table.removeElementFromTheBeginning();
	table.showContent();

	cout << endl;

	table.removeElementFromSomewhere();
	table.showContent();
	cout << endl;

	table.findElement();
	cout << endl;
	*/
	/*
	List list;

	list.showContent();

	list.addElementToTheBeginning();
	//cout << list.getElementsCounter() << endl;

	list.showContent();
	cout << endl;
	//cout << list.getElementsCounter() << endl;

	list.addElementToTheBeginning();
	list.showContent();
	cout << endl;
	//cout << list.getElementsCounter() << endl;

	list.addElementToTheBeginning();
	list.showContent();
	cout << endl;

	//cout << list.getElementsCounter() << endl;

	list.addElementToTheEnd();
	list.showContent();
	cout << endl;
	//cout << list.getElementsCounter() << endl;

	list.addElementToTheEnd();
	//list.addElementToTheBeginning();

	list.showContent();
	cout << endl;
	//cout << list.getElementsCounter() << endl;

	list.removeLastElement();
	list.showContent();
	cout << endl;
	//cout << list.getElementsCounter() << endl;
	
	list.removeFirstElement();
	list.showContent();
	cout << endl;

	list.removeFirstElement();
	list.showContent();
	cout << endl;
	
	*/

	Table table;
	table.showContent();
	cout << endl;
	table.resize();
	cout << endl;
	table.showContent();
	cout << endl;
	cout << table.getNumberOfElements() << endl;
	table.resize();
	table.showContent();
	cout << endl;
	cout << table.getNumberOfElements() << endl;
	system("PAUSE");
	return 0;
}

