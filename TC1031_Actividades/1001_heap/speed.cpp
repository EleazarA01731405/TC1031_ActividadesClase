
#include <iostream>
#include "header.h"
#include "heapsort.h"

using namespace std;

void fillArray(int *A, int size) {
  for (int i = 0; i < size - 1; i++) {
    A[i] = size - i + 1;
    //A[i] = i;
  }
}

int main(int argc, char* argv[]) {
  int *arr;
  int size = 1000;
  Chronometer c;
  double ms;

  for (int i = 0; i < 5; i++) {
    std::cout << "Starting size = " << size <<  "...";
    arr = new int[size];
    fillArray(arr, size);
    c.start();
    heapSort(arr, size);
    ms = c.stop();
    std::cout<< " time = " << ms << " ms\n";
    delete [] arr;
    size *= 10;
  }
  return 0;
}
