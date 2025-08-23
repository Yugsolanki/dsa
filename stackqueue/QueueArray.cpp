#include <iostream>
#include <vector>
using namespace std;

#define MAX_SIZE 10

class QueueArray
{
private:
    int queue[MAX_SIZE];
    int front, rear, count;

public:
    QueueArray()
    {
        front = 0;
        rear = -1;
        count = 0;
    }

    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "Queue overflow!" << endl;
            return;
        }
        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = val;
        count++;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        front = (front + 1) % MAX_SIZE;
        count--;
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return queue[front];
    }

    bool isFull()
    {
        return count == MAX_SIZE;
    }

    bool isEmpty()
    {
        return count == 0;
    }

    void display()
    {
        int i = front;
        int elementsPrinted = 0;
        while (elementsPrinted < count)
        {
            cout << queue[i] << " ";
            i = (i + 1) % MAX_SIZE;
            elementsPrinted++;
        }
        cout << endl;
    }
};

int main()
{
    QueueArray q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    cout << q.top() << endl;
    q.dequeue();
    q.display();
    return 0;
}