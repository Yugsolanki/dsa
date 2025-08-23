#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data = 0;
    Node *next = nullptr;

    Node(int value)
    {
        this->data = value;
    }
};

class LinkedList
{
private:
    Node *head = nullptr;

public:
    LinkedList(int value)
    {
        head = new Node(value);
    }

    void insert(int value)
    {
        Node *newNode = new Node(value);
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

    void remove(int val)
    {
        if (head == nullptr)
            return;

        // if head is the node to remove
        if (head->data == val)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node *temp = head; // it will always point to the one node previous to the val containing node

        // iterate until you reach the node before the value node
        while (temp->next->data != val && temp->next != nullptr)
        {
            temp = temp->next;
        }

        if (temp->next != nullptr)
        {

            Node *nodeToRemove = temp->next;
            temp->next = nodeToRemove->next;
            delete nodeToRemove;
        }
    }

    bool search(int val)
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            if (temp->data == val)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void display()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    LinkedList list(0);
    list.insert(10);
    list.insert(20);
    list.insert(5);
    list.insert(30);
    list.display();

    list.remove(20);
    list.display();
    return 0;
}