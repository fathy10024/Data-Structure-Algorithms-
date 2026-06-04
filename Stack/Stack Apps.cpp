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

// app 2 (Add tow big integer)
string sum(string str1, string str2)
{
    stack<int> s1, s2;
    stack<char> s3;

    for (char x : str1)
        s1.push(x - '0');

    for (char x : str2)
        s2.push(x - '0');

    string ans = "";
    int carry = 0;

    while (!s1.empty() || !s2.empty() || carry)
    {
        int d1 = 0;
        int d2 = 0;

        if (!s1.empty())
        {
            d1 = s1.top();
            s1.pop();
        }

        if (!s2.empty())
        {
            d2 = s2.top();
            s2.pop();
        }

        int total = d1 + d2 + carry;

        s3.push((total % 10) + '0');
        carry = total / 10;
    }

    while (!s3.empty())
    {
        ans += s3.top();
        s3.pop();
    }

    return ans;
}