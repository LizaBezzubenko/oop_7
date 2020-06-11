
#pragma once
#include <iostream>
#include <locale>
#include <string>
#include <map>
#include "Stack.h"
#include "Exeption.h"
#include "ProductNode.h"

using namespace std;

class Algoritm {
	map<int, ProductNode*> myMap;
	Stack* MyStack;
public:
	void Menu();
	void showMap();
	void MoreThan10();
	bool LessThan20();
	void showStack();
	void AddElement();
};

void Algoritm::Menu()
{
	map< int, ProductNode*>::iterator  myIter, myIter2;
	ProductNode* obj;
	MyStack = nullptr;
	int num, count;
	do
	{
		try
		{
			cout << "1. Add Element\n";
			cout << "2. Find Element(by key)\n";
			cout << "3. Sort by count\n";
			cout << "4. Enough\n";
			rewind(stdin);
			if (!(cin >> num))
			{
				cin.clear();
				rewind(stdin);
				throw myExep("error: incorrect input");
			}
			rewind(stdin);
			switch (num)
			{
			case 1:
				AddElement();
				break;
			case 2:
				cout << "Input COUNT: ";
				if (!(cin >> count))
				{
					cin.clear();
					rewind(stdin);
				}
				myIter2 = myMap.find(count);
				if (myIter2 != myMap.end())
				{
					cout << "Count: " << myIter2->second->count << endl;
					cout << "Storage duration: " << myIter2->second->date << endl;
					cout << "Name: " << myIter2->second->name << endl;
					cout << "Price: " << myIter2->second->price << endl;
				}
				/*else
				{
					cout << "error: nullptr\n";
				}*/
			case 3:
				showMap();
			}
		}
		catch (myExep exep)
		{
			cout << exep.ShowExepName() << endl;
		}
	} while (num != 4); //*********** 3
	if (myMap.begin() == myMap.end())
	{
		cout << "Container is empty\n";
		return;
	}
	//***********  showMap();
	cout << "1. Condition: stock days more than 10.\n";
	cout << "2. Condition: push all prices less than 20 into the stack.\n";
	do
	{
		rewind(stdin);
		while (!(cin >> num))
		{
			cin.clear();
			rewind(stdin);
		}
		rewind(stdin);
	} while (num < 1 || num > 2);
	switch (num)
	{
	case 1:
		MoreThan10();
		break;
	case 2:
		if (LessThan20())
		{
			showStack();
		}
		break;
	}

}

inline void Algoritm::showMap()
{
	cout << "Sort by COUNT: \n";
	map< int, ProductNode*>::iterator myIter;
	for (myIter = myMap.begin(); myIter != myMap.end(); myIter++)
	{
		cout << "Count: " << myIter->second->count << endl;
		cout << "Storage duration: " << myIter->second->date << endl;
		cout << "Name: " << myIter->second->name << endl;
		cout << "Price: " << myIter->second->price << endl;
	}
}

void Algoritm::AddElement()
{

	ProductNode* objProd = new ProductNode;
	cout << "Enter name: ";
	rewind(stdin);
	cin >> objProd->name;
	rewind(stdin);
	cout << "Enter count: ";
	rewind(stdin);
	while (!(cin >> objProd->count))
	{
		cin.clear();
		rewind(stdin);
	}
	rewind(stdin);
	cout << "Enter storage duration: ";
	while (!(cin >> objProd->date))
	{
		cin.clear();
		rewind(stdin);
	}
	rewind(stdin);
	cout << "Enter price: ";
	while (!(cin >> objProd->price))
	{
		cin.clear();
		rewind(stdin);
	}
	rewind(stdin);
	myMap.emplace(objProd->count, objProd);
}


void Algoritm::MoreThan10()
{
	bool flag = true;
	map<int, ProductNode*>::iterator myIter;
	for (myIter = myMap.begin(); myIter != myMap.end(); myIter++)
	{
		if (myIter->second->date <= 10)
		{
			flag = false;
			cout << "This element does not satisfy the condition:\n";
			cout << "Count: " << myIter->second->count << endl;
			cout << "Storage duration: " << myIter->second->date << endl;
			cout << "Name: " << myIter->second->name << endl;
			cout << "Price: " << myIter->second->price << endl;
		}
	}
	if (flag)
	{
		cout << "All items are suitable\n";
	}
	system("pause");
}


//********** здесь происходит копирование множества элементов, удовл условию,  в стек *******
bool Algoritm::LessThan20()
{
	bool flag = false;
	map<int, ProductNode*>::iterator myIter;
	for (myIter = myMap.begin(); myIter != myMap.end(); myIter++)
	{
		if (myIter->second->price < 20.0)  
		{
			flag = true;
			MyStack->push(&MyStack, myIter->second);   // ******здееесь
		}
	}
	if (!flag)
	{
		cout << "No matching items\n";
	}
	return flag;
	system("pause");
}

void Algoritm::showStack()
{
	if (!MyStack)
	{
		myExep("error: stack is empty");
	}
	while (MyStack)
	{
		MyStack->pop(&MyStack);
	}
}
