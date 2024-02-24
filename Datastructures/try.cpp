#include "Heap.h"
#include <iostream>

int main()
{
    MinHeap<int> heap;
    heap.append(88);
    heap.append(36);
    heap.append(22);
    heap.append(89);
    heap.append(65);
    heap.append(45);
    std::cout << heap;
  
    return 0;
}