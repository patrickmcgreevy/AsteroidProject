//#include "Asteroid.h"
#pragma once

template <class t>
class node {
public:
	node();
	node(t & newData);
	~node();

	void setNext(node* newNext);
	void setPrev(node* newPrev);
	void setData(t & newt);
	t & getData();
	node<t>* getNext();
	node<t>* getPrev();
	
private:
	t data;
	node<t>* mpNext;
	node<t>* mpPrev;
};

template <class t>
node<t>::node() {
	mpNext = nullptr;
	mpPrev = nullptr;
}

template <class t>
node<t>::node(t & newData)
{
	data = newData;
	mpNext = nullptr;
	mpPrev = nullptr;
}

template <class t>
node<t>::~node() {
	delete data;
}

template <class t>
void node<t>::setNext(node* newNext) {
	mpNext = newNext;
}

template <class t>
void node<t>::setPrev(node* newPrev)
{
	mpPrev = newPrev;
}

template <class t>
void node<t>::setData(t & newT) {
	data = newT;
}

template <class t>
t & node<t>::getData()
{
	return data;
}

template <class t>
node<t>* node<t>::getNext() {
	return mpNext;
}

template <class t>
node<t>* node<t>::getPrev()
{
	return mpPrev;
}