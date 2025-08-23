#include "utilities.h"

DNode *deleteAllKey(DNode *head, int key)
{
    DNode *temp = head;

    while (temp != nullptr)
    {
        if (temp->data == key)
        {
            if (temp == head)
                head = head->next;

            DNode *nextNode = temp->next;
            DNode *prevNode = temp->prev;

            if (nextNode)
                nextNode->prev = prevNode;
            if (prevNode)
                prevNode->next = nextNode;

            delete temp;
            temp = nextNode;
        }
        else
        {
            temp = temp->next;
        }
    }
}