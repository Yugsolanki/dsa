#include "utilities.h"

Node *removeMiddle(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr; // empty or single node → nothing left

    Node *slow = head;
    Node *fast = head->next->next;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *temp = slow->next;
    slow->next = slow->next->next;
    delete temp;

    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node *head = arrayToLinkedList(arr);
    Node *res = removeMiddle(head);
    printLinkedList(res);
    return 0;
}