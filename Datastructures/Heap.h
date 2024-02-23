#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>
#include <stdexcept>

template <class T>
class MinHeap
{
private:
    std::vector<T> heap;
    void sift_down(int index=0);
    void sift_up(int index = this->heap.size() - 1);
};

#endif