#include <iostream>
#include <vector>
using namespace std;

#define MAX_SIZE 10

class StackArray
{
private:
    int stack[MAX_SIZE];
    int top_index;

public:
    StackArray()
    {
        top_index = -1; // indicates empty stack
    }

    void push(int val)
    {
        if (top_index > MAX_SIZE - 1)
        {
            cout << "Stack limit reached" << endl;
            return;
        }
        stack[++top_index] = val;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty nothing to pop" << endl;
            return;
        }
        top_index--;
    }

    bool isEmpty()
    {
        if (top_index == -1)
            return true;
        else
            return false;
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty nothing at top" << endl;
            return -1;
        }
        return stack[top_index];
    }

    int size()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }

        return top_index + 1;
    }
};

int main()
{
    StackArray s;
    s.pop();
    s.push(1);
    s.push(2);
    cout << s.size() << endl;
    cout << s.top() << endl;
    return 0;
}