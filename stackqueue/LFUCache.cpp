#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Node
{
    int key, data, count;
    Node *next, *prev;
    Node(int _key, int _data)
    {
        key = _key;
        data = _data;
        count = 1;
    }
};

class List
{
public:
    int size = 0;
    Node *head;
    Node *tail;

    List()
    {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addToFront(Node *node)
    {
        Node *headNext = head->next;
        node->next = headNext;
        node->prev = head;
        head->next = node;
        headNext->prev = node;
        size++;
    }

    void removeNode(Node *delNode)
    {
        delNode->prev->next = delNode->next;
        delNode->next->prev = delNode->prev;
        size--;
    }
};

class LFUCache
{
private:
    map<int, Node *> keyNode;
    map<int, List *> freqListMap;
    int capacity, minFreq, curSize; // currentSize

public:
    LFUCache(int capacity)
    {
        this->capacity = capacity;
        minFreq = 0;
        curSize = 0;
    }

    void put(int key, int value)
    {
        if (capacity == 0)
            return;

        // if key exists
        if (keyNode.find(key) != keyNode.end())
        {
            Node *node = keyNode[key];
            node->data = value;
            updateFreqList(node);
        }
        else
        {
            if (curSize == capacity)
            {
                List *list = freqListMap[minFreq];                  // extract list
                keyNode.erase(list->tail->prev->key);               // remove the last element
                freqListMap[minFreq]->removeNode(list->tail->prev); // remove from that list also
                curSize--;
            }
            curSize++;

            minFreq = 1;
            List *listFreq = new List();
            if (freqListMap.find(minFreq) != freqListMap.end())
            {
                listFreq = freqListMap[minFreq];
            }
            Node *node = new Node(key, value);
            listFreq->addToFront(node);
            keyNode[key] = node;
            freqListMap[minFreq] = listFreq;
        }
    }

    int get(int key)
    {
        if (keyNode.find(key) != keyNode.end())
        {
            Node *node = keyNode[key];
            int val = node->data;
            updateFreqList(node);
            return val;
        }
        return -1;
    }

    void updateFreqList(Node *node)
    {
        keyNode.erase(node->key);
        freqListMap[node->count]->removeNode(node);

        // 1 : [(1,2)] if this was the case of freqListMap then removing the last element will remove freq too
        // then minFreq will be the key 2
        if (node->count == minFreq && freqListMap[node->count]->size == 0)
        {
            minFreq++;
        }

        List *nextHigherFreqList = new List();

        if (freqListMap.find(node->count + 1) != freqListMap.end())
        {
            // already a list is present at that frequency
            // copy the list and then will add to the existing list and reassign to that freqeuncy
            nextHigherFreqList = freqListMap[node->count + 1];
        }
        node->count++;
        nextHigherFreqList->addToFront(node);
        freqListMap[node->count] = nextHigherFreqList;
        keyNode[node->key] = node;
    }
};

int main()
{
    LFUCache lfu(3);
    lfu.put(1, 10);
    lfu.put(2, 20);
    lfu.put(3, 30);
    lfu.put(4, 40);
    cout << lfu.get(3) << endl;
    cout << lfu.get(2) << endl;
    cout << lfu.get(4) << endl;
    lfu.put(5, 5);
    cout << lfu.get(4) << endl;
    return 0;
}