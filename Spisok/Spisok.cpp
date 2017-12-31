// Spisok.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib> // Для работы с функцией system()
#include "List.h"
#include "Struct.h"

using namespace std;

void print();
void getInt();
void getString();
void getStruct();
int getPolyzenieChislaInt(int min1, int max1);
void menuSpisok();



int main()
{	
	print();
	//list.pop_front();

	//cout << "Size: " << list.size() << endl;
	//list.print();

	system("pause"); // Команда задержки экрана
    return 0;
}


void print()
{	
	system("cls");
	int n;
	
	do {
		cout << "1.Chislovoy\n";
		cout << "2.Strokovoy\n";
		cout << "3.Structura\n";
		cout << "4.Exit\n";
		n = getPolyzenieChislaInt(1, 4);

		switch (n)
		{
		case 1: getInt();
			break;
		case 2: getString();
			break;
		case 3: getStruct();
			break;
		default:
			break;
		}

	} while (n != 4);
}

void getInt()
{	
	int n;
	int chislo;
	List<int> list; //инициализация

	do {
		menuSpisok();
		n = getPolyzenieChislaInt(1, 11);

		switch (n)
		{
		case 1:  list.clear();  //очистка списка
			break;
		case 2:  
			cout << "Vvedite chislo: ";
			chislo = getPolyzenieChislaInt(-1000, 1000);
			list.push_front(chislo);
			break;
		case 3:  
			cout << "Vvedite chislo: ";
			chislo = getPolyzenieChislaInt(-1000, 1000);
			list.push_back(chislo);
			break;
		case 4:  list.print();
			break;
		case 5:  cout << "Proverka Semmitria: " << list.proverka_Semmitria() << endl;
			break;
		case 6:  cout << "Proverka Yporyad: " << list.proverka_Yporyad() << '\n' << endl;
			break;
		case 7:  cout << "Kol: " << list.getSizeIcluzive() << endl;
			break;
		case 8:  list.deletSpicokPovtor();
			break;
		case 9:  list.reverse();
			break;
		case 10:  list.sort();
			break;

		default:
			break;
		}

	} while (n != 11);

	print();

	/*
	list.push_back(2);
	list.push_front(3);
	list.push_front(5);
	list.push_front(6);
	list.push_front(6);
	list.push_front(5);

	cout << "Size: " << list.size() << endl;
	list.print();

	list.pop_back();
	list.print();

	cout << "Sort: ";
	list.sort();
	list.print();

	cout << "Reverse: ";
	list.reverse();
	list.print();

	cout << "Kol: " << list.getSizeIcluzive() << endl;

	list.deletSpicokPovtor();
	cout << "Size: " << list.size() << endl;
	list.print();

	list.push_back(5);
	list.push_back(6);
	list.print();
	cout << "Proverka Semmitria: " << list.proverka_Semmitria() << endl;

	list.pop_front();
	list.print();
	cout << "Proverka Yporyad: " << list.proverka_Yporyad() << '\n' << endl;
	*/
}

void getString()
{
	int n;
	string stroka;
	List<string> list; //инициализация

	do {
		menuSpisok();
		n = getPolyzenieChislaInt(1, 11);

		switch (n)
		{
		case 1:  list.clear();  //очистка списка
			break;
		case 2:
			cout << "Vvedite stroky: ";
			cin >> stroka;
			list.push_front(stroka);
			break;
		case 3:
			cout << "Vvedite stroky: ";
			cin >> stroka;
			list.push_back(stroka);
			break;
		case 4:  list.print();
			break;
		case 5:  cout << "Proverka Semmitria: " << list.proverka_Semmitria() << endl;
			break;
		case 6:  cout << "Proverka Yporyad: " << list.proverka_Yporyad() << '\n' << endl;
			break;
		case 7:  cout << "Kol: " << list.getSizeIcluzive() << endl;
			break;
		case 8:  list.deletSpicokPovtor();
			break;
		case 9:  list.reverse();
			break;
		case 10:  list.sort();
			break;

		default:
			break;
		}

	} while (n != 11);

	print();

	/*List<string> list;
	list.push_back("hello");
	list.push_front("apple");
	list.push_front("gren");
	list.push_front("blue");
	list.push_front("orange");
	list.push_front("balck");

	cout << "Size: " << list.size() << endl;
	list.print();

	list.pop_back();
	list.print();

	cout << "Sort: ";
	list.sort();
	list.print();

	cout << "Reverse: ";
	list.reverse();
	list.print();

	cout << "Kol: " << list.getSizeIcluzive() << endl;

	list.deletSpicokPovtor();
	cout << "Size: " << list.size() << endl;
	list.print();

	list.push_back("one");
	list.push_back("two");
	list.print();
	cout << "Proverka Semmitria: " << list.proverka_Semmitria() << endl;

	list.pop_front();
	list.print();
	cout << "Proverka Yporyad: " << list.proverka_Yporyad() << '\n' << endl;
	*/
}

