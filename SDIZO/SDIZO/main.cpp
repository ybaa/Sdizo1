
#include <stdio.h>
#include <iostream>
#include "Table.h"
#include "List.h"



int main()
{
	List list;
	list.showContent();
	cout << endl;
	list.addElementSomewhere();
	list.showContent();
	cout << endl;
	list.addElementToTheEnd();
	list.showContent();
	cout << endl;

	system("PAUSE");
	return 0;
}

