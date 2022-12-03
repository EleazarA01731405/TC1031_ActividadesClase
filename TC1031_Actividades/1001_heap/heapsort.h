
#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "header.h"
#include <vector>

int parent(int pos) {
	return (pos - 1) / 2;
}

int left(int pos) {
	return (pos * 2) + 1;
}

int right(int pos) {
	return (pos * 2) + 2;
}

template <class T>
void heapify(T *arr, int size, int pos) {
	uint le = left(pos);
	uint ri = right(pos);
	uint max = pos;

	if(le < size && arr[le] > arr[max]){
		max = le;
	}
	if(ri < size && arr[ri] > arr[max]){
		max = ri;
	}

	if(max != pos){
		swap(arr, pos, max);
		heapify(arr, size, max);
	}
}

template <class T>
void buildMaxHeap(T *arr, int size) {
	for (int i = (size / 2) - 1; i >= 0; i--) {
		heapify(arr, size, i);
	}
}

template <class T>
void heapSort(T *arr, int size) {
	int max = size, i;

	buildMaxHeap(arr, max);
	for (i = size - 1; i > 0; i--) {
		swap(arr, i, 0);
		max--;
		heapify(arr, max, 0);
	}
}

template <class T>
void heapify(std::vector<T> &arr, int size, int pos) {
	uint le = left(pos);
	uint ri = right(pos);
	uint max = pos;

	if(le < size && arr[le] > arr[max]){
		max = le;
	}
	if(ri < size && arr[ri] > arr[max]){
		max = ri;
	}

	if(max != pos){
		swap(arr, pos, max);
		heapify(arr, size, max);
	}
}

template <class T>
void buildMaxHeap(std::vector<T> &arr, int size) {
	for (int i = (size / 2) - 1; i >= 0; i--) {
		heapify(arr, size, i);
	}
}

template <class T>
void heapSort(std::vector<T> &arr) {
	int i, max;

	max = arr.size() - 1;
	buildMaxHeap(arr, max);
	for (i = arr.size() - 1; i > 0; i--) {
		swap(arr, i, 0);
		max--;
		heapify(arr, max, 0);
	}
}
#endif 