void getStruct()
{	
	int n;
	Struct a;
	List<Struct> list; //инициализация

	do {
		menuSpisok();
		n = getPolyzenieChislaInt(1, 11);

		switch (n)
		{
		case 1:  list.clear();  //очистка списка
			break;
		case 2:
			cout << "Vvedite chislo: ";
			cin >> a.chislo;
			cout << "Vvedite date: ";
			cin >> a.date;
			list.push_front(a);
			break;
		case 3:
			cout << "Vvedite chislo: ";
			cin >> a.chislo;
			cout << "Vvedite date: ";
			cin >> a.date;
			list.push_back(a);
			break;
		case 4:  list.print();
			break;
		case 5:  cout << "Proverka Semmitria: " << list.proverka_Semmitria() << endl;
			break;
		case 6:  cout << "Proverka Yporyad: " << list.proverka_Yporyad() << '\n' << endl;
			break;
		case 7:  cout << "Kol: " << list.getSizeIcluzive() << endl;
			break;
		case 8:  list.deletSpicokPovtor();
			break;
		case 9:  list.reverse();
			break;
		case 10:  list.sort();
			break;

		default:
			break;
		}

	} while (n != 11);

	print();


	/*Struct a;
	a.chislo = 10;
	a.date = "Apple";

	List<Struct> list;
	list.push_back(a);
	a.chislo = 20;
	a.date = "Gren";
	list.push_front(a);
	a.chislo = 12;
	a.date = "Blue";
	list.push_front(a);
	a.chislo = 14;
	a.date = "Black";
	list.push_front(a);
	a.chislo = 99;
	a.date = "Orange";
	list.push_front(a);
	a.chislo = 15;
	a.date = "Red";
	list.push_front(a);
	list.push_front(a);


	cout << "Size: " << list.size() << endl;
	list.print();

	list.pop_back();
	list.print();

	cout << "Sort: ";
	list.sort();
	list.print();

	cout << "Reverse: ";
	list.reverse();
	list.print();

	cout << "Kol: " << list.getSizeIcluzive() << endl; 

	list.deletSpicokPovtor(); //Удаляет по полю chislo
	cout << "Ydalenie povtor\n";
	cout << "Size: " << list.size() << endl;
	list.print();

	a.chislo = 14;
	a.date = "Battles";
	list.push_front(a);
	a.chislo = 30;
	a.date = "Wins";
	list.push_front(a);

	list.print();
	cout << "Proverka Semmitria: " << list.proverka_Semmitria() << endl;

	list.pop_front();  //Удаление элемента
	list.print();
	cout << "Proverka Yporyad: " << list.proverka_Yporyad() << '\n' << endl;
	*/
	
}

//получение числа int
int getPolyzenieChislaInt(int min1, int max1)
{
	int n;

	while (true)
	{
		cin >> n;
		if (!cin)
		{
			cout << "Ne verno, vvedite chslo\n";
			cin.clear();
			while (cin.get() != '\n');
		}
		else {
			if (n >= min1 && n <= max1)
				break;
			else
			{
				cout << "Ne pravilno, vvedite ot " << min1 << " do " << max1 << endl;
				continue;
			}
		}
	}
	return n;

}

void menuSpisok()
{
	cout << "\n1. Inizialization\n";
	cout << "2. Push_front\n";
	cout << "3. Pop_front\n";
	cout << "4. Print element\n";
	cout << "5. Proverka simmetria spiska\n";
	cout << "6. Proverka  na ydalenie dvyx elementov\n";
	cout << "7. Vivod kolizestvo raznix elementov\n";
	cout << "8. Delete povtorov\n";
	cout << "9. Reverse spisok\n";
	cout << "10. Sortirovka\n";
	cout << "11. Backward\n";
}

