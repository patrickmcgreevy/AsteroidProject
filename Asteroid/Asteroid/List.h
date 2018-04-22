#pragma once
#include "ListNode.h"

template <class T>
class List {
public:
	List();
	~List();

	node<T>* getHead();
	void setHead(node<T>* newHead);

	void insertAtFront(T & newData);

	bool isEmpty();

private:
	void destrucorHelper();

	node<T>* mpHead;
	//node<T>* mpTail;
};

template <class T>
List<T>::List()
{
	mpHead = nullptr;
	//mpTail = nullptr;
}

template <class T>
List<T>::~List()
{
	std::cout << "Inside List destructor." << std::endl;
	while (mpHead != nullptr)
	{
		destrucorHelper();
	}
}

template <class T>
void List<T>::destrucorHelper()
{
	if (mpHead != nullptr)
	{
		node<T> * pCur = mpHead;

		if (mpHead->getNext() != nullptr)
		{
			mpHead->getNext()->setPrev(nullptr);
			mpHead = mpHead->getNext();
		}
		else
		{
			mpHead = nullptr;
		}

		delete pCur;
	}
}

template <class T>
bool List<T>::isEmpty()
{
	if (mpHead != nullptr)
	{
		return true;
	}
	return false;
}

template <class T>
node<T>* List<T>::getHead()
{
	return mpHead;
}

template <class T>
void List<T>::setHead(node<T>* newHead)
{
	mpHead = newHead;
}

template <class T>
void List<T>::insertAtFront(T & newData)
{
	node<T> * pNew = new node<T>(newData);
	if (pNew != nullptr)
	{
		pNew->setNext(mpHead);

		if (mpHead != nullptr)
		{
			mpHead->setPrev(pNew);
		}

		mpHead = pNew;
	}
}