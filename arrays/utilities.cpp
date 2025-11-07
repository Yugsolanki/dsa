#include "utilities.h"

void printLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data;
        if (temp->next != nullptr)
            cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

void printDoublyLinkedList(DNode *head)
{
    DNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data;
        if (temp->next != nullptr)
            cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

Node *arrayToLinkedList(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return nullptr; // empty array

    Node *head = new Node(arr[0]);
    Node *current = head;

    for (int i = 1; i < n; i++)
    {
        current->next = new Node(arr[i]);
        current = current->next;
    }

    return head;
}

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

DNode *arrayToDoublyLinkedList(vector<int> &arr)
{
    // If the array is empty, return nullptr
    if (arr.empty())
    {
        return nullptr;
    }

    // Create the head of the doubly linked list
    DNode *head = new DNode(arr[0]);
    DNode *current = head;

    // Iterate through the rest of the array starting from the second element
    for (size_t i = 1; i < arr.size(); ++i)
    {
        // Create a new node for the current array element
        DNode *newNode = new DNode(arr[i]);

        // Link the new node to the previous node
        current->next = newNode;
        newNode->prev = current;

        // Move to the new node
        current = newNode;
    }

    return head;
}

void print2DVector(const vector<vector<int>> &vec)
{
    cout << "Printing 2D Vector:" << endl;
    if (vec.empty())
    {
        cout << "  (Vector is empty)" << endl;
        return;
    }

    // Iterate through each inner vector (row)
    for (size_t i = 0; i < vec.size(); ++i)
    {
        cout << "  Row " << i << ": [";
        // Iterate through each element in the current inner vector
        for (size_t j = 0; j < vec[i].size(); ++j)
        {
            cout << vec[i][j];
            // Add a comma and space if it's not the last element in the row
            if (j < vec[i].size() - 1)
            {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
}

Node *mergeLL(Node *head1, Node *head2)
{
    Node *t1 = head1;
    Node *t2 = head2;
    Node *newHead = new Node(-1);
    Node *temp = newHead;

    while (t1 != nullptr && t2 != nullptr)
    {
        if (t1->data < t2->data)
        {
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        }
        else
        {
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    }

    // since arr1 has only 2 elements and arr2 has 6
    // we go uptil arr1 is null and then
    // point temp to the rest of the larger array
    // so temp will point to arr2
    if (t1)
        temp->next = t1;
    else
        temp->next = t2;

    return newHead->next;
}