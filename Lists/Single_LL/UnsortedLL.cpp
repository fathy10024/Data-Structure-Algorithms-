#include "LinkedList.cpp"

class UnSorted_LinkedList : public LinkedList
{
private:
    void insert(int val) override
    {
    }

public:
    UnSorted_LinkedList() : LinkedList() {}

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

    // copy constructor
    UnSorted_LinkedList(const UnSorted_LinkedList &USL)
    {
        head = NULL;
        tail = NULL;
        count = 0;

        Node *current = USL.head;
        while (current != NULL)
        {
            push_back(current->data);
            current = current->next;
        }
    }
};