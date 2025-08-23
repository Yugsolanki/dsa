#include <iostream>
#include <string>
#include <cctype>
#include <stack>
using namespace std;

string postfixToInfix(string str)
{
    stack<string> st;

    for (int i = 0; i < str.length(); i++)
    {
        char c = str[i];

        if (isalpha(c))
            st.push(string(1, c));

        else
        {
            string top1 = st.top();
            st.pop();
            string top2 = st.top();
            st.pop();

            string temp = '(' + top2 + c + top1 + ')';
            st.push(temp);
        }
    }

    return st.top();
}

int main()
{
    string str = "ab-de+f*/";
    cout << postfixToInfix(str) << endl;

    str = "AB+C*DE--FG+^";
    cout << postfixToInfix(str) << endl;

    str = "ABC*DEF^/G*-H*+";
    cout << postfixToInfix(str) << endl;

    str = "abc^^d*e+";
    cout << postfixToInfix(str) << endl;

    return 0;
}