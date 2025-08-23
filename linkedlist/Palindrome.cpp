#include "utilities.h"

bool palindrome(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    // finding the middle
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *oldHead = head;
    Node *newHead = reverseLL(slow->next);
    Node *newHeadTemp = newHead; // used for iteration to avoid modifying newHead

    bool isPalindrome = true;

    while (newHeadTemp->next != nullptr)
    {
        if (oldHead->data != newHeadTemp->data)
        {
            isPalindrome = false;
        }
        oldHead = oldHead->next;
        newHeadTemp = newHeadTemp->next;
    }

    Node *temp = reverseLL(newHead);
    return palindrome;
}

int main()
{
    vector<int> arr1 = {1, 2, 3, 2, 1};
    Node *head1 = arrayToLinkedList(arr1);
    cout << palindrome(head1) << endl;
    printLinkedList(head1);

    cout << "----------------------------------------------------------" << endl;

    vector<int> arr2 = {1, 2, 3, 3, 2, 1};
    Node *head2 = arrayToLinkedList(arr2);
    cout << palindrome(head2) << endl;
    printLinkedList(head2);

    cout << "----------------------------------------------------------" << endl;

    vector<int> arr3 = {1, 2, 3, 3, 2};
    Node *head3 = arrayToLinkedList(arr3);
    cout << palindrome(head3) << endl;
    printLinkedList(head3);

    return 0;
}