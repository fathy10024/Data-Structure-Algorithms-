#include "LinkedList.cpp"

class UnSorted_LinkedList : public LinkedList
{
public:
    // Insert at beginning
    void push_front(int val)
    {
        Node *newNode = new Node{val, head};
        head = newNode;

        // check if the list is empty
        if (tail == NULL)
            tail = newNode;

        count++;
    }

    // Insert at end
    void push_back(int val)
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
};