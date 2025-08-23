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

class StackLL
{
private:
    Node *top = nullptr;

public:
    StackLL()
    {
        top = nullptr;
    }

    void push(int val)
    {
        Node *newNode = new Node(val);
        if (top == nullptr)
        {
            top = newNode;
            return;
        }

        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        if (top == nullptr)
        {
            cout << "Nothing to pop" << endl;
            return;
        }

        Node *temp = top;
        top = top->next;
        delete temp;
    }

    int topElement()
    {
        return top->data;
    }

    void display()
    {
        Node *temp = top;
        while (temp->next != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << temp->data << " ";
        cout << endl;
    }
};

int main()
{
    StackLL s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.display();
    s.pop();
    s.pop();
    s.display();
    return 0;
}