#include <iostream>
#include "./Sorting_Algorithms/Sorting_Algorithms.cpp"
using namespace std;

int main()
{

    int arr[] = {5, 3, 9, 6, 8, 7, 2, 5};

    Insertion_Sort(arr, 8);
    for (int x : arr)
    {
        cout << x << " ";
    }
    return 0;
}