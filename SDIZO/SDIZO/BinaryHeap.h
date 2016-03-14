#pragma once
class BinaryHeap
{
	int *myHeap;
	int ElementsCounter;

	
public:
	BinaryHeap();
	~BinaryHeap();
	void showContent();
	void draw();
	void addElement();
};

