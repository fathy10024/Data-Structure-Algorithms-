#include <iostream>
#include "./Algorithms/Sorting_Algorithms/Sorting_Algorithms.cpp"
using namespace std;

int main()
{

    int *ptr = new int[7]{1, 2, 3, 4, 5, 6, 7};
    int *temp = ptr;
    cout << ptr[0] << endl;
    delete[] temp;
    cout << ptr[2] << endl;
    return 0;
}