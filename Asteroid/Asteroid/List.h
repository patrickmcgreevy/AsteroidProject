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

	void deleteNode(node<T> * pCon);

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
	//std::cout << "Inside List destructor." << std::endl;
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
			pCur->getNext()->setPrev(nullptr);
			mpHead = pCur->getNext();
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

template <class T>
void List<T>::deleteNode(node<T> * pCon)
{
	node<T> * pCur = mpHead;
	while (pCur != nullptr && pCur != pCon)
	{
		pCur = pCur->getNext();
	}
	if (pCur != nullptr)
	{
		if (pCur->getPrev() != nullptr)
		{
			pCur->getPrev()->setNext(pCur->getNext());
		}

		if (pCur->getNext() != nullptr)
		{
			pCur->getNext()->setPrev(pCur->getPrev());
		}

		if (pCur == mpHead)
		{
			mpHead = pCur->getNext();
		}

		delete pCur;
	}
}