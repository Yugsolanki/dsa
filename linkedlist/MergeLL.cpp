#include "utilities.h"

Node *merge(Node *head1, Node *head2)
{
    Node *t1 = head1;
    Node *t2 = head2;
    Node *newHead = new Node(-1);
    Node *temp = newHead;

    while (t1 != nullptr && t2 != nullptr)
    {
        if (t1->data < t2->data)
        {
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        }
        else
        {
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    }

    // since arr1 has only 2 elements and arr2 has 6
    // we go uptil arr1 is null and then
    // point temp to the rest of the larger array
    // so temp will point to arr2
    if (t1)
        temp->next = t1;
    else
        temp->next = t2;

    return newHead->next;
}

int main()
{
    vector<int> arr1 = {2, 4};
    vector<int> arr2 = {1, 3, 3, 6, 11, 14};
    Node *head1 = arrayToLinkedList(arr1);
    Node *head2 = arrayToLinkedList(arr2);
    Node *res = merge(head1, head2);
    printLinkedList(res);
    return 0;
}