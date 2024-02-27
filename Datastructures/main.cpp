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

    heap.push(42);
    std::cout << heap <<"\n";
    std::cout << heap.pop() << "\n";
    std::cout << heap << "\n";
  
    return 0;
}