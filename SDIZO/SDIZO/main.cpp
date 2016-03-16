
#include <stdio.h>
#include <iostream>
#include "Table.h"
#include "List.h"
#include "BinaryHeap.h"



int main()
{
	List list;
	list.showContent();
	cout << endl;
	list.addElementSomewhere();
	list.showContent();
	cout << endl;
	list.add();
	list.showContent();
	cout << endl;
	list.add();
	list.showContent();
	cout << endl;
	list.add();
	list.showContent();
	cout << endl;



	system("PAUSE");
	return 0;
}

