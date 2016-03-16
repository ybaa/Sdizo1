
#include <stdio.h>
#include <iostream>
#include "Table.h"
#include "List.h"
#include "BinaryHeap.h"



int main()
{
	BinaryHeap heap;
	heap.showContent();
	heap.removeRoot();
	cout << endl << endl;
	heap.draw();
	//heap.showContent();
	cout << endl;
	heap.findElement();
	cout << endl;



	system("PAUSE");
	return 0;
}

