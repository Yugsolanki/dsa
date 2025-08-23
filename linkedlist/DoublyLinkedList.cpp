#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int _data)
    {
        data = _data;
        next = nullptr;
        prev = nullptr;
    }

    Node(int _data, Node *_next, Node *_prev)
    {
        data = _data;
        next = _next;
        prev = _prev;
    }
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insert_at_head(int value)
    {
        Node *newNode = new Node(value);

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }

    void insert_at_tail(int value)
    {
        Node *newNode = new Node(value);

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void insert_after(Node *node, int value)
    {
        if (node == nullptr)
            return;

        Node *newNode = new Node(value, node->next, node);

        if (node->next != nullptr)
            node->next->prev = newNode;
        else
            tail = newNode; // inserting after tail

        node->next = newNode;
    }

    void insert_before(Node *node, int value)
    {
        if (node == nullptr)
            return;

        Node *newNode = new Node(value, node, node->prev);

        if (node->prev != nullptr)
            node->prev->next = newNode;
        else
            head = newNode; // inserting before head

        node->prev = newNode;
    }

    void remove_from_head()
    {
        if (head == nullptr)
            return;

        Node *temp = head;
        head = head->next;

        if (head != nullptr)
            head->prev = nullptr;
        else
            tail = nullptr; // list became empty

        delete temp;
    }

    void remove_from_tail()
    {
        if (head == nullptr)
            return;

        Node *temp = tail;
        tail = tail->prev;

        if (tail != nullptr)
            tail->next = nullptr;
        else
            head = nullptr; // list became empty

        delete temp;
    }

    void remove(Node *node)
    {
        if (head == nullptr)
            return;

        if (node == nullptr)
            return;

        if (node->prev != nullptr)
            node->prev->next = node->next;
        else
            head = node->next; // removing head

        if (node->next != nullptr)
            node->next->prev = node->prev;
        else
            tail = node->prev; // removing tail

        delete node;
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

    void reverse()
    {
        Node *current = head;
        Node *prev = nullptr;

        tail = head;

        while (current != nullptr)
        {
            prev = current->prev;
            current->prev = current->next;
            current->next = prev;
            current = current->prev;
        }

        if (prev != nullptr)   // list was not empty
            head = prev->prev; // new head
    }
};