#include "LinkedList.cpp"

class Sorted_LinkedList : public LinkedList
{
public:
    // default constructor
    Sorted_LinkedList() : LinkedList() {};

    void insert(int val)
    {
        Node *newNode = new Node{val, NULL};

        if (head == NULL || head->data > val)
        {
            newNode->next = head;
            head = newNode;

            if (tail == NULL)
                tail = newNode;

            count++;
            return;
        }

        Node *current = head;
        while (current->next != NULL && current->next->data < val)
            current = current->next;

        newNode->next = current->next;
        current->next = newNode;

        if (newNode->next == NULL)
            tail = newNode;

        count++;
    }

    // copy constructor
    Sorted_LinkedList(const Sorted_LinkedList &SL)
    {
        head = NULL;
        tail = NULL;
        count = 0;

        Node *current = SL.head;
        while (current != NULL)
        {
            insert(current->data);
            current = current->next;
        }
    }
};