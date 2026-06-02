#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *RChild;
    Node *LChild;
};

Node *creat_Node(int data)
{
    Node *node = new Node();
    node->data = data;
    node->LChild = nullptr;
    node->RChild = nullptr;
    return node;
}

// Tree traversal algorithms (BFS and DFS - Preorder, Inorder, Postorder)

// DFS - Preorder (data , left ,right)
void Preorder(Node *root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    Preorder(root->LChild);
    Preorder(root->RChild);
}

// Inorder (left , data , right)
void Inorder(Node *root)
{
    if (root == nullptr)
        return;
    Inorder(root->LChild);
    cout << root->data << " ";
    Inorder(root->RChild);
}

// Postorder (left , right , data)
void Postorder(Node *root)
{
    if (root == nullptr)
        return;
    Postorder(root->LChild);
    Postorder(root->RChild);
    cout << root->data << " ";
}

// BFS ==> Levels
void BFS(Node *root)
{
    if (root == nullptr)
        return;

    queue<Node *> q;
    q.push(root);
    int level = 0;
    while (!q.empty())
    {
        int levelSize = q.size();
        cout << "Level " << level << " : " << endl;
        for (int i = 0; i < levelSize; i++)
        {

            Node *current = q.front();
            cout << current->data << " ";

            q.pop();

            if (current->LChild != nullptr)
            {
                q.push(current->LChild);
            }
            if (current->RChild != nullptr)
            {
                q.push(current->RChild);
            }
        }
        level++;
        cout << endl;
    }
}

int main()
{
    Node *Root = creat_Node(4);
    Root->LChild = creat_Node(2);
    Root->RChild = creat_Node(5);

    Root->LChild->LChild = creat_Node(1);

    Preorder(Root);
    cout << endl;
    Inorder(Root);
    cout << endl;
    Postorder(Root);
    cout << endl;
    BFS(Root);

    return 0;
}