

#ifndef PQUEUE_H
#define PQUEUE_H

#include <string>
#include <sstream>
#include "header.h"
#include "queue.h"

template <class T> class PriorityQueue;

template <class T>
class Node {
private:
	Node(T);
	Node(T, Node<T>*, Node<T>*);

	T	    value;
	Node<T> *previous;
	Node<T> *next;

	friend class PriorityQueue<T>;
};


template <class T>
Node<T>::Node(T val)
	: value(val), previous(0), next(0) {}


template <class T>
Node<T>::Node(T val, Node *prev, Node* nxt)
	: value(val), previous(prev), next(nxt) {}


template <class T>
class PriorityQueue : public Queue<T>{
private:
	Node<T> *head;
	Node<T> *tail;

public:
	PriorityQueue();
	~PriorityQueue();

	void enqueue(T);
	void dequeue();
	T front() const;
	bool empty() const;
	void clear();
	std::string toString() const;
};


template <class T>
PriorityQueue<T>::PriorityQueue()
	: head(NULL), tail(NULL) {}


template <class T>
PriorityQueue<T>::~PriorityQueue() {
	clear();
}



template <class T>
bool PriorityQueue<T>::empty() const {
	return (head == NULL && tail == NULL);
}


template <class T>
void PriorityQueue<T>::enqueue(T val) {
	Node<T> *p, *q, *new_link;

	new_link = new Node<T>(val);
	if (empty()) {
		head = new_link;
		tail = new_link;
		return;
	}

	if (val <= head->value) {
		new_link->next = head;
		head->previous = new_link;
		head = new_link;
		return;
	}

	if (val >= tail->value) {
		new_link->previous = tail;
		tail->next= new_link;
		tail = new_link;
		return;
	}

	p = head;
	while (p != NULL)
	 	if (p->value >= val) {
			break;
		}
		p = p->next;
	}

	q = p->previous;
	new_link->next = p;
	new_link->previous = q;

	q->next = new_link;
	p->previous = new_link;
}


template <class T>
T PriorityQueue<T>::front() const {
	if (empty()) {
		throw NoSuchElement();
	}
	return head->value;
}


template <class T>
void PriorityQueue<T>::dequeue() {
	Node<T> *p;
	
	if (empty()) {
		throw NoSuchElement();
	}

	p = head;
	if (head == tail) {
		head = NULL;
		tail = NULL;
	} else {
		head = p->next;
		p->next->previous = NULL;
	}
	delete p;
}


template <class T>
void PriorityQueue<T>::clear() {
	Node<T> *p, *q;

	p = head;
	while (p != NULL) {
		q = p->next;
		delete p;
		p = q;
	}
	head = NULL;
	tail = NULL;
}


template <class T>
std::string PriorityQueue<T>::toString() const {
	std::stringstream aux;
	Node<T> *p;

	p = head;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->next != NULL) {
			aux << ", ";
		}
		p = p->next;
	}
	aux << "]";
	return aux.str();
}
#endif 
