#include "Heap.h"

template <class T>
void MinHeap<T>::sift_down(int index)
{
    if (index > this->heap.size()-1)
    {
        return;
    }
    int child1 = index * 2 + 1;
    int child2 = index * 2 + 2;
    if (child1 > this->heap.size() - 1)
    {
        return;
    }
    if (child2 > this->heap.size() - 1)
    {
        child2 = child1;
    }
    while (this->heap[child1] < this->heap[index] or this->heap[child2] < this->heap[index])
    {
        if (this->heap[child1] < this->heap[index] and this->heap[child1] < this->heap[child2])
        {
            std::swap(this->heap[child1], this->heap[index]);
            index = child1;
        }
        else
        {
            std::swap(this->heap[child2], this->heap[index]);
            index = child2;
        }
        child1 = index * 2 + 1;
        child2 = index * 2 + 2;
        if (child1 > this->heap.size() - 1)
        {
            return;
        }
        if (child2 > this->heap.size() - 1)
        {
            child2 = child1;
        }
    }
}

template <class T>
void MinHeap<T>::sift_up(int index)
{
    int parent = round((index - 1) / 2);
    return;
}