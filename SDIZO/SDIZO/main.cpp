
#include <stdio.h>
#include <iostream>
#include "Table.h"
#include "List.h"
#include "BinaryHeap.h"

using namespace std;

int main()
{
	Table table;
	//List list;
	//BinaryHeap heap;

	//long long performanceCountStart, performanceCountEnd;

	

	int whichStruct;
	cout << "wybierz strukture: " << endl;
	cout << "[1] Tablica" << endl;
	cout << "[2] Lista" << endl;
	cout << "[3] Kopiec binarny" << endl;
	cin >> whichStruct;

	switch (whichStruct)
	{
	case 1:
		int whichOption;
		do{
			table.showContent();
			cout << endl;
			cout << "wybierz operacje: " << endl;
			cout << "[1] Dodaj element na poczatku" << endl;
			cout << "[2] Dodaj element na koncu" << endl;
			cout << "[3] Dodaj element w losowym miejscu w srodku" << endl;
			cout << "[4] Usun pierwszy element" << endl;
			cout << "[5] Usun ostatni element" << endl;
			cout << "[6] Usun element w losowym miejscu w srodku" << endl;
			cout << "[7] Zmien rozmiar" << endl;
			cout << "[8] Znajdz element" << endl;
			cout << "[9] Pokaz zawartosc" << endl;
			cout << "[10] Koniec" << endl;
			cin >> whichOption;

			switch (whichOption)
			{
			case 1:
				table.addElementToTheBeginning();
				break;
			case 2:
				table.addElementToTheEnd();
				break;
			case 3:
				table.addElementSomewhere();
				break;
			case 4:
				table.removeElementFromTheBeginning();
				break;
			case 5:
				table.removeElementFromTheEnd();
				break;
			case 6:
				table.removeElementFromSomewhere();
				break;
			case 7:
				table.resize();
				break;
			case 8:
				table.findElement();
				break;
			case 9:
				table.showContent();
				break;
			case 10:
				break;
			default:
				cout << "nie ma takiej opcji" << endl;
				break;
			}
		} while (whichOption != 10);



		break;
	case 2:
		
		break;
	case 3: 
		
		break;

	default:
		break;
	}



	system("PAUSE");
	return 0;
}

