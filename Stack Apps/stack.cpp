#include <iostream>
#include <stack>
using namespace std;
// Bracket delimiters checking

bool delimiters(string str)
{
    stack<char> st;
    for (char x : str)
    {
        if (x == '(' || x == '[' || x == '{' || x == '<')
        {
            st.push(x);
        }
        else if (x == ')' || x == ']' || x == '}' || x == '>')
        {
            st.pop();
        }
        else if (x != '(' || x != '[' || x != '{' || x != '<')
        {
            return 0;
        }
    }
    return st.empty();
}