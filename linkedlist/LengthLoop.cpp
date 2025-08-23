#include "utilities.h"

int findLength(Node *slow, Node *fast)
{
    int size = 1;
    while (slow != fast)
    {
        size++;
        fast = fast->next;
    }
    return size;
}

int lengthOfLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return findLength(slow, fast);
        }
    }

    return 0;
}