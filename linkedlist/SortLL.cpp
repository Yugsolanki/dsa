#include "utilities.h"

Node *findMiddle(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node *sort(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *middle = findMiddle(head);
    Node *leftHead = head;
    Node *rightHead = middle->next;
    middle->next = nullptr; // disconnect so `merge` and `findMiddle` can won't go beyond as they check for nullptr

    // after here it returns the sorted head
    leftHead = sort(leftHead);
    rightHead = sort(rightHead);

    return mergeLL(leftHead, rightHead);
}

// Time Complexity : O(n log n)
// Space Complexity : O(log n)

int main()
{
    // vector<int> arr = {3, 5, 2, 1, 5, 7, 3, 6, 8, 5};
    vector<int> arr = {0};
    Node *head = arrayToLinkedList(arr);
    Node *res = sort(head);
    printLinkedList(res);
    return 0;
}