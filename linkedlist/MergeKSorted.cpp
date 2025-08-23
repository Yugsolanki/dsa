#include "utilities.h"
#include <queue>
#include <utility>

Node *mergeTwoList(Node *list1, Node *list2)
{
    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;

    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->data < list2->data)
        {
            temp->next = list1;
            temp = list1;
            list1 = list1->next;
        }
        else
        {
            temp->next = list2;
            temp = list2;
            list2 = list2->next;
        }
    }

    if (list1 != nullptr)
        temp->next = list1;
    else
        temp->next = list2;

    return dummyNode->next;
}

// Time Complexity = O(n + m)
// Space Complexity = O(1)

Node *mergeKLists(vector<Node *> &lists)
{
    if (lists.size() == 0)
        return nullptr;

    Node *head = lists[0];

    for (int i = 1; i < lists.size(); i++)
    {
        head = mergeTwoList(head, lists[i]);
    }

    return head;
}

// Time Complexity = O(kn)
// Space Complexity = O(1)

Node *mergeKListsOptimized(vector<Node *> &lists)
{
    // priority_queue<T, Container, Comparator>
    // T = element type
    // Container = underlying storage(usually vector<T>)
    // Comparator = way to compare two Ts
    priority_queue<pair<int, Node *>, vector<pair<int, Node *>>, greater<pair<int, Node *>>> pq;

    // Pushing all heads into the pq
    for (int i = 0; i < lists.size(); i++)
    {
        pq.push({lists[i]->data, lists[i]});
    }

    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;

    while (!pq.empty())
    {
        auto p = pq.top();
        temp->next = p.second;
        pq.pop();
        if (p.second->next)
            pq.push({p.second->next->data, p.second->next});
        temp = temp->next;
    }

    return dummyNode->next;
}

// Time Complexity = O(N log k)
// Space Complexity = O(k)

int main()
{
    vector<int> arr1 = {2, 4, 6};
    vector<int> arr2 = {1, 5};
    vector<int> arr3 = {1, 1, 3, 7};
    vector<int> arr4 = {8};

    Node *head1 = arrayToLinkedList(arr1);
    Node *head2 = arrayToLinkedList(arr2);
    Node *head3 = arrayToLinkedList(arr3);
    Node *head4 = arrayToLinkedList(arr4);

    vector<Node *> lists = {head1, head2, head3, head4};

    Node *result = mergeKListsOptimized(lists);

    printLinkedList(result);

    return 0;
}