#pragma once
#include <iostream>

template <class D>
class StackNode
{
public:
	StackNode() : data{ NULL }, pNext { nullptr }
	{
		std::cout << "In StackNode base constructor" << std::endl;
	}

	StackNode(const D& initData, StackNode*& initNext) : data{ initData }, pNext{ initNext }
	{
		std::cout << "In StackNode data constructor" << std::endl;
	}

	~StackNode()
	{
		std::cout << "In StackNode destructor" << std::endl;
	}

	D& getData();
	StackNode*& getpNext();

	void setData(D& newData);
	void setpNext(StackNode*& next);
private:
	D data;
	StackNode *pNext;
};

template <class D>
D& StackNode<D>::getData()
{
	return data;
}

template <class D>
StackNode<D>*& StackNode<D>::getpNext()
{
	return pNext;
}

template <class D>
void StackNode<D>::setData(D& newData)
{
	data = newData;
}

template <class D>
void StackNode<D>::setpNext(StackNode*& next)
{
	pNext = next;
}