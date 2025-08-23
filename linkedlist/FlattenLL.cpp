#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *child;

    Node(int _data)
    {
        data = _data;
        next = nullptr;
        child = nullptr;
    }
};

Node *mergeTwoList(Node *list1, Node *list2)
{
    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;

    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->data < list2->data)
        {
            temp->child = list1;
            temp = list1;
            list1 = list1->child;
        }
        else
        {
            temp->child = list2;
            temp = list2;
            list2 = list2->child;
        }

        temp->next = nullptr;
    }

    if (list1 != nullptr)
        temp->child = list1;
    else
        temp->child = list2;

    return dummyNode->child;
}

Node *flatten(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *list2 = flatten(head->next);

    Node *res = mergeTwoList(head, list2);

    return res;
}