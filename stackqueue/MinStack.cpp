#include <iostream>
#include <stack>
using namespace std;

class MinStack
{
private:
    stack<int> st;
    int mini = 0;

public:
    void push(int val)
    {
        // if stack is empty
        if (st.empty())
        {
            st.push(val);
            mini = val;
            return;
        }

        // If val replaces current minium value then calculate newValue
        if (val < mini)
        {
            int newVal = 2 * val - mini;
            mini = val;
            st.push(newVal);
        }

        // if val dose not replace current minimum
        else
        {
            st.push(val);
        }
    }

    void pop()
    {
        if (st.empty())
            return;

        if (st.top() < mini) // true if it was a special value
        {
            mini = 2 * mini - st.top(); // getting back the previous minimum
        }
        st.pop();
    }

    int getMin()
    {
        return mini;
    }

    int top()
    {
        if (st.top() < mini) // true if it was a special value
        {
            return mini;
        }
        else
        {
            return st.top();
        }
    }
};

int main()
{
    MinStack ms;
    ms.push(12);
    ms.push(15);
    ms.push(10);
    cout << ms.getMin() << endl;
    ms.pop();
    cout << ms.top() << endl;
    ms.push(10);
    cout << ms.top() << endl;
}