
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
	heap.sort();
	heap.showContent();
	cout << endl;
	//heap.draw();
	cout << endl;

	system("PAUSE");
	return 0;
}

