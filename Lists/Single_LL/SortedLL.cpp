#include "LinkedList.cpp"

class Sorted_LinkedList : public LinkedList
{
public:
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
};