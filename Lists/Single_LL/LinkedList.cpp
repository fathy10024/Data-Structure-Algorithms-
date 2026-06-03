#include "linkedList.h"

// Constructor
LinkedList::LinkedList()
{
    head = NULL;
    tail = NULL;
    count = 0;
}

// Destructor
LinkedList::~LinkedList()
{
    clear();
}

// Check if empty
bool LinkedList::isEmpty() const
{
    return head == NULL;
}

// Length
int LinkedList::length() const
{
    return count;
}

// Print
void LinkedList::print() const
{
    Node *current = head;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Search
bool LinkedList::search(int val) const
{
    Node *current = head;

    while (current != NULL)
    {
        if (current->data == val)
            return true;
        current = current->next;
    }

    return false;
}

// Delete node
void LinkedList::deleteNode(int val)
{
    if (head == NULL)
        return;

    // IF AT FIRST
    if (head->data == val)
    {
        Node *temp = head;
        head = head->next;

        if (head == NULL)
            tail = NULL;

        delete temp;
        count--;
        return;
    }

    Node *current = head;
    Node *prev = NULL;

    while (current != NULL && current->data != val)
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
        return;

    prev->next = current->next;

    if (current == tail)
        tail = prev;

    delete current;
    count--;
}

// Front
int LinkedList::front() const
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return -1;
    }
    return head->data;
}

// Back
int LinkedList::back() const
{
    if (tail == NULL)
    {
        cout << "List is empty!" << endl;
        return -1;
    }
    return tail->data;
}

void LinkedList::clear()
{
    Node *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }

    tail = NULL;
    count = 0;
}
