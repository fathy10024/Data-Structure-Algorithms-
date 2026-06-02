#include <iostream>
#include <stack>

using namespace std;

int main()
{
    string postfix;

    cout << "Enter Postfix Expression : ";
    cin >> postfix;

    stack<int> st;

    for (int i = 0; i < postfix.length(); i++)
    {
        char ch = postfix[i];

        // لو رقم
        if (isdigit(ch))
        {
            st.push(ch - '0');
        }

        // لو operator
        else
        {
            int b = st.top();
            st.pop();

            int a = st.top();
            st.pop();

            int result;

            switch (ch)
            {
                case '+':
                    result = a + b;
                    break;

                case '-':
                    result = a - b;
                    break;

                case '*':
                    result = a * b;
                    break;

                case '/':
                    result = a / b;
                    break;
            }

            st.push(result);
        }
    }

    cout << "Result = " << st.top();

    return 0;
}