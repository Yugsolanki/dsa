#include "utilities.h"

DNode *removeDuplicates(DNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    DNode *temp = head;

    while (temp != nullptr && temp->next != nullptr)
    {
        DNode *next = temp->next;
        while (next != nullptr && next->data == temp->data)
        {
            DNode *duplicate = next;
            next = next->next;
            delete duplicate; // ✅ safely delete
        }
        temp->next = next;
        if (next)
            next->prev = temp;
        temp = temp->next;
    }

    return head;
}

int main()
{
    vector<int> arr = {1, 1, 1, 2, 3, 3, 4};
    // vector<int> arr = {1, 1, 1};
    DNode *head = arrayToDoublyLinkedList(arr);
    DNode *res = removeDuplicates(head);
    printDoublyLinkedList(res);
    return 0;
}