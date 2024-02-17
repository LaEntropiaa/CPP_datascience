#include <iostream>
#include <stdexcept>

template <typename T>
class LinkedList;

template <typename T>
class Node
{
private:
    T data;
    Node* next = nullptr;

    friend class LinkedList<T>;
public:
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
            throw std::runtime_error("LinkedList Insert method doesn't support negative index.");
        }
        while (current_index < index)
        {
            if (current_node == nullptr or current_node->next == nullptr)
            {
                throw std::runtime_error("Index out of range");
            }
            current_node = current_node->next;
            current_index++;
        }
        Node<T>* next_node = current_node->next;
        current_node->next = new_node;
        new_node->next = next_node;
        }catch (const std::runtime_error& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            std::cerr << "File: " << __FILE__ << std::endl;
            std::cerr << "Line: " << __LINE__ << std::endl;
            std::exit(EXIT_FAILURE);
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
        std::cout << current_node->data << " -> " << "NULL" << std::endl;
        return;
    }

    T get(int index)
    {
        int current_index = 0;
        Node<T>* current_node = head;
        try {
        if (index < 0)
        {
            throw std::runtime_error("LinkedList::get doesn't support negative index");
        }
        while (current_index < index)
        {
            if (current_node == nullptr or current_node->next == nullptr)
            {
                throw std::runtime_error("Index out of range");
            }
            current_node = current_node->next;
            current_index++;
        }
        return current_node->data;
        }catch (const std::runtime_error& e){
            std::cerr << "Error: " << e.what() << std::endl;
            std::cerr << "File: " << __FILE__ << std::endl; 
            std::cerr << "Line: " << __LINE__ << std::endl;   
            std::exit(EXIT_FAILURE);
            
        }


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
    list.insert(56, 4);

    list.print();
    std::cout << list.get(6);

    return 0;
}