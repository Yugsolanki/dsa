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
};

Node *oddEven(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *odd = head;
    Node *even = head->next;
    Node *evenHead = head->next;

    while (even != nullptr && even->next != nullptr)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }

    odd->next = evenHead;
    return head;
}