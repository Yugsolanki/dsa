#include "utilities.h"

Node *reverseLL(Node *head)
{
    Node *prev = nullptr;
    Node *front = nullptr;
    Node *temp = head;

    while (temp != nullptr)
    {
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    return prev;
}

// Time complexity = O(n)
// Space complexity = O(1)

Node *reverseRecursive(Node *head)
{
    // https://youtu.be/MRe3UsRadKw?si=QOra3VOyiuqWQmbJ

    if (head == nullptr || head->next == nullptr)
        return head;

    Node *newHead = reverseRecursive(head->next);

    head->next->next = head;
    head->next = nullptr;

    return newHead;
}

int main()
{
    vector<int> arr = {5, 4, 3, 2, 1};
    Node *head = arrayToLinkedList(arr);
    Node *res = reverseRecursive(head);
    printLinkedList(res);
    return 0;
}