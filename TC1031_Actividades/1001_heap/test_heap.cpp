#include <iostream>
#include "heap.h"

int main(int argc, char* argv[]) {
  
  Heap<int> heap(20);

  heap.add(10);
  std::cout << heap.toString() << "\n";
  heap.add(1);
  std::cout << heap.toString() << "\n";
  heap.add(5);
  std::cout << heap.toString() << "\n";

  std::cout << "remove = " << heap.remove() << "\n";
  std::cout << heap.toString() << "\n";
  std::cout << "remove = " << heap.remove() << "\n";
  std::cout << heap.toString() << "\n";
  std::cout << "remove = " << heap.remove() << "\n";
  std::cout << heap.toString() << "\n";
  return 0;
}
