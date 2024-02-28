#include "Heap.h"
#include <vector>

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

    std::cout << heap <<"\n";
    std::vector<int> list = heap.heapsort();
    for (int i : list)
    {
        std::cout << i << "-";
    }
    std::cout << "\n" << heap;
  
    return 0;
}