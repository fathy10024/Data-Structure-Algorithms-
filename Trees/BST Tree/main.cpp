#include <iostream>
using namespace std;

template <class T>
class BSTNode
{
private:
    T data;
    BSTNode<T> *right;
    BSTNode<T> *left;

public:
    BSTNode()
    {
        right = left = 0;
    }
    BSTNode(const T &data, BSTNode<T> *right = nullptr, BSTNode<T> *left = nullptr)
    {
        this.data = data;
        this.right = right;
        this.left = left;
    }

    T get_data()
    {
        return data;
    }
    BSTNode<T> *get_right() { return right; }
    BSTNode<T> *get_Left() { return left; }

    void set_Left(BSTNode<T> *l)
    {
        left = l;
    }
    void set_Right(BSTNode<T> *r)
    {
        right = r;
    }
};

template <class T>
class BST
{
protected:
    BSTNode<T> *root;

public:
    void clear()
    {
        root = 0;
    }

    bool Empty()
    {
        return root == 0;
    }

    T *search(T &el)
    {
        BSTNode<T> *p = root;
        while (p != 0)
        {
            if (el == p->get_data())
            {
                return p;
            }
            else if (el < p->get_data())
            {
                p = p->get_Left();
            }
            else
            {
                p = p->get_right();
            }
        }
    }

    // insertion
private:
    BSTNode<T> *insertNode(BSTNode<T> node, const T &value)
    {
        if (node == nullptr)
        {
            return new BSTNode<T>(value);
        }

        if (value < node->data)
        {
            node->left = insertRec(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = insertRec(node->right, value);
        }
        //
        return node;
    }

public:
    // Delete
};

int main()
{

    cout << "Au Haga" << endl;

    return 0;
}