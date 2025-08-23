#include "utilities.h"

void reverse(Node *head)
{
    Node *temp = head;
    Node *prev = nullptr;
    Node *front = nullptr;

    while (temp != nullptr)
    {
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
}

Node *findKthNode(Node *node, int k)
{
    Node *temp = node;
    for (int i = 0; i < k - 1; i++)
    {
        if (temp == nullptr)
            return nullptr;
        temp = temp->next;
    }
    return temp;
}

Node *reverseKGroup(Node *head, int k)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *temp = head;
    Node *prev = nullptr;

    while (temp != nullptr)
    {
        Node *kthNode = findKthNode(temp, k);

        if (kthNode == nullptr)
        {
            if (prev)
                prev->next = temp;
            break;
        }

        Node *nextNode = kthNode->next; // preserving next node to kthnode

        kthNode->next = nullptr;
        reverse(temp);

        if (temp == head)
            head = kthNode;
        else
            prev->next = kthNode;

        prev = temp;
        temp = nextNode;
    }

    return head;
}

int main()
{
    // vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> arr = {1, 2, 3};
    Node *head = arrayToLinkedList(arr);
    Node *res = reverseKGroup(head, 3);
    printLinkedList(res);
    return 0;
}