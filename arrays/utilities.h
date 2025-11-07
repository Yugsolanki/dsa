#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int _data) : data(_data), next(nullptr) {}
};

struct DNode
{
    int data;
    DNode *next;
    DNode *prev;

    DNode(int _data)
    {
        data = _data;
        next = nullptr;
        prev = nullptr;
    }

    DNode(int _data, DNode *_next, DNode *_prev)
    {
        data = _data;
        next = _next;
        prev = _prev;
    }
};

// Function declaration
Node *arrayToLinkedList(vector<int> &arr);
void printLinkedList(Node *head);
Node *reverseLL(Node *head);
DNode *arrayToDoublyLinkedList(vector<int> &arr);
void print2DVector(const vector<vector<int>> &vec);
void printDoublyLinkedList(DNode *head);
Node *mergeLL(Node *head1, Node *head2);

#endif