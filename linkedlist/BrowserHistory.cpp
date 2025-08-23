#include "utilities.h"
#include <string>

struct Node
{
    string data;
    Node *next;
    Node *prev;

    Node(string _data)
    {
        data = _data;
        next = nullptr;
        prev = nullptr;
    }

    Node(string _data, Node *_next, Node *_prev)
    {
        data = _data;
        next = _next;
        prev = _prev;
    }
};

class BrowserHistory
{
private:
    Node *head;

public:
    BrowserHistory(string homepage)
    {
        Node *newNode = new Node(homepage);
        head = newNode;
    }

    void visit(string url)
    {
        Node *newNode = new Node(url);
        newNode->prev = head;
        head->next = newNode;
        head = newNode;
    }

    string back(int steps)
    {
        for (int i = 0; i < steps; i++)
        {
            if (head->prev == nullptr)
                return head->data;
            head = head->prev;
        }

        return head->data;
    }

    string forward(int steps)
    {
        for (int i = 0; i < steps; i++)
        {
            if (head->next == nullptr)
                return head->data;
            head = head->next;
        }

        return head->data;
    }
};