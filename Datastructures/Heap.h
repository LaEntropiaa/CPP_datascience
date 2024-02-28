#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <math.h>
#include <limits>


template <class T>
class MinHeap
{
private:
    std::vector<T> heap;
    void sift_down(int index = 0)
    {
        if (index > this->heap.size() - 1)
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

    void sift_up(int index)
    {
        if (index < 1)
        {
            return;
        }
        size_t parent = (index - 1) / 2;
        if (this->heap[index] < this->heap[parent])
        {
            std::swap(this->heap[index], this->heap[parent]);
            sift_up(parent);
        }
    }
public:
    MinHeap(){}

    void append(T data)
    {
        this->heap.push_back(data);
        this->sift_up(this->heap.size() - 1);
    }

    T get(int index)
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

    size_t size()
    {
        return this->heap.size();
    }

    void push(T data)
    {
        if (this->heap.size() < 1)
        {
            return;
        }
        this->heap[0] = data;
        sift_down();
        return;
    }

    T pop()
    {
        if (this->heap.size() < 1)
        {
            return std::numeric_limits<T>::max();
        }
        else if (this->heap.size() == 1)
        {
            T data = heap[0];
            this->heap.pop_back();
            return data;
        }
        T data = this->heap[0];
        this->heap[0] = this->heap[this->heap.size() - 1];
        this->heap.pop_back();
        sift_down();
        return data;
    }

    void replace(T data, int index)
    {
        if (this->heap.size() < 1)
        {
            return;
        }
        try {
            if (index < this->heap.size() - 1)
            {
                throw std::runtime_error("Index out of range");
            }
        }
        catch (const std::runtime_error& e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
            std::cerr << "File: " << __FILE__ << std::endl;
            std::cerr << "Line: " << __LINE__ << std::endl;
            std::exit(EXIT_FAILURE);
        }
        this->heap[index] = data;
        sift_down(index);
        sift_up(index);
        return;
    }

    void erase(int index)
    {
        if (this->heap.size() < 1)
        {
            return;
        }
        try {
            if (index < this->heap.size() - 1)
            {
                throw std::runtime_error("Index out of range");
            }
        }
        catch (const std::runtime_error& e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
            std::cerr << "File: " << __FILE__ << std::endl;
            std::cerr << "Line: " << __LINE__ << std::endl;
            std::exit(EXIT_FAILURE);
        }
        this->heap[index] = pop();
        sift_down(index);
    }

    T peek()
    {
        if (this->heap.size() < 1)
        {
            return std::numeric_limits<T>::max();
        }
        return this->heap[0];
    }

    std::vector<T> heapsort()
    {
        if (this->heap.size() < 1)
        {
            std::vector<T> list = {};
            return list;
        }
        std::vector<T> list;
        while (this->heap.size() > 0)
        {
            list.push_back(pop());
        }
        return list;
    }
};


template <class T>
std::ostream& operator << (std::ostream& out, MinHeap<T> heap)
{
    if (heap.size() < 1)
    {
        out << "NULL";
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
#endif