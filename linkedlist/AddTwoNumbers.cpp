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

Node *addTwoNumbers(Node *num1, Node *num2)
{
    Node *dummyNode = new Node(-1);
    Node *temp1 = num1;
    Node *temp2 = num2;
    Node *currn = dummyNode;
    int carry = 0;

    while (temp1 != nullptr || temp2 != nullptr)
    {
        int a = temp1 != nullptr ? temp1->data : 0;
        int b = temp2 != nullptr ? temp2->data : 0;

        int sum = a + b + carry; // 10 + 10 + 3 = 23
        carry = sum / 10;        // 23 / 10 = 2
        int digit = sum % 10;    // 23 % 10 = 3

        currn->next = new Node(digit);
        currn = currn->next;

        if (temp1)
            temp1 = temp1->next;
        if (temp2)
            temp2 = temp2->next;
    }

    return dummyNode->next;
}