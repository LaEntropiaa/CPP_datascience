#include "Heap.h"

int main()
{
    MinHeap<int> heap;
    heap.append(88);
    heap.append(36);
    heap.append(22);
    heap.append(89);
    heap.append(65);
    heap.append(45);
    heap.append(11);
    heap.append(13);

    std::cout << heap ;
  
    return 0;
}