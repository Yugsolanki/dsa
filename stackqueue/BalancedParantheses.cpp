#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool balancedParantheses(string str)
{
    stack<char> st;
    int n = str.length();

    st.push(str[0]);

    for (int i = 1; i < n; i++)
    {

        if (str[i] == ')' && st.top() == '(' || str[i] == '}' && st.top() == '{' || str[i] == ']' && st.top() == '[')
        {
            st.pop();
        }
        else
        {
            st.push(str[i]);
        }
    }

    return st.empty();
}

int main()
{
    string str = "(){}";
    cout << balancedParantheses(str) << endl;

    str = "(){}[{()}]";
    cout << balancedParantheses(str) << endl;

    str = "(){[}";
    cout << balancedParantheses(str) << endl;

    str = "(){{({[})}}";
    cout << balancedParantheses(str) << endl;
    return 0;
}