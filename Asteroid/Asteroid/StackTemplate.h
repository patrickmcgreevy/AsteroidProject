// StackNodeTemplate.h depedent
// Referenced user amitapm @ http://www.cplusplus.com/forum/general/81166/ on 3/19/2018

#pragma once
#include <iostream>
#include "StackNodeTemplate.h"

template<class T>
class Stack
{
public:
	Stack()
		:pHead{nullptr}
	{
		std::cout << "Inside Stack constructor" << std::endl;
	}

	Stack(Stack<T>& oldStack) : pHead{nullptr}
	{
		if (!(oldStack.isEmpty()))
		{
			/*StackNode<T> newNode = oldStack.*pHead;
			copyHelper(newNode);*/
			copyHelper(oldStack.pHead);
		}
	}

	~Stack()
	{
		std::cout << "Inside Stack destructor" << std::endl;
		// pop it all
		while (!isEmpty())
		{
			//pop();
			destructorHelper();
		}
	}

	bool isEmpty();
	T& peek();
	bool push(const T& newData);
	T pop();
private:
	StackNode<T> *pHead;

	void destructorHelper();
	void copyHelper(StackNode<T> *node);
};

template <class T>
bool Stack<T>::isEmpty()
{
	if (pHead != nullptr)
	{
		return false;
	}
	return true;
}

template <class T>
T& Stack<T>::peek()
{
	return pHead->getData();
}

template <class T>
bool Stack<T>::push(const T& newData)
{
	bool success = false;
	StackNode<T>* pNew = new StackNode<T>(newData, pHead);

	if (pNew != nullptr)
	{
		success = true;
		pHead = pNew;
	}

	return success;
}

template <class T>
T Stack<T>::pop()
{
	StackNode<T> temp;
	if (!isEmpty())
	{
		StackNode<T>* pTemp = pHead;
		pHead = pHead->getpNext();
		temp = *pTemp;
		delete pTemp;
	}
	return temp.getData();
}

template <class T>
void Stack<T>::destructorHelper()
{
	//StackNode<T> temp;
	if (!isEmpty())
	{
		StackNode<T>* pTemp = pHead;
		pHead = pHead->getpNext();
		//temp = *pTemp;
		delete pTemp;
	}
	//return temp.getData();
}

template <class T>
void Stack<T>::copyHelper(StackNode<T> *node)
{
	if (node != nullptr)
	{
		if (node->getpNext() != nullptr)
		{
			copyHelper(node->getpNext());
		}
		this->push(node->getData());
	}
}