#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{

    LinkedList *l = new LinkedList();

    l->push_back(5);
    l->push_back(6);
    l->push_back(7);
    l->push_back(8);
    l->push_front(4);

    int first = l->front();

    cout << first << endl;

    return 0;
}