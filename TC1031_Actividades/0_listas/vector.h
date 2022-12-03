
#ifndef VECTOR_H
#define VECTOR_H

#include "exception.h"
#include <string>
#include <sstream>

typedef unsigned int uint;

template <class T>
class Vector {
private:
	uint size;
	T	*data;

public:
	Vector();
	Vector(uint);
	Vector(uint, T);
	Vector(const Vector<T>&);
	~Vector();

	uint length() const;
	uint resize(uint);
	std::string toString() const;

	T& operator[](uint) const;
	Vector<T>& operator=(const Vector<T>&);
};

template <class T>
Vector<T>::Vector() {
	size = 1;
	data = new T[size];
	if(data == 0){
		throw OutOfMemory();
	}
}

template <class T>
Vector<T>::Vector(uint elements) {
	if(elements == 0){
		throw RangeError();
	}

	size = elements;
	data = new T[size];
	if(data == 0){
		throw OutOfMemory();
	}
}

template <class T>
Vector<T>::Vector(uint elements, T initialValue) {
	if(elements == 0){
		throw RangeError();
	}
	size = elements;
	data = new T[size];
	if(data == 0){
		throw OutOfMemory();
	}

	for (uint i = 0; i < size; i++) {
		data[i] = initialValue;
	}
}

template <class T>
Vector<T>::Vector(const Vector<T> &source) {
	size = source.size;
	data = new T[size];
	if(data == 0){
		throw OutOfMemory();
	}
	for(uint i = 0; i < size; i++){
		data[i] = source.data[i];
	}
}


template <class T>
Vector<T>::~Vector() {
	delete [] data;
	data = 0; //NULL o nullptr
	size = 0;
}

template <class T>
uint Vector<T>::length() const {
	return size;
}

template <class T>
uint Vector<T>::resize(uint newSize) {
	if (newSize == 0){
		throw RangeError();
	}

	if (size == newSize) {
		return size;
	}

	T *newData = new T[newSize];
	if(newData == 0){
		throw OutOfMemory();
	}

	if(newSize < size){
		for(uint i = 0; i < newSize; i++) {
			newData[i] = data[i];
		}
	} else{
		for(uint i = 0; i < size; i++) {
			newData[i] = data[i];
		}
	}

	delete [] data;
	data = newData;
	size = newSize;

	return size;
}

template <class T>
std::string Vector<T>::toString() const {
	std::stringstream aux;

	aux << "[" << data[0];
	for (uint i = 1; i < size; i++) {
		aux << ", " << data[i];
	}
	aux << "]";
	return aux.str();
}

template <class T>
T& Vector<T>::operator[] (uint index) const {
	if(index >= size){
		throw IndexOutOfBounds();
	}
	return data[index];
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T> &right) {
	if(size != right.size){
		resize(right.size);
	}
	for(uint i =0; i < right.size; i++){
		data[i] = right.data[i];
	}
	return (*this);
}

#endif 
