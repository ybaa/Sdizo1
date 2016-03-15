
#include <stdio.h>
#include <iostream>
#include "Table.h"
#include "List.h"
#include "BinaryHeap.h"



int main()
{
	BinaryHeap heap;
	heap.showContent();
	cout << endl;
	//heap.addElement();
	heap.showContent();
	cout << endl;
	//heap.draw();
	cout << endl;

	heap.removeRoot();
	heap.showContent();
	cout << endl;

	system("PAUSE");
	return 0;
}

