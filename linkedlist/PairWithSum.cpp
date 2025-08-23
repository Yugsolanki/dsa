#include "utilities.h"
#include <utility>

DNode *findTail(DNode *head)
{
    DNode *tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    return tail;
}

vector<vector<int>> pairWithSum(DNode *head, int sum)
{
    vector<vector<int>> ans;
    if (head == nullptr)
        return ans;

    DNode *left = head;
    DNode *right = findTail(head);

    while (left != right && left->data < right->data)
    {
        if (left->data + right->data == sum)
        {
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
        else if (left->data * right->data < sum)
        {
            left = left->next;
        }
        else
        {
            right = right->prev;
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 14};
    DNode *head = arrayToDoublyLinkedList(arr);
    vector<vector<int>> result = pairWithSum(head, 10);
    print2DVector(result);
    return 0;
}