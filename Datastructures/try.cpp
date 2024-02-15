#include <iostream>

class Node
{
public:
    int data;
    Node* next = nullptr;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList
{
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void append(int data)
    {
        if (head == nullptr)
        {
            head = new Node(data);
            return;
        }
        Node* last_node = head;
        while (last_node->next != nullptr)
        {
            last_node = last_node->next;
        }
        last_node->next = new Node(data);
    }

    void print()
    {

    }
};