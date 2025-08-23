#include "utilities.h"

Node *addOne(Node *head)
{
    Node *reversed = reverseLL(head);
    Node *temp = reversed;
    int carry = 1;

    while (temp != nullptr)
    {
        int res = temp->data + carry;

        if (res < 10)
        {
            temp->data = res;
            carry = 0;
            break;
        }
        else
        {
            temp->data = 0;
            carry = 1;
        }
        temp = temp->next;
    }

    reversed = reverseLL(reversed);

    if (carry == 1)
    {
        Node *newNode = new Node(carry);
        newNode->next = reversed;
        reversed = newNode;
    }

    return reversed;
}

// Time Complexity = O(3N)
// Space Complexity = O(1)

int addOneHelper(Node *head)
{
    if (head == nullptr)
        return 1;

    int carry = addOneHelper(head->next);

    int sum = head->data + carry;
    head->data = sum % 10;
    return sum / 10; // returns 0 or 1. 10/10 == 1 and 9/10 == 0
}

Node *addOneRecursive(Node *head)
{
    int carry = addOneHelper(head);
    if (carry == 1)
    {
        Node *newNode = new Node(carry);
        newNode->next = head;
        head = newNode;
    }

    return head;
}

// Time Complexity: O(n)
// Space Complexity: O(n) (due to recursion stack)

int main()
{
    vector<int> arr = {1, 5, 9};
    // vector<int> arr = {9, 9, 9, 9};
    // vector<int> arr = {0};
    Node *head = arrayToLinkedList(arr);
    Node *res = addOneRecursive(head);
    printLinkedList(res);
    return 0;
}