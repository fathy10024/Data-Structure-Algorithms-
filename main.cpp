#include <iostream>
#include "./Algorithms/Sorting_Algorithms/Sorting_Algorithms.cpp"
#include "./Lists/Single_LL/SortedLL.cpp"
using namespace std;

int main()
{

    Sorted_LinkedList ls;
    ls.insert(5);
    ls.insert(8);
    ls.insert(2);
    ls.insert(3);

    ls.remove(3);
    ls.print();
    return 0;
}