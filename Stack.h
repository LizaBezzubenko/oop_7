#pragma once
#include "ProductNode.h"
#include "Exeption.h"
#include <iostream>

using namespace std;

struct Stack
{
	ProductNode* data;
	Stack* next;
	void push(Stack**, ProductNode*);
	void pop(Stack**);
};

void Stack::push(Stack** head, ProductNode* Data)
{
	Stack* node = new Stack;
	node->next = (*head);
	node->data = Data;
	(*head) = node;
}

void Stack::pop(Stack** head)
{
	if (!(*head))
	{
		myExep("Stack is empty.");
	}
	cout << "Data\n";
	cout << "Count: " << (*head)->data->count << endl;
	cout << "Storage duration: " << (*head)->data->date << endl;
	cout << "Name: " << (*head)->data->name << endl;
	cout << "Price: " << (*head)->data->price << endl;
	Stack* st = (*head);
	(*head) = (*head)->next;
	delete st;
}