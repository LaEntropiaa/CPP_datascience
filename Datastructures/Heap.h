#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <math.h>


template <class T>
class MinHeap
{
private:
    std::vector<T> heap;
    void sift_down(int index=0);
    void sift_up(int index = this->heap.size() - 1);
public:
    MinHeap();
    void append(T data);
    T get(int index);
    int size();
};

template <class T>
std::ostream& operator << (std::ostream& out, MinHeap<T> heap);
#endif