#include "Asteroid.h"

template <class t>
class node {
public:
	node();
	node(node& newNode);
	~node();

	void setNext(node* newNext);
	void setPrev(node* newPrev);
	void setT(t* newt);
	t* getT();
	node* getNext();
	node* getPrev();
	
private:
	t* data;
	node* mpNext;
	node* mpPrev;
};

template <class t>
node<t>::node() {
	mpNext = nullptr;
	mpPrev = nullptr;
}

template <class t>
node<t>::node(node* newNode) {
	data = newNode.gett();
	mpNext = newNode.getNext();
	mpPrev = newNode.getPrev();
}

template <class t>
node<t>::~node() {
	// no dynamic data
	if (mpPrev != nullptr) {
		mpPrev->setNext(mpNext);
	}
	if (mpNext != nullptr) {
		mpNext->setNext(mpPrev);
	}
}

template <class t>
void node<t>::setNext(node* newNext) {
	mpNext = newNext;
}

template <class t>
void node<t>::setT(t* newT) {
	data = newT;
}

template <class t>
t* node<t>::getT() {
	return mt;
}

template <class t>
node* node<t>::getNext() {
	return mpNext;
}