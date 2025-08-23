#include "utilities.h"
#include <unordered_map>

struct Node
{
    int data;
    Node *next;
    Node *random;

    Node(int _data) : data(_data), next(nullptr), random(nullptr) {}
};

Node *cloneRandom(Node *head)
{
    unordered_map<Node *, Node *> mp;

    Node *temp = head;

    while (temp != nullptr)
    {
        Node *newNode = new Node(temp->data);
        mp[temp] = newNode;
        temp = temp->next;
    }

    temp = head;

    while (temp != nullptr)
    {
        mp[temp]->next = mp[temp->next];
        mp[temp]->random = mp[temp->random];
        temp = temp->next;
    }

    return mp[head];
}

// Time Complexity : O(n)
// Space Complexity : O(n)

Node *cloneRandom(Node *head)
{
    if (head == nullptr)
        return nullptr;

    Node *temp = head;

    // Step 1: Insert cloned nodes
    while (temp != nullptr)
    {
        Node *newNode = new Node(temp->data);
        newNode->next = temp->next;
        temp->next = newNode;
        temp = newNode->next;
    }

    // Step 2: Set random pointers
    temp = head;
    while (temp != nullptr)
    {
        if (temp->random != nullptr)
            temp->next->random = temp->random->next;
        temp = temp->next->next;
    }

    // Step 3: Separate original and cloned lists
    Node *dummyNode = head->next;
    Node *copy = dummyNode;
    temp = head;

    while (temp != nullptr)
    {
        temp->next = temp->next->next;

        if (copy->next != nullptr)
            copy->next = copy->next->next;

        temp = temp->next;
        copy = copy->next;
    }

    return dummyNode;
}

// Time Complexity: O(n)
// Space Complexity: O(1)