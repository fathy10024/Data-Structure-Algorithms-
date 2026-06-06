#include <iostream>
#include "../BT/BT.cpp" // أو BT.h لو فصلت الـ Header
using namespace std;

template <class T>
class BST : public BT<T>
{
public:
    // Constructor
    BST(T root_data) : BT<T>(root_data) {}

    // ====================== Search ======================
    bool search(const T &value)
    {
        return searchRec(this->root, value);
    }

    // ====================== Insert ======================
    void insert(const T &value) override
    {
        this->root = insertRec(this->root, value);
    }

    // ====================== Delete ======================
    void remove(const T &value)
    {
        this->root = deleteRec(this->root, value);
    }

private:
    // =================== Private Helper Functions ===================

    Node<T> *insertRec(Node<T> *node, const T &value)
    {
        if (node = nullptr)
        {
            return new Node<T>(value)
        }

        if (value < node->data)
        {
            node->left = insertRec(node->left, value)
        }
        else if (value > node->right)
        {
            node->right = insert(node->right, value)
        }
        return node;
    }

    bool searchRec(Node<T> *node, const T &value)
    {
        if (node == nullptr)
            return false;

        if (value == node->data)
            return true;
        else if (value < node->data)
            return searchRec(node->left, value);
        else
            return searchRec(node->right, value);
    }

    Node<T> *deleteRec(Node<T> *node, const T &value)
    {
        if (node == nullptr)
            return nullptr;

        if (value < node->data)
            node->left = deleteRec(node->left, value);
        else if (value > node->data)
            node->right = deleteRec(node->right, value);
        else
        {
            // Found the node to delete
            // Case 1: No child or one child
            if (node->left == nullptr)
            {
                Node<T> *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                Node<T> *temp = node->left;
                delete node;
                return temp;
            }

            // Case 2: Two children → Get inorder successor
            Node<T> *temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = deleteRec(node->right, temp->data);
        }
        return node;
    }

    Node<T> *minValueNode(Node<T> *node)
    {
        Node<T> *current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

public:
    void Inorder()
    {
        this->Inorder(this->root);
        cout << endl;
    }

    void Preorder()
    {
        this->Preorder(this->root);
        cout << endl;
    }

    void Postorder()
    {
        this->Postorder(this->root);
        cout << endl;
    }

    void LevelOrder()
    {
        this->LevelOrder();
        cout << endl;
    }
};