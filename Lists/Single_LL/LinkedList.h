#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
protected:
    Node *head;
    Node *tail;
    int count;

public:
    // Constructor
    LinkedList();

    // Destructor
    ~LinkedList();

    virtual void insert(int val) = 0;
    // Basic operations
    bool isEmpty() const;
    int length() const;

    void print() const;

    // void push_front(int val);
    // void push_back(int val);

    bool search(int val) const;
    void deleteNode(int val);

    int front() const;
    int back() const;

    void clear();
    // void remove(int val);
};

#endif