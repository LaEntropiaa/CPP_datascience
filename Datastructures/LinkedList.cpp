#include <iostream>
#include <stdexcept>
#include <vector>

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

    LinkedList(const std::vector<T>& values): head(nullptr)
    {
        for (T i : values)
        {
            append(i);
        }
    }

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
        }catch (const std::runtime_error& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            std::cerr << "File: " << __FILE__ << std::endl;
            std::cerr << "Line: " << __LINE__ << std::endl;
            std::exit(EXIT_FAILURE);
        }
    }

    T pop_head()
    {
        try {
            if (head == nullptr)
            {
                throw std::runtime_error("Empty llist");
            }
        }catch (const std::runtime_error& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            std::cerr << "File: " << __FILE__ << std::endl;
            std::cerr << "Line: " << __LINE__ << std::endl;
            std::exit(EXIT_FAILURE);
        }


        Node<T>* temp_node = head;
        T temp_data = head->data;
        head = head->next;
        delete temp_node;
        return temp_data;
        
    }

    T pop_tail()
    {
        try {
            if (head == nullptr)
            {
                throw std::runtime_error("Empty llist");
            }
        }
        catch (const std::runtime_error& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            std::cerr << "File: " << __FILE__ << std::endl;
            std::cerr << "Line: " << __LINE__ << std::endl;
            std::exit(EXIT_FAILURE);
        }
        if (head->next == nullptr) 
        {
            T temp_data = head->data;
            delete head;
            head = nullptr;
            return temp_data;
        }
        Node<T>* current_node = head;
        while (current_node->next->next != nullptr)
        {
            current_node = current_node->next;
        }
        T temp_data = current_node->next->data;
        delete current_node->next;
        current_node->next = nullptr;
        return temp_data;
    }

    int lenght()
    {
        if (head == nullptr)
        {
            return 0;
        }
        int lenght = 1;
        Node<T>* current_node = head;
        while (current_node != nullptr && current_node->next != nullptr)
        {
            current_node = current_node->next;
            lenght++;
        }
        return lenght;
    }

    int count(T data)
    {
        int times = 0;
        Node<T>* current_node = head;
        while (current_node != nullptr && current_node->next != nullptr)
        {
            if (current_node->data == data)
            {
                times++;
            }
            current_node = current_node->next;
        }
        return times;
    }

    int find(T data)
    {
        Node<T>* current_node = head;
        int current_index = 0;
        while (current_node->data != data)
        {
            if (current_node == nullptr or current_node->next == nullptr)
            {
                return -1;
            }
            current_node = current_node->next;
            current_index++;
        }
        return current_index;
    }
};


int main()
{
    std::vector<int> vect = { 1,2,3,4,5,6,7,8 };
    LinkedList<int> list(vect);
    list.print();
    

    return 0;
}