#include <iostream>
#include "./Algorithms/Sorting_Algorithms/Sorting_Algorithms.cpp"
#include "./Lists/Single_LL/UnsortedLL.cpp"
#include "./Heap/heap.cpp"
using namespace std;

int main()
{
    int a[8] = {10, 2, 65, 28, 21, 89, 6, 66};

    heap_sort(a, 8);
    for (int i : a)
    {
        cout << i << " ";
    }

    return 0;
}