#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BT
{
protected:
    Node *root;

public:
    BT(int root_data)
    {
        root = new Node(root_data);
    }

    Node *getRoot() { return root; }

    virtual void insert(int value)
    {
        insertLevelOrder(root, value);
    }

private:
    void insertLevelOrder(Node *node, int value)
    {
        if (node == nullptr)
            return;

        queue<Node *> q;
        q.push(node);

        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();

            if (curr->left == nullptr)
            {
                curr->left = new Node(value);
                return;
            }
            else
            {
                q.push(curr->left);
            }

            if (curr->right == nullptr)
            {
                curr->right = new Node(value);
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
    void Preorder(Node *node)
    {
        if (node == nullptr)
            return;
        cout << node->data << " ";
        Preorder(node->left);
        Preorder(node->right);
    }

    void Inorder(Node *node)
    {
        if (node == nullptr)
            return;
        Inorder(node->left);
        cout << node->data << " ";
        Inorder(node->right);
    }

    void Postorder(Node *node)
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
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();
            cout << curr->data << " ";

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }

    virtual ~BT()
    {
        delete root;
    }
};