

#ifndef DEQUEUE_H
#define DEQUEUE_H

#include <string>
#include <sstream>
#include "header.h"

template <class T> class Dequeue;


template <class T>
class Node {
private:
	Node(T);
	Node(T, Node<T>*, Node<T>*);

	T	    	value;
	Node<T> *previous;
	Node<T> *next;

	friend class Dequeue<T>;
};


template <class T>
Node<T>::Node(T val)
	: value(val), previous(0), next(0) {}


template <class T>
Node<T>::Node(T val, Node *prev, Node* nxt)
	: value(val), previous(prev), next(nxt) {}


template <class T>
class Dequeue {
private:
	Node<T> *head;
	Node<T> *tail;
	uint 	 size;

public:
	Dequeue();
	~Dequeue();

	bool empty() const;
	uint length() const;
	bool contains(T) const;
	void clear();

	T    front() const;
	T		 last() const;

	void push_front(T);
	void push_back(T);

	void pop_front();
	void pop_back();

	std::string toString() const;
};


template <class T>
Dequeue<T>::Dequeue()
	: head(NULL), tail(NULL), size(0) {}


template <class T>
Dequeue<T>::~Dequeue() {
	clear();
}


template <class T>
bool Dequeue<T>::empty() const {
	return (head == NULL && tail == NULL);
}


template <class T>
uint Dequeue<T>::length() const {
	return size;
}


template <class T>
bool Dequeue<T>::contains(T val) const {
	Node<T> *p;

	p = head;
	while (p != NULL) {
		if (p->value == val) {
			return true;
		}
		p = p->next;
	}
	return false;
}


template <class T>
void Dequeue<T>::clear() {
	Node<T> *p, *q;

	p = head;
	while (p != NULL) {
		q = p->next;
		delete p;
		p = q;
	}
	head = NULL;
	tail = NULL;
	size = 0;
}


template <class T>
T Dequeue<T>::front() const {
	if (empty()) {
		throw NoSuchElement();
	}
	return head->value;
}



template <class T>
T Dequeue<T>::last() const {
	if (empty()) {
		throw NoSuchElement();
	}
	return tail->value;
}


template <class T>
void Dequeue<T>::push_front(T val) {
	Node<T> *new_link;
	new_link = new Node<T>(val);

	if (empty()) {
		head = new_link;
		tail = new_link;
	} else {
		new_link->next = head;
		head->previous = new_link;
		head = new_link;
	}
	size++;
}


template <class T>
void Dequeue<T>::push_back(T val) {
	Node<T> *new_link;
	new_link = new Node<T>(val);

	if (empty()) {
		head = new_link;
		tail = new_link;
	} else {
		new_link->previous = tail;
		tail->next= new_link;
		tail = new_link;
	}
	size++;
}

template <class T>
void Dequeue<T>::pop_front() {
	Node<T> *p;
	T val;

	if (empty()) {
		throw NoSuchElement();
	}

	p = head;
	val = p->value;
	if (head == tail) {
		head = NULL;
		tail = NULL;
	} else {
		head = p->next;
		p->next->previous = NULL;
	}
	delete p;
	size--;
}


template <class T>
void Dequeue<T>::pop_back() {
	T val;
	Node<T> *p;

	if (empty()) {
		throw NoSuchElement();
	}

	p = tail;
	val = p->value;
	if (head == tail) {
		head = NULL;
		tail = NULL;
	} else {
		tail = p->previous;
		p->previous->next = NULL;
	}
	delete p;
	size--;
}


template <class T>
std::string Dequeue<T>::toString() const {
	std::stringstream aux;
	Node<T> *p;

	p = head;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->next != 0) {
			aux << ", ";
		}
		p = p->next;
	}
	aux << "]";
	return aux.str();
}
#endif 
