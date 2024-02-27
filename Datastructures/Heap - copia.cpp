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
    return;
}

template <class T>
void MinHeap<T>::sift_up(int index)
{
    if (index < 1)
    {
        return;
    }
    int parent = round((index - 1) / 2);
    while (this->heap[index] < this->heap[parent])
    {
        std::swap(this->heap[index], this->heap[parent]);
        index = parent;
        if (index < 1)
        {
            return;
        }
        int parent = round((index - 1) / 2);
    }
    return;
}

template <class T>
void MinHeap<T>::append(T data)
{
    this->heap.push_back(data);
    this->sift_up(this->heap.size() - 1);
}

template <class T>
T MinHeap<T>::get(int index)
{
    try {
        if (index < 0 or index > this->heap.size() - 1)
        {
            throw std::runtime_error("Heap index out of range");
        }
        return this->heap[index];
    }
    catch (const std::runtime_error& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        std::cerr << "File: " << __FILE__ << std::endl;
        std::cerr << "Line: " << __LINE__ << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

template <class T>
int MinHeap<T>::size()
{
    return this->heap.size();
}

template <class T>
MinHeap<T>::MinHeap(){}

template <class T>
std::ostream& operator << (std::ostream& out, MinHeap<T> heap)
{
    if (heap.size() < 1)
    {
        out << "";
        return out;
    }
    out << heap.get(0) << "\n";
    int level = 1;
    int nodes = 0;
    for (int index = 1; index < heap.size(); index++)
    {
        out << heap.get(index) << ", ";
        nodes++;
        if (nodes >= pow(2, level))
        {
            level++;
            nodes = 0;
            out << "\n";
        }
        if (index + 2 >= heap.size())
        {
            out << heap.get(index + 1);
            return out;
        }
    }
}