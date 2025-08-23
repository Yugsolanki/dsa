#include "utilities.h"

Node *removeNthNode(Node *head, int n)
{
    Node *fast = head;
    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }

    // if n = size of the linkedlist then fast
    // will after n iteration will always point to
    // nullptr, meaning we need to remove the head.
    // ll size = 3, and n = 3 (remove 3rd node from end)
    // basically remove the head
    if (fast == nullptr)
    {
        Node *tempHead = head;
        head = head->next;
        delete tempHead;
        return head;
    }

    Node *slow = head;
    while (fast->next != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }

    Node *temp = slow->next;
    slow->next = slow->next->next;
    delete temp;

    return head;
}

// Time Complexity : O(n + (L - n))
// Space Complexity: O(1)