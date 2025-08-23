#include "utilities.h"

Node *rotate(Node *head, int k)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    int length = 1; // since already starting from head
    Node *tail = head;
    while (tail->next != nullptr)
    {
        length++;
        tail = tail->next;
    }

    if (k % length == 0)
        return head;

    k = k % length;

    tail->next = head;

    Node *newLastNode = head;
    for (int i = 0; i < (length - k - 1); i++)
    {
        newLastNode = newLastNode->next;
    }

    // set new head
    head = newLastNode->next;
    // disconnect the loop
    newLastNode->next = nullptr;

    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node *head = arrayToLinkedList(arr);
    Node *res = rotate(head, 3);
    printLinkedList(res);
    return 0;
}