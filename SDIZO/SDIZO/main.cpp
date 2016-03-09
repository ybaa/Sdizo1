
#include <stdio.h>
#include <iostream>
#include "Table.h"



int main()
{
	Table table;
	table.showContent();

	cout << endl;
	table.resize();
	table.showContent();

	cout << endl;
	table.resize();
	table.showContent();

	system("PAUSE");
	return 0;
}

