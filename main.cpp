#include <iostream>
#include "./Algorithms/Sorting_Algorithms/Sorting_Algorithms.cpp"
#include "./Stack/Stack Apps.cpp"
#include "./Stack/LLStack.cpp"
using namespace std;

int main()
{
    LLStack ls;
    ls.push(5);
    ls.push(8);
    ls.push(15);

    while (!ls.isEmpty())
    {
        cout << ls.top() << endl;
        ls.pop();
    }

    return 0;
}