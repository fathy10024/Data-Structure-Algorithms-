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

// Insert at beginning
void LinkedList::push_front(int val)
{
    Node *newNode = new Node{val, head};
    head = newNode;

    // check if the list is empty
    if (tail == NULL)
        tail = newNode;

    count++;
}

// Insert at end
void LinkedList::push_back(int val)
{
    Node *newNode = new Node{val, NULL};

    if (head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }

    count++;
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

    Node *current = head;
    Node *prev = NULL;

    // لو أول عنصر
    if (head->data == val)
    {
        Node *temp = head;
        head = head->next;
        delete temp;

        if (head == NULL)
            tail = NULL;

        count--;
        return;
    }

    while (current != NULL && current->data != val)
    {
        prev = current;
        current = current->next;
    }

    if (current != NULL)
    {
        prev->next = current->next;

        if (current == tail)
            tail = prev;

        delete current;
        count--;
    }
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
