#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int _data)
    {
        data = _data;
        next = nullptr;
    }

    Node(int _data, Node *_next)
    {
        data = _data;
        next = _next;
    }
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void insert_at_head(int data)
    {
        Node *newNode = new Node(data);

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }

    void insert_at_tail(int data)
    {
        Node *newNode = new Node(data);

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void insert_after(int data, int after)
    {
        Node *temp = head;
        while (temp != nullptr && temp->data != after)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
            return; // not found

        Node *newNode = new Node(data, temp->next);
        temp->next = newNode;
    }

    void pop_front()
    {
        if (head == nullptr)
            return;

        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void pop_back()
    {
        if (head == nullptr)
            return;

        if (head->next == nullptr) // only one node
        {
            delete head;
            head = nullptr;
            return;
        }

        Node *temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = nullptr;
        delete temp->next;
    }

    Node *find(int value)
    {
        Node *temp = head;

        while (temp != nullptr)
        {
            if (temp->data == value)
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    int size()
    {
        int _size = 0;
        Node *temp = head;
        while (temp != nullptr)
        {
            _size++;
            temp = temp->next;
        }

        return _size;
    }
};
