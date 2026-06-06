#include <iostream>
#include <queue>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T> *left;
    Node<T> *right;

    Node(T val) : data(val), left(nullptr), right(nullptr) {}
};

template <typename T>
class BT
{
protected:
    Node<T> *root;

public:
    BT(T root_data)
    {
        root = new Node<T>(root_data);
    }

    Node<T> *getRoot() { return root; }

    virtual void insert(T value)
    {
        insertLevelOrder(root, value);
    }

private:
    void insertLevelOrder(Node<T> *node, T value)
    {
        if (node == nullptr)
            return;

        queue<Node<T> *> q;
        q.push(node);

        while (!q.empty())
        {
            Node<T> *curr = q.front();
            q.pop();

            if (curr->left == nullptr)
            {
                curr->left = new Node<T>(value);
                return;
            }
            else
            {
                q.push(curr->left);
            }

            if (curr->right == nullptr)
            {
                curr->right = new Node<T>(value);
                return;
            }
            else
            {
                q.push(curr->right);
            }
        }
    }

public:
    // Traversals
    // Using for Copying
    void Preorder(Node<T> *node)
    {
        if (node == nullptr)
            return;
        cout << node->data << " ";
        Preorder(node->left);
        Preorder(node->right);
    }

    // using in order
    void Inorder(Node<T> *node)
    {
        if (node == nullptr)
            return;
        Inorder(node->left);
        cout << node->data << " ";
        Inorder(node->right);
    }

    // using in deleting
    void Postorder(Node<T> *node)
    {
        if (node == nullptr)
            return;
        Postorder(node->left);
        Postorder(node->right);
        cout << node->data << " ";
    }

    void LevelOrder()
    {
        if (root == nullptr)
            return;

        queue<Node<T> *> q;
        q.push(root);

        while (!q.empty())
        {
            Node<T> *curr = q.front();
            q.pop();
            cout << curr->data << " ";

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }

    void deleteTree(Node<T> *node)
    {
        if (node == nullptr)
            return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

    virtual ~BT()
    {
        deleteTree(root);
        root = nullptr;
    }
};