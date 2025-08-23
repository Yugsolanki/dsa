#include <iostream>
#include <string>
#include <cctype>
#include <stack>
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

string infixToPostfix(string str)
{
    stack<char> st;
    string ans;

    for (int i = 0; i < str.length(); i++)
    {
        char c = str[i];

        // if alphabet push to ans
        if (isalpha(c))
        {
            ans += c;
        }
        // if opening bracked
        else if (c == '(')
        {
            st.push(c);
        }
        // if closing bracket discovered then pop until opening bracket
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
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        {
            /*
            ^ operator is basically right associative.
            Left associativity: performed from left to right (e.g., a - b - c is interpreted as (a - b) - c)
            Right associativity: Operations are performed from right to left (e.g., a^b^c is interpreted as a^(b^c))
            It creates difficulty when working with two ^^;
            When first one is pushed into stack ^.
            Then second one arrives we don't pop the first one.
            this results in abc^^ which means a^(b^c) and not ab^c^
            So we are simply skipping when we see that
            */
            if (c != '^')
            {
                while (!st.empty() && st.top() != '(' && priority(c) <= priority(st.top()))
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

    return ans;
}

int main()
{
    string str = "a^b^c";
    cout << infixToPostfix(str) << endl;

    str = "A + (B * C - (D / E ^ F) * G) * H";
    cout << infixToPostfix(str) << endl; // ABC*DEF^/G*-H*+

    str = "((A + B) * C - (D - E)) ^ (F + G)";
    cout << infixToPostfix(str) << endl; // AB+C*DE--FG+^

    str = "a^b^c*d+e";
    cout << infixToPostfix(str) << endl; // AB+C*DE--FG+^

    return 0;
}