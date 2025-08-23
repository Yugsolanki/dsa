#include "utilities.h"

Node *middle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = arrayToLinkedList(arr);
    cout << middle(head)->data << endl;
    return 0;
}