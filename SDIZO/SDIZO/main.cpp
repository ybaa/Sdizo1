
#include <stdio.h>
#include <iostream>
#include "Table.h"
#include "List.h"
#include "BinaryHeap.h"
#include <windows.h>

using namespace std;

LARGE_INTEGER startTimer() {
	LARGE_INTEGER start;
	DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
	QueryPerformanceCounter(&start);
	SetThreadAffinityMask(GetCurrentThread(), oldmask);
	return start;
}

LARGE_INTEGER endTimer() {
	LARGE_INTEGER stop;
	DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
	QueryPerformanceCounter(&stop);
	SetThreadAffinityMask(GetCurrentThread(), oldmask);
	return stop;
}


int main()
{
	

	Table table;
	List list;
	BinaryHeap heap;



	LARGE_INTEGER clockFrequency;
	QueryPerformanceFrequency(&clockFrequency);
	LARGE_INTEGER performanceCountStart, performanceCountEnd;
	double time;

	
	int whichStruct;

	do{

		cout << "wybierz strukture: " << endl;
		cout << "[1] Tablica" << endl;
		cout << "[2] Lista" << endl;
		cout << "[3] Kopiec binarny" << endl;
		cout << "[4] Koniec" << endl;
		cin >> whichStruct;

		switch (whichStruct)
		{
		case 1:
			int whichOption;
			do{
				//table.showContent();
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
					performanceCountStart = startTimer();

					for (int i = 0; i < 40000; i++){
						table.addElementToTheBeginning();
					}

					performanceCountEnd = endTimer(); 
					time = (float)(performanceCountEnd.QuadPart - performanceCountStart.QuadPart) / clockFrequency.QuadPart;
					cout <<"Dodaj element na poczatek "<< endl << "Time:" << time << endl;
					break;
				case 2:
					performanceCountStart = startTimer();

					for (int i = 0; i < 40000; i++){
						table.addElementToTheEnd();
					}

					performanceCountEnd = endTimer(); 
					time = (float)(performanceCountEnd.QuadPart - performanceCountStart.QuadPart) / clockFrequency.QuadPart;
					cout <<"Dodaj element na koniec"<< endl << "Time:" << time << endl;
					break;
				case 3:
					performanceCountStart = startTimer();

					for (int i = 0; i < 40000; i++){
						table.addElementSomewhere();
					}

					performanceCountEnd = endTimer(); 
					time = (float)(performanceCountEnd.QuadPart - performanceCountStart.QuadPart) / clockFrequency.QuadPart;
					cout <<"Dodaj element w losowe miejsce"<< endl << "Time:" << time << endl;
					break;
				case 4:
					performanceCountStart = startTimer();

					for (int i = 0; i < 40000; i++){
						table.removeElementFromTheBeginning();
					}

					performanceCountEnd = endTimer(); 
					time = (float)(performanceCountEnd.QuadPart - performanceCountStart.QuadPart) / clockFrequency.QuadPart;
					cout << "Usun element z poczatku" << endl << "Time:" << time << endl;
					break;
				case 5:
					performanceCountStart = startTimer();

					for (int i = 0; i < 40000; i++){
						table.removeElementFromTheEnd();
					}

					performanceCountEnd = endTimer(); 
					time = (float)(performanceCountEnd.QuadPart - performanceCountStart.QuadPart) / clockFrequency.QuadPart;
					cout <<"Usun element na koncu"<< endl << "Time:" << time << endl;
					break;
				case 6:
					performanceCountStart = startTimer();

					for (int i = 0; i < 40000; i++){
						table.removeElementFromSomewhere();
					}

					performanceCountEnd = endTimer(); 
					time = (float)(performanceCountEnd.QuadPart - performanceCountStart.QuadPart) / clockFrequency.QuadPart;
					cout <<"Usun element w losowym miejscu"<< endl << "Time:" << time << endl;
					break;
				case 7:
					performanceCountStart = startTimer();

					
						table.resize();
					

					performanceCountEnd = endTimer();
					time = (float)(performanceCountEnd.QuadPart - performanceCountStart.QuadPart) / clockFrequency.QuadPart;
					cout << "Zmien rozmiar na losowy" << endl << "Time:" << time << endl;
					break;
				case 8:
					performanceCountStart = startTimer();

					for (int i = 0; i < 10000; i++){
						table.findElement();
					}

					performanceCountEnd = endTimer(); 
					time = (float)(performanceCountEnd.QuadPart - performanceCountStart.QuadPart) / clockFrequency.QuadPart;
					cout <<"Znajdz losowy element"<< endl << "Time:" << time << endl;
					break;
				case 9:
					performanceCountStart = startTimer();

			
						table.showContent();
					
					performanceCountEnd = endTimer(); 
					time = (float)(performanceCountEnd.QuadPart - performanceCountStart.QuadPart) / clockFrequency.QuadPart;
					cout <<"Wyswietl zawartosc"<< endl << "Time:" << time << endl;
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
			int whichOption2;
			do{
				//list.showContent();
				cout << endl;
				cout << "wybierz operacje: " << endl;
				cout << "[1] Dodaj element na poczatku" << endl;
				cout << "[2] Dodaj element na koncu" << endl;
				cout << "[3] Dodaj element w losowym miejscu w srodku" << endl;
				cout << "[4] Usun pierwszy element" << endl;
				cout << "[5] Usun ostatni element" << endl;
				cout << "[6] Usun element w losowym miejscu w srodku" << endl;
				cout << "[7] Znajdz element po indeksie" << endl;
				cout << "[8] Znajdz element po wartosci" << endl;
				cout << "[9] Pokaz zawartosc" << endl;
				cout << "[10] Koniec" << endl;
				cin >> whichOption2;

				switch (whichOption2)
				{
				case 1:
					performanceCountStart = startTimer();

					for (int i = 0; i < 80000; i++){
					list.addElementToTheBeginning();
					}

					performanceCountEnd = endTimer(); 
					time = (float)(performanceCountEnd.QuadPart - performanceCountStart.QuadPart) / clockFrequency.QuadPart;
					cout << "Dodaj element na poczatek " << endl << "Time:" << time << endl;
					break;
				case 2:
					performanceCountStart = startTimer();

					for (int i = 0; i < 40000; i++){
					list.addElementToTheEnd();
					}

					performanceCountEnd = endTimer(); 
					time = (float)(performanceCountEnd.QuadPart - performanceCountStart.QuadPart) / clockFrequency.QuadPart;
					cout << "Dodaj element na koniec " << endl << "Time:" << time << endl;
					break;
				case 3:
					performanceCountStart = startTimer();

					for (int i = 0; i < 40000; i++){
					list.addElementSomewhere();
					}

					performanceCountEnd = endTimer(); 
					time = (float)(performanceCountEnd.QuadPart - performanceCountStart.QuadPart) / clockFrequency.QuadPart;
					cout << "Dodaj element w losowe miejsce " << endl << "Time:" << time << endl;
					break;
				case 4:
					performanceCountStart = startTimer();

					for (int i = 0; i < 40000; i++){
					list.removeFirstElement();
					}

					performanceCountEnd = endTimer();
					time = (float)(performanceCountEnd.QuadPart - performanceCountStart.QuadPart) / clockFrequency.QuadPart;
					cout << "Usun element z poczatku " << endl << "Time:" << time << endl;
					break;
				case 5:
					performanceCountStart = startTimer();

					for (int i = 0; i < 40000; i++){
					list.removeLastElement();
					}

					performanceCountEnd = endTimer(); 
					time = (float)(performanceCountEnd.QuadPart - performanceCountStart.QuadPart) / clockFrequency.QuadPart;
					cout << "Usun element z konca " << endl << "Time:" << time << endl;
					break;
				case 6:
					performanceCountStart = startTimer();

					for (int i = 0; i < 40000; i++){
					list.removeSomeElement();
					}

					performanceCountEnd = endTimer(); 
					time = (float)(performanceCountEnd.QuadPart - performanceCountStart.QuadPart) / clockFrequency.QuadPart;
					cout << "Usun element z losowego miejsca " << endl << "Time:" << time << endl;
					break;
				case 7:
					performanceCountStart = startTimer();

					for (int i = 0; i < 10000; i++){
					list.findElement();
					}

					performanceCountEnd = endTimer(); 
					time = (float)(performanceCountEnd.QuadPart - performanceCountStart.QuadPart) / clockFrequency.QuadPart;
					cout << "znajdz" << endl << "Time:" << time << endl;
					break;
				case 8:
					performanceCountStart = startTimer();

					for (int i = 0; i < 10000; i++){
					list.findElementValue();
					}

					performanceCountEnd = endTimer(); 
					time = (float)(performanceCountEnd.QuadPart - performanceCountStart.QuadPart) / clockFrequency.QuadPart;
					cout << "znajdz po wartosci" << endl << "Time:" << time << endl;
					break;
				case 9:
					performanceCountStart = startTimer();

					
					list.showContent();
					

					performanceCountEnd = endTimer(); 
					time = (float)(performanceCountEnd.QuadPart - performanceCountStart.QuadPart) / clockFrequency.QuadPart;
					cout << "Usun element z poczatku " << endl << "Time:" << time << endl;
					break;
				case 10:
					break;
				default:
					cout << "nie ma takiej opcji" << endl;
					break;
				}
			} while (whichOption2 != 10);


			break;
		case 3:

			int whichOption3;
			do{
				//heap.showContent();
				//cout << endl;
				//heap.draw();
				cout << endl;
				cout << "wybierz operacje: " << endl;
				cout << "[1] Dodaj element" << endl;
				cout << "[2] Usun korzen" << endl;
				cout << "[3] Znajdz element" << endl;
				cout << "[4] Koniec" << endl;
				cin >> whichOption3;

				switch (whichOption3)
				{
				case 1:
					performanceCountStart = startTimer();

					for (int i = 0; i < 80000; i++){
					heap.addElement();
					}
					performanceCountEnd = endTimer(); 
					time = (float)(performanceCountEnd.QuadPart - performanceCountStart.QuadPart) / clockFrequency.QuadPart;
					cout << "Dodaj element" << endl << "Time:" << time << endl;
					break;
				case 2:
					performanceCountStart = startTimer();

					for (int i = 0; i < 40000; i++){
					heap.removeRoot();
					}
					performanceCountEnd = endTimer(); 
					time = (float)(performanceCountEnd.QuadPart - performanceCountStart.QuadPart) / clockFrequency.QuadPart;
					cout << "usun korzen" << endl << "Time:" << time << endl;
					break;
				case 3:
					performanceCountStart = startTimer();

					for (int i = 0; i < 10000; i++){
					heap.findElement();
					}
					performanceCountEnd = endTimer(); 
					time = (float)(performanceCountEnd.QuadPart - performanceCountStart.QuadPart) / clockFrequency.QuadPart;
					cout << "Znajdz element" << endl << "Time:" << time << endl;
					break;
				case 4:

					break;

				default:
					cout << "nie ma takiej opcji" << endl;
					break;
				}
			} while (whichOption3 < 4);


		case 4:
			break;

			break;

		default:
			cout << "nie ma takiej opcji" << endl;
			break;
		}
	}while (whichStruct != 4);


	system("PAUSE");
	return 0;
}

