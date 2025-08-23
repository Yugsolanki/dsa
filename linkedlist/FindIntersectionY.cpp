#include "utilities.h"

Node *findIntersectionY(Node *head1, Node *head2)
{
    Node *temp1 = head1;
    Node *temp2 = head2;

    while (temp1 != temp2)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;

        if (temp1 == nullptr)
            temp1 = head2;
        if (temp2 == nullptr)
            temp2 = head1;
    }

    return temp1;
}

int main()
{
    // Create two separate lists
    Node *head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);

    Node *head2 = new Node(9);
    head2->next = new Node(8);

    // Create common part (intersection)
    Node *common = new Node(10);
    common->next = new Node(11);
    common->next->next = new Node(12);

    // Attach the intersection to both lists
    head1->next->next->next = common; // 1 → 2 → 3 → 10 → 11 → 12
    head2->next->next = common;       // 9 → 8 → 10 → 11 → 12

    // Find intersection
    Node *intersection = findIntersectionY(head1, head2);

    if (intersection != nullptr)
        cout << "Intersection at node with value: " << intersection->data << endl;
    else
        cout << "No intersection found" << endl;

    return 0;
}