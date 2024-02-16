#include <iostream>
#include <stdexcept>

template <typename T>
class Node
{
public:
    T data;
    Node* next = nullptr;

    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList
{
private:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}

    void append(T data)
    {
        if (head == nullptr)
        {
            head = new Node<T>(data);
            return;
        }
        Node<T>* last_node = head;
        while (last_node->next != nullptr)
        {
            last_node = last_node->next;
        }
        last_node->next = new Node<T>(data);
    }

    void pre_append(T data)
    {
        Node<T>* new_node =  new Node<T>(data);
        new_node->next = head;
        head = new_node;
    }

    void insert(T data, int index)
    {
        Node<T>* new_node = new Node<T>(data);
        Node<T>* current_node = head;
        int current_index = 0;
        try{
        if (current_index < 0)
        {
            throw "Insert method doesn't support negative index.";
        }
        while (current_index < index)
        {
            if (current_node == nullptr or current_node->next == nullptr)
            {
                throw "Index out of range";
            }
            current_node = current_node->next;
            current_index++;
        }
        if (current_node == nullptr or current_node->next == nullptr)
        {
            throw "Index out of range";
        }
        Node<T>* next_node = current_node->next;
        current_node->next = new_node;
        new_node->next = next_node;
        }catch (const char* e){
            std::cout << "Error: " << e << "\n";
            std::cout << "Insertion failed" << "\n";
        }
    }
 
    void print()
    {
        if (head == nullptr)
        {
            std::cout << "NULL";
            return;
        }
        Node<T>* current_node = head;
        while (current_node != nullptr && current_node->next != nullptr)
        {
            std::cout << current_node->data << " -> ";
            current_node = current_node->next;
        }
        std::cout << current_node->data << " -> " << "NULL";
        return;
    }

    int lenght()
    {
        int lenght = 1;
        Node<T>* current_node = head;
        while (current_node != nullptr && current_node->next != nullptr)
        {
            current_node = current_node->next;
            lenght++;
        }
        return lenght;
    }
};


int main()
{
    LinkedList<int> list;
    list.append(17);
    list.append(31);
    list.append(40);
    list.append(23);
    list.pre_append(55);
    list.insert(56, 5);

    list.print();

    return 0;
}