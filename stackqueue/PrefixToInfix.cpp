#include <iostream>
#include <string>
#include <cctype>
#include <stack>
using namespace std;

string prefixToInfix(string str)
{
    stack<string> st;

    for (int i = str.length() - 1; i >= 0; i--)
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

            string temp = "(" + top1 + string(1, c) + top2 + ")";
            st.push(temp);
        }
    }

    return st.top();
}

int main()
{
    string str = "*+cd-ab";
    cout << prefixToInfix(str) << endl;

    str = "*+ABC";
    cout << prefixToInfix(str) << endl;

    str = "^A^BC";
    cout << prefixToInfix(str) << endl;

    str = "/*+AB+CDE";
    cout << prefixToInfix(str) << endl;

    return 0;
}