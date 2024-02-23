#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>

template <class T>
class MinHeap
{
private:
    std::vector<T> heap;
    void sift_down(int index=0);
};

#endif