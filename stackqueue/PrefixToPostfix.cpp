#include <iostream>
#include <string>
#include <cctype>
#include <stack>
using namespace std;

string prefixToPostfix(string str)
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

            string temp = top1 + top2 + string(1, c);
            st.push(temp);
        }
    }

    return st.top();
}

int main()
{
    string str = "*+cd-ab";
    cout << prefixToPostfix(str) << endl;

    str = "*+ABC";
    cout << prefixToPostfix(str) << endl;

    str = "^A^BC";
    cout << prefixToPostfix(str) << endl;

    str = "/*+AB+CDE";
    cout << prefixToPostfix(str) << endl;

    return 0;
}