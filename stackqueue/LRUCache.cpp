#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Node
{
public:
    int key;
    int data;
    Node *prev = nullptr;
    Node *next = nullptr;

    Node(int key, int data)
    {
        this->key = key;
        this->data = data;
    }
};

class LRUCache
{
private:
    Node *head;
    Node *tail;
    int capacity = 0;
    int count = 0;
    map<int, Node *> lru;

public:
    LRUCache(int capacity)
    {
        // Allocate memory for the sentinel nodes
        head = new Node(0, 0);
        tail = new Node(0, 0);

        // Correctly link the head and tail
        head->next = tail;
        tail->prev = head;

        this->capacity = capacity;
    }

    void put(int key, int val)
    {
        // if key exists then we update the value and bring it forward
        if (lru.find(key) != lru.end())
        {
            Node *toUpdate = lru[key];
            toUpdate->data = val;

            // unlink node from its current position
            toUpdate->prev->next = toUpdate->next;
            toUpdate->next->prev = toUpdate->prev;

            // insert node right after head
            Node *headNext = head->next;
            toUpdate->next = headNext;
            toUpdate->prev = head;
            head->next = toUpdate;
            headNext->prev = toUpdate;
            return;
        }

        if (count == capacity)
        {
            // remove last element
            Node *lastElement = tail->prev;
            lru.erase(lastElement->key);

            tail->prev = lastElement->prev;
            lastElement->prev->next = tail;

            delete lastElement;
            count--;
        }

        // insert new node at front
        Node *temp = new Node(key, val);
        Node *headNext = head->next;

        temp->next = headNext;
        temp->prev = head;
        head->next = temp;
        headNext->prev = temp;

        lru[key] = temp;
        count++;
    }

    int get(int key)
    {
        if (lru.find(key) == lru.end())
            return -1;

        Node *temp = lru[key];

        // unlink current connection before moving
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        // add new connection to fron
        Node *headNext = head->next;
        temp->next = headNext;
        temp->prev = head;
        head->next = temp;
        headNext->prev = temp;

        return temp->data;
    }
};

int main()
{
    LRUCache lru(2);
    lru.put(1, 2);
    cout << lru.get(1) << endl; // 2
    lru.put(3, 4);
    lru.put(5, 6);              // evicts key 1
    cout << lru.get(1) << endl; // -1
    cout << lru.get(3) << endl; // 4
    cout << lru.get(5) << endl; // 6
    return 0;
}