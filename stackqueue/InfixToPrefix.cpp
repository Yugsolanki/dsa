#include <iostream>
#include <string>
#include <cctype>
#include <stack>
#include <algorithm>
using namespace std;

int priority(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        cout << "Wrong character passed" << endl;
        return -1;
    }
}

string infixToPrefix(string str)
{
    // Step 1: Reverse the string
    reverse(str.begin(), str.end());

    // Step 2: Swap `(` with `)`
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
            str[i] = ')';
        else if (str[i] == ')')
            str[i] = '(';
    }

    // Step 3: Generate a postfix of it
    stack<char> st;
    string ans = "";

    for (int i = 0; i < str.length(); i++)
    {
        char c = str[i];

        if (isalpha(c))
            ans += c;

        else if (c == '(')
            st.push(c);

        // If closing brakced found pop from stack and push to ans until opening bracked is discovered in stack
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop(); // Remove the '('
        }

        // If operator
        else
        {
            if (c == '^')
            {
                while (!st.empty() && st.top() != '(' && priority(c) <= priority(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
            }
            else
            {
                while (!st.empty() && st.top() != '(' && priority(c) < priority(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    // Step 4: Reverse the ans now
    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    string str = "a+b";
    cout << infixToPrefix(str) << endl; //+ab

    str = "(A+B)*C";
    cout << infixToPrefix(str) << endl; /* *+ABC */

    str = "A^B^C";
    cout << infixToPrefix(str) << endl; //^A^BC

    str = "(A+B)*(C+D)/E";
    cout << infixToPrefix(str) << endl; /* /*+AB+CDE */

    return 0;
}