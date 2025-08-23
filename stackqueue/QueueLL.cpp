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

class QueueLL
{
private:
    Node *start = nullptr;
    Node *end = nullptr;
    int size = 0;

public:
    void enqueue(int val)
    {
        Node *newNode = new Node(val);

        if (start == nullptr && end == nullptr)
        {
            start = end = newNode;
            return;
        }

        end->next = newNode;
        end = newNode;
        size++;
    }

    void dequeue()
    {
        if (start == nullptr && end == nullptr)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        Node *temp = start;
        start = start->next;

        if (start->next == nullptr)
            end == nullptr;

        delete temp;
        size--;
    }

    int top()
    {
        return start->data;
    }

    int length()
    {
        return size;
    }

    void display()
    {
        Node *temp = start;
        while (temp->next != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << temp->data << endl;
    }
};

int main()
{
    QueueLL qll;
    qll.enqueue(1);
    qll.enqueue(2);
    qll.enqueue(3);
    qll.enqueue(4);
    qll.display();
    qll.dequeue();
    qll.dequeue();
    qll.display();
    return 0;
}