#include "utilities.h"

Node *Sort012(Node *head)
{
    Node *zeroHead = nullptr, *oneHead = nullptr, *twoHead = nullptr;
    Node *zero = nullptr, *one = nullptr, *two = nullptr;
    Node *temp = head;

    while (temp != nullptr)
    {
        if (zeroHead == nullptr && temp->data == 0)
        {
            zeroHead = temp;
            zero = temp;
            temp = temp->next;
            continue;
        }
        if (oneHead == nullptr && temp->data == 1)
        {
            oneHead = temp;
            one = temp;
            temp = temp->next;
            continue;
        }
        if (twoHead == nullptr && temp->data == 2)
        {
            twoHead = temp;
            two = temp;
            temp = temp->next;
            continue;
        }

        if (temp->data == 0)
        {
            zero->next = temp;
            zero = zero->next;
        }
        else if (temp->data == 1)
        {
            one->next = temp;
            one = one->next;
        }
        else if (temp->data == 2)
        {
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }

    zero->next = oneHead;
    one->next = twoHead;
    two->next = nullptr;
    return zeroHead;
}

int main()
{
    vector<int> arr = {1, 0, 1, 2, 0, 2, 1};
    Node *head = arrayToLinkedList(arr);
    Node *sorted = Sort012(head);
    printLinkedList(sorted);
    return 0;
}