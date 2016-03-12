
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

	List list;
	list.addElementToTheBeginning();

	list.showContent();
	cout << endl;

	list.addElementToTheBeginning();

	list.showContent();
	cout << endl;

	list.addElementToTheBeginning();

	list.showContent();
	cout << endl;

	list.addElementToTheEnd();

	list.showContent();
	cout << endl;

	list.addElementToTheEnd();
	//list.addElementToTheBeginning();

	list.showContent();
	cout << endl;
	list.showInverseContent();
	cout << endl;

	system("PAUSE");
	return 0;
}

