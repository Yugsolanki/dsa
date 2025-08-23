#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Queue
{
private:
    stack<int> s1;
    stack<int> s2;

public:
    void enqueue(int val)
    {
        while (s1.size())
        {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(val);

        while (s2.size())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    void dequeue()
    {
        if (!s1.empty())
            s1.pop();
    }

    int top()
    {
        if (!s1.empty())
            return s1.top();
        return -1;
    }

    int size()
    {
        return s1.size();
    }
};

class Queue2
{
private:
    stack<int> s1;
    stack<int> s2;

public:
    void enqueue(int val)
    {
        s1.push(val);
    }

    void pop()
    {
        if (s2.size() != 0)
        {
            s2.pop();
        }
        else
        {
            while (s1.size())
            {
                s2.push(s1.top());
                s1.pop();
            }
            if (!s2.empty())
                s2.pop();
        }
    }

    int top()
    {
        if (s2.size() != 0)
        {
            return s2.top();
        }
        else
        {
            while (s1.size())
            {
                s2.push(s1.top());
                s1.pop();
            }
            if (!s2.empty())
                return s2.top();
            return -1;
        }
    }
};