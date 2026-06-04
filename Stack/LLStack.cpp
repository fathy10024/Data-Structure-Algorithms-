#include <iostream>
#include "../Lists/Single_LL/UnsortedLL.cpp"

class LLStack
{
private:
    UnSorted_LinkedList LS;

public:
    void clear()
    {
        LS.clear();
    }
    void push(int val)
    {
        LS.push_back(val);
    }
    void pop()
    {
        LS.pop_back();
    }

    int top()
    {
        return LS.back();
    }
    bool isEmpty()
    {
        return LS.isEmpty();
    }
};